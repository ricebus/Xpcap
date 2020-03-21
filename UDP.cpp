//
// Created by George on 13-Mar-20.
//

#include "UDP.h"
#include <sstream>
#include <cstring>

UDP::UDP()
{
	_srcPort = 0;
	_dstPort = 0;
	_length = 0;
	_checksum = 0;
}

UDP::UDP(const uint8_t* bytes, size_t size) : UDP()
{

    if(size < UDP::HeaderSize())
        throw std::length_error("UDP(): byte-array too small");

    uint8_t endiannessSwap[2];
    endiannessSwap[1] = *bytes;
    endiannessSwap[0] = *(bytes + 1);
    std::memcpy(&_srcPort, endiannessSwap, 2);
    endiannessSwap[1] = *(bytes + 2);
    endiannessSwap[0] = *(bytes + 3);
    std::memcpy(&_dstPort, endiannessSwap, 2);
    endiannessSwap[1] = *(bytes + 4);
    endiannessSwap[0] = *(bytes + 5);
    std::memcpy(&_length, endiannessSwap, 2);
	endiannessSwap[1] = *(bytes + 6);
    endiannessSwap[0] = *(bytes + 7);
    std::memcpy(&_checksum, endiannessSwap, 2);
}

std::string UDP::ToString() const
{
    std::stringstream os;

    os << "UDP LENGTH: " << std::to_string(_length) << " CHECKSUM: 0x" << std::hex << std::to_string(_checksum) << std::endl;
    os << "SRC PORT: " << std::to_string(_srcPort) << std::endl;
    os << "DST PORT: " << std::to_string(_dstPort) << std::endl;

    return os.str();
}

std::ostream& operator<<(std::ostream& os, const UDP& obj)
{
    os << obj.ToString();
    return os;
}

uint16_t UDP::GetSrcPort()
{
	return _srcPort;
}

uint16_t UDP::GetDstPort()
{
	return _dstPort;
}

uint16_t UDP::GetLength()
{
	return _length;
}

uint16_t UDP::GetChecksum()
{
	return _checksum;
}