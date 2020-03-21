//
// Created by George on 16-Mar-20.
//

#ifndef XPCAP_TCPFLAGS_H
#define XPCAP_TCPFLAGS_H

#include <cstdint>
#include <type_traits>

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


inline TCPFlags operator|(TCPFlags lhs, TCPFlags rhs)
{
	return static_cast<TCPFlags> (
			static_cast<std::underlying_type<TCPFlags>::type>(lhs) |
			static_cast<std::underlying_type<TCPFlags>::type>(rhs)
	);
}

inline TCPFlags operator&(TCPFlags lhs, TCPFlags rhs)
{
	return static_cast<TCPFlags> (
			static_cast<std::underlying_type<TCPFlags>::type>(lhs) &
			static_cast<std::underlying_type<TCPFlags>::type>(rhs)
	);
}

#endif //XPCAP_TCPFLAGS_H
