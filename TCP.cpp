//
// Created by George on 13-Mar-20.
//

#include "TCP.h"
#include <sstream>
#include <cstring>

TCP::TCP()
{
	_srcPort = 0;
	_dstPort = 0;
	_seqNumber = 0;
	_ackNumber = 0;
	_dataOffset = 0;
	_flags = TCPFlags::ACK;
	_windowSize = 0;
	_checksum = 0;
	_urgentPtr = 0;
}

TCP::TCP(const uint8_t* bytes, size_t size) : TCP()
{
    if(size < TCP::HeaderSize())
        throw std::length_error("TCP(): byte-array too small");

    uint8_t endiannessSwap[4];
    endiannessSwap[1] = *bytes;
    endiannessSwap[0] = *(bytes + 1);
    std::memcpy(&_srcPort, endiannessSwap, 2);
    endiannessSwap[1] = *(bytes + 2);
    endiannessSwap[0] = *(bytes + 3);
    std::memcpy(&_dstPort, endiannessSwap, 2);
    endiannessSwap[3] = *(bytes + 4);
    endiannessSwap[2] = *(bytes + 5);
    endiannessSwap[1] = *(bytes + 6);
    endiannessSwap[0] = *(bytes + 7);
    std::memcpy(&_seqNumber, endiannessSwap, 4);
    endiannessSwap[3] = *(bytes + 8);
    endiannessSwap[2] = *(bytes + 9);
    endiannessSwap[1] = *(bytes + 10);
    endiannessSwap[0] = *(bytes + 11);
    std::memcpy(&_ackNumber, endiannessSwap, 4);

    uint8_t tmp8 = 0, tmp8_2 = 0;
    std::memcpy(&tmp8, bytes+12, 1);
    _dataOffset = tmp8 >> 4u;
    //_flags = 0;
    uint16_t tmp16 = 0;
    std::memcpy(&tmp8_2, bytes+13, 1);
    tmp16 = tmp8_2;
    _flags = static_cast<TCPFlags>(tmp16 |  ((tmp8 & 1u) << 8u));

    endiannessSwap[1] = *(bytes + 14);
    endiannessSwap[0] = *(bytes + 15);
    std::memcpy(&_windowSize, endiannessSwap, 2);
    endiannessSwap[1] = *(bytes + 16);
    endiannessSwap[0] = *(bytes + 17);
    std::memcpy(&_checksum, endiannessSwap, 2);
    endiannessSwap[1] = *(bytes + 18);
    endiannessSwap[0] = *(bytes + 19);
    std::memcpy(&_urgentPtr, endiannessSwap, 2);
}

std::string TCP::ToString() const
{
    std::stringstream os;

    os << "TCP IHL: " << std::to_string(_dataOffset) << " CHECKSUM: 0x" << std::hex << (int)(_checksum) << std::endl;
    os << "SRC PORT: " << std::to_string(_srcPort) << std::endl;
    os << "DST PORT: " << std::to_string(_dstPort) << std::endl;
    os << "SEQ NUM: " << std::to_string(_seqNumber) << " ACK NUM: "<< std::to_string(_ackNumber)
       << " (WIN SIZE: " << std::to_string(_windowSize) << ")"<< std::endl;
    os << "URG PTR: " << std::to_string(_urgentPtr)  << " (0x" << std::hex << (int)_urgentPtr << ")" << std::endl;
    os << "FLAGS: " << std::to_string((int)_flags) << std::endl;

    return os.str();
}

std::ostream& operator<<(std::ostream& os, const TCP& obj)
{
    os << obj.ToString();
    return os;
}

uint16_t TCP::GetSrcPort()
{
	return _srcPort;
}

uint16_t TCP::GetDstPort()
{
	return _dstPort;
}

uint32_t TCP::GetSeqNumber()
{
	return _seqNumber;
}

uint32_t TCP::GetAckNumber()
{
	return _ackNumber;
}

uint8_t TCP::GetDataOffset()
{
	return _dataOffset;
}

TCPFlags TCP::GetFlags()
{
	return _flags;
}

uint16_t TCP::GetWindowSize()
{
	return _windowSize;
}

uint16_t TCP::GetChecksum()
{
	return _checksum;
}

uint16_t TCP::GetUrgentPtr()
{
	return _urgentPtr;
}
