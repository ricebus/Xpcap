//
// Created by George on 13-Mar-20.
//

#ifndef XPCAP_TCP_H
#define XPCAP_TCP_H

#include "TCPFlags.h"
#include <cstdint>
#include <string>
#include "ApplicationProtocol.h"
#include "TransportProtocol.h"

// TODO: TCP Header Options

class TCP : public TransportProtocol
{
private:
    uint16_t _srcPort;
    uint16_t _dstPort;
    uint32_t _seqNumber;
    uint32_t _ackNumber;
    uint8_t _dataOffset;
    TCPFlags _flags;
    uint16_t _windowSize;
    uint16_t _checksum;
    uint16_t _urgentPtr;
    TCP();

public:
    TCP(const uint8_t* bytes, size_t size);
    [[nodiscard]] std::string ToString() const override;
    friend std::ostream& operator<<(std::ostream& os, const TCP& obj);
    constexpr static uint32_t HeaderSize() { return 20; }
    ~TCP() override = default;

	uint16_t GetSrcPort();
	uint16_t GetDstPort();
	uint32_t GetSeqNumber();
	uint32_t GetAckNumber();
	uint8_t GetDataOffset();
	TCPFlags GetFlags();
	uint16_t GetWindowSize();
	uint16_t GetChecksum();
	uint16_t GetUrgentPtr();
};

#endif //XPCAP_TCP_H
