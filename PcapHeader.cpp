//
// Created by George on 14-Mar-20.
//

#include "PcapHeader.h"
#include <cstring>
#include <stdexcept>

PcapHeader::PcapHeader()
{
    _timestampSec = 0;
    _timestampUSec = 0;
    _savedPacketLength = 0;
    _origPacketLength = 0;
}

PcapHeader::PcapHeader(const uint8_t* bytes, std::size_t size) : PcapHeader()
{
    if(size < PcapHeader::HeaderSize())
        throw std::length_error("PcapHeader(): byte-array too small");

    std::memcpy(&_timestampSec, bytes, 4);
    std::memcpy(&_timestampUSec, bytes + 4, 4);
    std::memcpy(&_savedPacketLength, bytes + 8, 4);
    std::memcpy(&_origPacketLength, bytes + 12, 4);
}

uint32_t PcapHeader::SavedPacketLength() const
{
    return _savedPacketLength;
}

uint32_t PcapHeader::OrigPacketLength() const
{
    return _origPacketLength;
}

//constexpr const uint32_t PcapHeader::HeaderSize()
//{
//    return 16;
//}