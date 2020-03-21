//
// Created by George on 17-Mar-20.
//

#include "InternetProtocol.h"

InternetProtocol::~InternetProtocol() {
    delete(_payload);
}

void InternetProtocol::SetPayload(TransportProtocol** transportProtocol) {
    _payload = *transportProtocol;
}

InternetProtocol::InternetProtocol() {
    _payload = nullptr;
}

TransportProtocol *InternetProtocol::GetPayload() {
    return _payload;
}


