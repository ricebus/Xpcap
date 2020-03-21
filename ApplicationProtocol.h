//
// Created by George on 16-Mar-20.
//

#ifndef XPCAP_APPLICATIONPROTOCOL_H
#define XPCAP_APPLICATIONPROTOCOL_H

#include <string>

class ApplicationProtocol
{
public:
    virtual ~ApplicationProtocol() = default;
	[[nodiscard]] virtual std::string ToString() const = 0;
};

#endif //XPCAP_APPLICATIONPROTOCOL_H
