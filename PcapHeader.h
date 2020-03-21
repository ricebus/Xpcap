//
// Created by George on 14-Mar-20.
//

#ifndef XPCAP_PCAPHEADER_H
#define XPCAP_PCAPHEADER_H


#include <cstdint>

class PcapHeader {
private:
    uint32_t _timestampSec;
    uint32_t _timestampUSec;
    uint32_t _savedPacketLength;
    uint32_t _origPacketLength;
    PcapHeader();

public:
    PcapHeader(const uint8_t* bytes, std::size_t size);
    ~PcapHeader() = default;
	[[nodiscard]] uint32_t SavedPacketLength() const;
    [[nodiscard]] uint32_t OrigPacketLength() const;
    constexpr static uint32_t HeaderSize() { return 16; }
};


#endif //XPCAP_PCAPHEADER_H
