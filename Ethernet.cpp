//
// Created by George on 13-Mar-20.
//

#include "Ethernet.h"
#include <iostream>
#include <ios>
#include <iomanip>

Ethernet::Ethernet()
{
	 _srcAddr = nullptr;
	 _dstAddr = nullptr;
	 _etherType = EthernetType::IPv4;
}

Ethernet::~Ethernet()
{
    delete(_srcAddr);
    delete(_dstAddr);
}

Ethernet::Ethernet(const uint8_t* bytes, size_t size) : Ethernet()
{
	_etherType = EthernetType::IPv4;
    if(size < Ethernet::HeaderSize())
        throw std::length_error("Ethernet(): byte-array too small");

    _srcAddr = new MACAddress(bytes,6);
    _dstAddr = new MACAddress(bytes+6,6);
    // Bytes are swapped.
    int8_t endiannessSwap[2];
    endiannessSwap[1] = *(bytes + 12);
    endiannessSwap[0] = *(bytes + 13);
    std::memcpy(&_etherType, endiannessSwap, 2);
}

std::string Ethernet::ToString() const
{
    std::stringstream os;
    os << "SRC MACADDR: " << _srcAddr->ToString() << std::endl;
    os << "DST MACADDR: " << _dstAddr->ToString() << std::endl;
    os << std::hex << std::setw(4) << std::setfill('0');
    os << "ETHERTYPE: 0x" << (int) _etherType << std::endl;
    return os.str();
}

std::ostream& operator<<(std::ostream& os, const Ethernet& obj)
{
    os << obj.ToString();
    return os;
}

EthernetType Ethernet::GetEthernetType() const
{
    return _etherType;
}

const MACAddress *Ethernet::GetDstAddr() const
{
	return _dstAddr;
}

const MACAddress *Ethernet::GetSrcAddr() const
{
	return _srcAddr;
}