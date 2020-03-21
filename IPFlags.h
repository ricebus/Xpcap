//
// Created by George on 14-Mar-20.
//

#ifndef XPCAP_IPFLAGS_H
#define XPCAP_IPFLAGS_H

#include <cstdint>

enum class IPFlags : uint8_t
{
    DontFragment = 2,
    MoreFragments = 1
};


//inline IPFlags operator|(IPFlags a, IPFlags b)
//{
//    return static_cast<IPFlags>(static_cast<int>(a) | static_cast<int>(b));
//}

#endif //XPCAP_IPFLAGS_H
