//
// Created by George on 21-Mar-20.
//

#ifndef XPCAP_LINKPROTOCOLTYPE_H
#define XPCAP_LINKPROTOCOLTYPE_H

#include <cstdint>

enum class LinkProtocolType : uint32_t
{
	Null = 0,
	Ethernet = 1,
	IEEE802_11 = 105,
	IPv4 = 228
};

#endif //XPCAP_LINKPROTOCOLTYPE_H
