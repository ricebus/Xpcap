cmake_minimum_required(VERSION 3.15)
project(Xpcap)

set(CMAKE_CXX_STANDARD 20)

add_library(Xpcap MACAddress.cpp MACAddress.h Ethernet.cpp Ethernet.h TCP.cpp TCP.h UDP.cpp UDP.h IPv4.cpp IPv4.h IPAddress.cpp IPAddress.h IPProtocol.h EthernetType.h PcapHeader.cpp PcapHeader.h Packet.cpp Packet.h IPFlags.h TCPFlags.h LinkProtocol.h InternetProtocol.h TransportProtocol.h ApplicationProtocol.h TransportProtocol.cpp LinkProtocol.cpp InternetProtocol.cpp Xpcap.cpp Xpcap.h LinkProtocolType.h)