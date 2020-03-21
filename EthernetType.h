//
// Created by George on 13-Mar-20.
//

#ifndef XPCAP_ETHERNETTYPE_H
#define XPCAP_ETHERNETTYPE_H

#include <cstdint>

enum class EthernetType : uint16_t
{
    IPv4 = 0x0800,
    ARP = 0x0806,
    IPv6 = 0x86DD,
};

#endif //XPCAP_ETHERNETTYPE_H
