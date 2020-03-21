//
// Created by George on 13-Mar-20.
//

#ifndef XPCAP_MACADDRESS_H
#define XPCAP_MACADDRESS_H

#include <string>
#include <cstring>

class MACAddress {
public:
    MACAddress();
    MACAddress(const uint8_t* octets, size_t size);
	MACAddress(const std::string& macString);
	[[nodiscard]] std::string ToString() const;
    bool operator==(const MACAddress& other) const;
    bool operator!=(const MACAddress& other) const;
    friend std::ostream& operator<<(std::ostream& os,  MACAddress& obj);
    ~MACAddress() = default;

private:
    uint8_t _octets[6] = {0};
	MACAddress(const char* macString);
};

#endif //XPCAP_MACADDRESS_H
