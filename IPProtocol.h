//
// Created by George on 13-Mar-20.
//

#ifndef XPCAP_IPPROTOCOL_H
#define XPCAP_IPPROTOCOL_H

#include <cstdint>

enum class IPProtocol : uint8_t
{
    ICMP = 0x01,
    IGMP = 0x02,
    TCP = 0x06,
    UDP = 0x11,
};

#endif //XPCAP_IPPROTOCOL_H
