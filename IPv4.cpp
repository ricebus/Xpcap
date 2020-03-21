//
// Created by George on 13-Mar-20.
//

#include <iostream>
#include "IPv4.h"
#include <iomanip>

IPv4::IPv4()
{
	_version = 0;
	_ihl = 0;
	_dscp = 0;
	_ecn = 0;
	_totalLength = 0;
	_identification = 0;
	_flags = IPFlags::DontFragment;
	_fragmentOffset = 0;
	_ttl = 0;
	_protocol = IPProtocol::TCP;
	_checksum = 0;
	_srcAddr = nullptr;
	_dstAddr = nullptr;
}

IPv4::IPv4(const uint8_t* bytes, size_t size) : IPv4()
{
    if(size < IPv4::HeaderSize())
        throw std::length_error("IPv4(): byte-array too small");

    uint8_t tmp8;
    uint16_t tmp16;
    uint8_t endiannessSwap[2];

    std::memcpy(&tmp8, bytes, 1);
    _version = tmp8 & 0xf0u >> 4u;
    _ihl = tmp8 & 0xfu;

    std::memcpy(&tmp8, bytes+1, 1);
    _dscp = tmp8 & 0xfcu >> 2u;
    _ecn = tmp8 & 0x3u;

    endiannessSwap[1] = *(bytes + 2);
    endiannessSwap[0] = *(bytes + 3);
    std::memcpy(&_totalLength, endiannessSwap, 2);
    endiannessSwap[1] = *(bytes + 4);
    endiannessSwap[0] = *(bytes + 5);
    std::memcpy(&_identification, endiannessSwap, 2);

    endiannessSwap[1] = *(bytes + 6);
    endiannessSwap[0] = *(bytes + 7);
    std::memcpy(&tmp16, endiannessSwap, 2); // swap
    _flags = static_cast<IPFlags>(tmp16 & 0xe000u >> 13u);
    _fragmentOffset = tmp16 & 0x1fffu;

    std::memcpy(&_ttl, bytes+8, 1);
    std::memcpy(&_protocol, bytes+9, 1);
    endiannessSwap[1] = *(bytes + 10);
    endiannessSwap[0] = *(bytes + 11);
    std::memcpy(&_checksum, endiannessSwap, 2); // swap
    _srcAddr = new IPAddress(bytes + 12, 4);
    _dstAddr = new IPAddress(bytes + 16, 4);
}

IPv4::~IPv4()
{
    delete(_srcAddr);
    delete(_dstAddr);
}

std::string IPv4::ToString() const
{
    std::stringstream os;

    os << "IP VERSION: " << std::to_string(_version) << " IHL: " << std::to_string(_ihl) << std::endl;
    os << std::hex << std::setw(2) << std::setfill('0');
    os << "DSCP: 0x" << (int)_dscp << " ECN: 0x" << (int)_ecn << std::endl;
    os << "LENGTH: " << std::dec << _totalLength << " (0x" << std::hex << (int)_totalLength << "), " <<
    "ID: " << std::dec << _identification << " (0x" << std::hex << (int)_identification << ")" << std::endl;
    os << std::dec;
    os << "FLAGS: " << (int)_flags << ", FRAGMENT OFFSET: " << _fragmentOffset << std::endl;
    os << "TTL: " << (int)_ttl << " PROTO: " << (int)_protocol << std::endl;
    os << "CHECKSUM: 0x" << std::hex << (int)_checksum << std::endl;
    os << "SRC IPADDR: " << _srcAddr->ToString() << std::endl;
    os << "DST IPADDR: " << _dstAddr->ToString() << std::endl;
    return os.str();
}

std::ostream& operator<<(std::ostream& os, const IPv4& obj)
{
    os << obj.ToString();
    return os;
}

IPProtocol IPv4::GetIPProtocol() {
    return _protocol;
}

const IPAddress *IPv4::GetDstAddr()
{
    return _dstAddr;
}

const IPAddress *IPv4::GetSrcAddr()
{
    return _srcAddr;
}

uint16_t IPv4::GetChecksum() const
{
    return _checksum;
}

IPProtocol IPv4::GetProtocol() const
{
    return _protocol;
}

uint8_t IPv4::GetTTL() const
{
    return _ttl;
}

uint16_t IPv4::GetFragmentOffset() const
{
    return _fragmentOffset;
}

IPFlags IPv4::GetFlags() const
{
    return _flags;
}

uint16_t IPv4::GetIdentification() const
{
    return _identification;
}

uint16_t IPv4::GetLength() const
{
    return _totalLength;
}

uint8_t IPv4::GetECN() const
{
    return _ecn;
}

uint8_t IPv4::GetDSCP() const
{
    return _dscp;
}

uint8_t IPv4::GetIHL() const
{
    return _ihl;
}

uint8_t IPv4::GetVersion() const
{
    return _version;
}
