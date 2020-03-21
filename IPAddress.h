//
// Created by George on 13-Mar-20.
//

#ifndef XPCAP_IPADDRESS_H
#define XPCAP_IPADDRESS_H

#include <string>
#include <cstring>

class IPAddress {
public:
    IPAddress();
    IPAddress(const uint8_t* octets, size_t size);
    IPAddress(const std::string& ipString);
    [[nodiscard]] std::string ToString() const;
    bool operator==(const IPAddress& other);
    bool operator!=(const IPAddress& other);
    friend std::ostream& operator<<(std::ostream& os,  IPAddress& obj);
    ~IPAddress() = default;

private:
    uint8_t _octets[4] = {0};
	IPAddress(const char* ipString);
};

#endif //XPCAP_IPADDRESS_H
