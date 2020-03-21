//
// Created by George on 16-Mar-20.
//

#ifndef XPCAP_TRANSPORTPROTOCOL_H
#define XPCAP_TRANSPORTPROTOCOL_H

#include "ApplicationProtocol.h"
#include <string>

class TransportProtocol
{
protected:
    ApplicationProtocol* _payload;
    TransportProtocol();
public:
    virtual ~TransportProtocol();
    void SetPayload(ApplicationProtocol** applicationProtocol);
    ApplicationProtocol* GetPayload();
    [[nodiscard]] virtual std::string ToString() const = 0;
};

#endif //XPCAP_TRANSPORTPROTOCOL_H
