//
// Created by George on 17-Mar-20.
//

#include "LinkProtocol.h"

LinkProtocol::~LinkProtocol() {
    delete(_payload);
}

void LinkProtocol::SetPayload(InternetProtocol **internetProtocol) {
    _payload = *internetProtocol;
}

LinkProtocol::LinkProtocol() {
    _payload = nullptr;
}

InternetProtocol *LinkProtocol::GetPayload() {
    return _payload;
}

