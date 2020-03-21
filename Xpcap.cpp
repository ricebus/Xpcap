//
// Created by George on 19-Mar-20.
//

#include "Xpcap.h"
#include "Ethernet.h"
#include "IPv4.h"
#include "TCP.h"
#include "UDP.h"
#include <istream>
#include <iostream>
#include <cstring>
#include "LinkProtocol.h"

Xpcap::Xpcap(std::string &filename, std::size_t bufferSize)
{
    _filename = filename;
    _fileSize = 0;
    _buffer = nullptr;
    _bufferSize = bufferSize;
    _actualBufferSize = 0;
}

bool Xpcap::Parse()
{
    if (_actualBufferSize == 0)
        if(this->Read() <= 24) // Pcap Global Header Size
            return false;

    //std::cout << "Read " << read_size << " bytes out of " << file_size << " bytes" << std::endl;
    uint32_t linkLayerType;
    std::memcpy(&linkLayerType, _buffer + 20, 4);

    unsigned int ptr = 24;
//    int i = 1;

    uint8_t *bytes = _buffer + ptr;
    size_t size = _actualBufferSize - ptr;
    size_t minHeaderSize = Ethernet::HeaderSize() + PcapHeader::HeaderSize();

    while (size > minHeaderSize)
    {
        auto packet = new Packet(bytes, size);
        // Ethernet
        if (linkLayerType == 1)
        {
          	auto ethernet = new Ethernet(bytes + PcapHeader::HeaderSize(),
                                              size - PcapHeader::HeaderSize());

            if (ethernet->GetEthernetType() == EthernetType::IPv4)
			{
            	auto ip = new IPv4(bytes + PcapHeader::HeaderSize() + Ethernet::HeaderSize(),
                                    size - PcapHeader::HeaderSize() - Ethernet::HeaderSize());

                IPProtocol ipProtocol = ip->GetIPProtocol();
                ethernet->SetPayload((InternetProtocol **) (&ip));


                if (ipProtocol == IPProtocol::TCP)
                {
                    TCP *tcp = new TCP(bytes + PcapHeader::HeaderSize() + Ethernet::HeaderSize() +
                                               IPv4::HeaderSize(),
                                       size - PcapHeader::HeaderSize() - Ethernet::HeaderSize() -
                                               IPv4::HeaderSize());
                    ip->SetPayload((TransportProtocol **) (&tcp));
                }
                else if (ipProtocol == IPProtocol::UDP)
                {
                    UDP *udp = new UDP(bytes + PcapHeader::HeaderSize() + Ethernet::HeaderSize() +
                                               IPv4::HeaderSize(),
                                       size - PcapHeader::HeaderSize() - Ethernet::HeaderSize() -
                                               IPv4::HeaderSize());
                    ip->SetPayload((TransportProtocol **) (&udp));
                }
            }

            auto linkProtocol = dynamic_cast<LinkProtocol*>(ethernet);
            packet->SetPayload(&linkProtocol);
            _packetList.push_front(packet);
        }

        ptr += packet->GetPcapHeader()->SavedPacketLength() + PcapHeader::HeaderSize();
        bytes = _buffer + ptr;
        size = _actualBufferSize - ptr;
    }

    this->Close();
    return true;
}

size_t Xpcap::Read()
{
    if(!this->Open())
        return -1;

    _bufferSize = (_bufferSize != 0) ? _bufferSize : this->PcapSize();

    _buffer = new uint8_t[_bufferSize];
    _fileStream.read(reinterpret_cast<char *>(_buffer), _bufferSize);
    _actualBufferSize = _fileStream.gcount();
    return _actualBufferSize;
}

Xpcap::~Xpcap()
{
    delete (_buffer);
}

size_t Xpcap::PcapSize()
{
    if (_fileSize == 0)
        if (this->Open())
            _fileSize = _fileStream.tellg();

    return _fileSize;
}

bool Xpcap::Open()
{
    _fileStream.open(_filename, std::ios::in | std::ios::binary | std::ios::ate);
    bool res = _fileStream.is_open();
    _fileSize = _fileStream.tellg();
    _fileStream.seekg(0, std::ios::beg);
    return res;
}

void Xpcap::Close()
{
    _fileStream.close();
}

const std::list<Packet *> *Xpcap::GetPacketList()
{
    return &_packetList;
}
