//
// Created by George on 16-Mar-20.
//

#ifndef XPCAP_TCPFLAGS_H
#define XPCAP_TCPFLAGS_H

#include <cstdint>

enum class TCPFlags : uint16_t
{
    FIN = 1,
    SYN = 2,
    RST = 4,
    PSH = 8,
    ACK = 16,
    URG = 32,
    ECE = 64,
    CWR = 128,
    NS = 256
};

#endif //XPCAP_TCPFLAGS_H
