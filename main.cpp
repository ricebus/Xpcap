#include <iostream>
#include "MACAddress.h"
#include "Ethernet.h"
#include "PcapHeader.h"
#include "IPv4.h"
#include "UDP.h"
#include "TCP.h"
#include "TransportProtocol.h"
#include "LinkProtocol.h"
#include "InternetProtocol.h"
#include "Xpcap.h"
//using namespace std;
#include <sstream>

//class A
//{
//protected:
//    int _a;
//public:
//    A(int a) { _a = a;}
//};
//
//class B : public A
//{
//    int _b;
//    //B() { _b = _a; }
//public:
//    //B(A a) : A(a._a) {}
//    void Print() { std::cout << "YEY" << _a;}
//};

int main()
{
//    A *a = new A(4);
//    dynamic_cast<B*>(a).Print();

//    std::ifstream file;
//    file.open("test.pcap", std::ios::in | std::ios::binary | std::ios::ate);
//    int buffer_size = 1e6;
//
//    if (file.is_open())
//    {
//        int file_size = file.tellg();
//        file.seekg(0, std::ios::beg);
//        uint8_t *buffer = new uint8_t[buffer_size];
//        file.read(reinterpret_cast<char *>(buffer), buffer_size);
//        int read_size = file.gcount();
//        std::cout << "Read " << read_size << " bytes out of " << file_size << " bytes" << std::endl;
//
//        bool run = true;
//        int ptr = 24;
//        int i = 1;
//        uint8_t *bytes = buffer + ptr;
//        size_t size = read_size - ptr;
//
//        while (size > PcapHeader::HeaderSize() + Ethernet::HeaderSize())
//        {
//
//            uint32_t linkLayerType;
//            std::memcpy(&linkLayerType, buffer + 20, 4);
//
//            PcapHeader pcap(bytes, size);
//            // Ethernet
//            if (linkLayerType == 1)
//            {
//                Ethernet *ethernet = new Ethernet(bytes + PcapHeader::HeaderSize(),
//                                                  size - PcapHeader::HeaderSize());
//
//                if (ethernet->GetEthernetType() == EthernetType::IPv4)
//                {
//                    IPv4 *ip = new IPv4(bytes + PcapHeader::HeaderSize() + Ethernet::HeaderSize(),
//                                        size - PcapHeader::HeaderSize() - Ethernet::HeaderSize());
//
//                    const IPProtocol *ipProtocol = ip->GetIPProtocol();
//                    ethernet->SetPayload((InternetProtocol **) (&ip));
//
//
//                    if (*ipProtocol == IPProtocol::TCP)
//                    {
//                        TCP *tcp = new TCP(bytes + PcapHeader::HeaderSize() + Ethernet::HeaderSize() +
//                                           IPv4::HeaderSize(),
//                                           size - PcapHeader::HeaderSize() - Ethernet::HeaderSize() -
//                                           IPv4::HeaderSize());
//                        ip->SetPayload((TransportProtocol **) (&tcp));
//                    }
//                    else if (*ipProtocol == IPProtocol::UDP)
//                    {
//                        UDP *udp = new UDP(bytes + PcapHeader::HeaderSize() + Ethernet::HeaderSize() +
//                                           IPv4::HeaderSize(),
//                                           size - PcapHeader::HeaderSize() - Ethernet::HeaderSize() -
//                                           IPv4::HeaderSize());
//                        ip->SetPayload((TransportProtocol **) (&udp));
//                    }
//                }
//
//                std::cout << "#" << i++ << std::endl;
//                std::cout << ethernet->ToString() << std::endl;
//                if(ethernet->GetEthernetType() == EthernetType::IPv4)
//                    std::cout << dynamic_cast<IPv4 *>(ethernet->GetPayload())->ToString() << std::endl;
//            }
//
//
//            ptr += pcap.SavedPacketLength() + PcapHeader::HeaderSize();
//            bytes = buffer + ptr;
//            size = read_size - ptr;
//
//            if (ptr > file.gcount())
//                run = false;
//
//            if (i == 100)
//                break;
//        }
//
//
//    }
//    file.close();

    std::string filename = "test.pcap";
    Xpcap pcap(filename,1e6);
    pcap.Parse();
    const std::list<Packet*>* list = pcap.GetPacketList();
    for(auto itr=list->begin(); itr!=list->end(); itr++)
    {
        Packet* packet = *itr;
        //Ethernet* ethernet = dynamic_cast<Ethernet*>(packet->GetPayload());
//        std::cout << "#" << i++ << std::endl;
        //std::cout << ethernet->ToString() << std::endl;
        std::cout << packet->GetPayload()->ToString() << std::endl;
//        if(ethernet->GetEthernetType() == EthernetType::IPv4)
//            std::cout << dynamic_cast<IPv4 *>(ethernet->GetPayload())->ToString() << std::endl;
    }

    return 0;
}
