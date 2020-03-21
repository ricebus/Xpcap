//
// Created by George on 13-Mar-20.
//

#include "IPAddress.h"
#include <stdexcept>

IPAddress::IPAddress()
{
    std::memset((void*)_octets, 0, 4);
}

IPAddress::IPAddress(const uint8_t* octets, size_t size)
{
	if(size != 4)
		throw std::length_error("IPAddress(): size should be 4 bytes.");

    std::memcpy(_octets, octets, 4);
}


IPAddress::IPAddress(const std::string& ipString) : IPAddress(ipString.c_str())
{
}

IPAddress::IPAddress(const char* ipString)
{
	std::sscanf(ipString, "%c.%c.%c.%c", _octets, _octets + 1, _octets + 2, _octets + 3);
}

std::string IPAddress::ToString() const
{
    std::string out;
    char *buf = new char[16];

    std::snprintf(buf,16,"%d.%d.%d.%d",
                  _octets[0], _octets[1], _octets[2], _octets[3]);
    out = buf;
    return out;
}

bool IPAddress::operator==(const IPAddress& other)
{
    bool eq = std::memcmp(_octets, other._octets, 4);
    return eq == 0;
}

bool IPAddress::operator!=(const IPAddress& other)
{
    return !(*this == other);
}

std::ostream& operator<<(std::ostream& os,  IPAddress& obj)
{
    os << obj.ToString();
    return os;
}