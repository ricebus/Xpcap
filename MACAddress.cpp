//
// Created by George on 13-Mar-20.
//

#include <ios>
#include "MACAddress.h"

MACAddress::MACAddress()
{
    std::memset((void*)_octets, 0, 6);
}

MACAddress::MACAddress(const uint8_t* octets, size_t size)
{
	if(size != 6)
		throw std::length_error("MACAddress(): size should be 6 bytes.");

    std::memcpy(_octets, octets, 6);
}

MACAddress::MACAddress(const std::string& macString) : MACAddress(macString.c_str())
{
}

MACAddress::MACAddress(const char* macString)
{
	std::sscanf(macString, "%u:%u:%u:%u:%u:%u", _octets, _octets + 1, _octets + 2, _octets + 3, _octets + 4,
				_octets + 5);
}

std::string MACAddress::ToString() const
{
    std::string out;
    char *buf = new char[18];
    std::snprintf(buf,18,"%02X:%02X:%02X:%02X:%02X:%02X",
            _octets[0], _octets[1], _octets[2],
            _octets[3], _octets[4], _octets[5]);
    out = buf;
    return out;
}

std::ostream& operator<<(std::ostream& os,  MACAddress& obj)
{
    os << obj.ToString();
    return os;
}

bool MACAddress::operator==(const MACAddress& other) const
{
    bool eq = std::memcmp(_octets, other._octets, 6);
    return eq == 0;
}

bool MACAddress::operator!=(const MACAddress& other) const
{
    return !(*this == other);
}