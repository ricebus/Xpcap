//
// Created by George on 16-Mar-20.
//

#ifndef XPCAP_LINKPROTOCOL_H
#define XPCAP_LINKPROTOCOL_H

#include "InternetProtocol.h"
#include <string>

class LinkProtocol
{
protected:
    InternetProtocol* _payload;
    LinkProtocol();
public:
    virtual ~LinkProtocol();
    void SetPayload(InternetProtocol** internetProtocol);
    InternetProtocol* GetPayload();
    [[nodiscard]] virtual std::string ToString() const = 0;
};

#endif //XPCAP_LINKPROTOCOL_H
