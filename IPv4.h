//
// Created by George on 13-Mar-20.
//

#ifndef XPCAP_IPV4_H
#define XPCAP_IPV4_H


#include <cstdint>
#include "IPAddress.h"
#include "IPFlags.h"
#include "TransportProtocol.h"
#include "InternetProtocol.h"
#include "IPProtocol.h"

// No support for IPv4 Options (IHL>5)
// TODO: IP Header Options

class IPv4 : public InternetProtocol
{
private:
    uint8_t _version;
    uint8_t _ihl;
    uint8_t _dscp;
    uint8_t _ecn;
    uint16_t _totalLength;
    uint16_t _identification;
    IPFlags _flags;
    uint16_t _fragmentOffset;
    uint8_t _ttl;
    IPProtocol _protocol;
    uint16_t _checksum;
    IPAddress* _srcAddr;
    IPAddress* _dstAddr;
    IPv4();
    
public:
    IPv4(const uint8_t* bytes, size_t size);
    [[nodiscard]] std::string ToString() const override;
    friend std::ostream& operator<<(std::ostream& os, const IPv4& obj);
    constexpr static uint32_t HeaderSize() { return 20; }
    IPProtocol GetIPProtocol();
    ~IPv4() override;

    uint8_t GetVersion() const;
    uint8_t GetIHL() const;
    uint8_t GetDSCP() const;
    uint8_t GetECN() const;
    uint16_t GetLength() const;
    uint16_t GetIdentification() const;
    IPFlags GetFlags() const;
    uint16_t GetFragmentOffset() const;
    uint8_t GetTTL() const;
    IPProtocol GetProtocol() const;
    uint16_t GetChecksum() const;
    const IPAddress* GetSrcAddr();
    const IPAddress* GetDstAddr();
};


#endif //XPCAP_IPV4_H
