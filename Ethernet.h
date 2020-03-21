//
// Created by George on 13-Mar-20.
//

#ifndef XPCAP_ETHERNET_H
#define XPCAP_ETHERNET_H

#include "MACAddress.h"
#include "EthernetType.h"
#include "Packet.h"
#include "InternetProtocol.h"

class Ethernet : public LinkProtocol
{
private:
    MACAddress* _srcAddr;
    MACAddress* _dstAddr;
    EthernetType _etherType;

    Ethernet();

public:
    Ethernet(const uint8_t* bytes, size_t size);
    [[nodiscard]] std::string ToString() const override;
    friend std::ostream& operator<<(std::ostream& os, const Ethernet& obj);
    constexpr static uint32_t HeaderSize() { return 14; }
    EthernetType GetEthernetType();
    const MACAddress* GetSrcAddr();
    const MACAddress* GetDstAddr();
    ~Ethernet() override;
};

#endif //XPCAP_ETHERNET_H
