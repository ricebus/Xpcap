//
// Created by George on 14-Mar-20.
//

#ifndef XPCAP_PACKET_H
#define XPCAP_PACKET_H

#include "PcapHeader.h"
#include "LinkProtocol.h"

class Packet {
private:
    PcapHeader* _pcapHeader;
    LinkProtocol* _payload;

public:
    Packet(const uint8_t *bytes, size_t size);
    ~Packet();
	void SetPayload(LinkProtocol** linkProtocol);
	LinkProtocol* GetPayload();
	const PcapHeader* GetPcapHeader();
};


#endif //XPCAP_PACKET_H
