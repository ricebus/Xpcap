//
// Created by George on 16-Mar-20.
//

#ifndef XPCAP_INTERNETPROTOCOL_H
#define XPCAP_INTERNETPROTOCOL_H

#include "TransportProtocol.h"
#include <string>

class InternetProtocol
{
protected:
    TransportProtocol* _payload;
    InternetProtocol();
public:
    virtual ~InternetProtocol();
    void SetPayload(TransportProtocol** transportProtocol);
    TransportProtocol* GetPayload();
    [[nodiscard]] virtual std::string ToString() const = 0;
};


#endif //XPCAP_INTERNETPROTOCOL_H
