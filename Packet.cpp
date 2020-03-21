//
// Created by George on 14-Mar-20.
//

#include <cstring>
#include <stdexcept>
#include "Packet.h"

Packet::Packet(const uint8_t *bytes, size_t size)
{
    if(size < PcapHeader::HeaderSize())
        throw std::length_error("Packet(): byte-array too small");

    _pcapHeader = new PcapHeader(bytes, size);
    _payload = nullptr;
}

Packet::~Packet()
{
    delete(_pcapHeader);
    delete(_payload);
}

void Packet::SetPayload(LinkProtocol **linkProtocol) {
	_payload = *linkProtocol;
}

LinkProtocol *Packet::GetPayload() {
	return _payload;
}

const PcapHeader *Packet::GetPcapHeader()
{
	return _pcapHeader;
}
