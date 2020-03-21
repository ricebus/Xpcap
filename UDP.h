//
// Created by George on 13-Mar-20.
//

#ifndef XPCAP_UDP_H
#define XPCAP_UDP_H


#include <cstdint>
#include <string>
#include "ApplicationProtocol.h"
#include "TransportProtocol.h"

class UDP : public TransportProtocol
{
private:
    uint16_t _srcPort;
    uint16_t _dstPort;
    uint16_t _length;
    uint16_t _checksum;
    UDP();

public:
    UDP(const uint8_t* bytes, size_t size);
    [[nodiscard]] std::string ToString() const override;
    friend std::ostream& operator<<(std::ostream& os, const UDP& obj);
    constexpr static uint32_t HeaderSize() { return 8; }
    ~UDP() override = default;

	uint16_t GetSrcPort() const;
	uint16_t GetDstPort() const;
	uint16_t GetLength() const;
	uint16_t GetChecksum() const;

};

#endif //XPCAP_UDP_H
