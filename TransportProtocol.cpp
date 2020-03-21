//
// Created by George on 17-Mar-20.
//

#include "TransportProtocol.h"

TransportProtocol::~TransportProtocol() {
    delete(_payload);
}

void TransportProtocol::SetPayload(ApplicationProtocol **applicationProtocol) {
    _payload = *applicationProtocol;
}

TransportProtocol::TransportProtocol() {
    _payload = nullptr;
}

ApplicationProtocol *TransportProtocol::GetPayload() {
    return _payload;
}

