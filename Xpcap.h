//
// Created by George on 19-Mar-20.
//

#ifndef XPCAP_XPCAP_H
#define XPCAP_XPCAP_H


#include <string>
#include "Packet.h"
#include <list>
#include <fstream>

class Xpcap {
private:
    std::string _filename;
    std::size_t _fileSize;
    std::list<Packet*> _packetList;
    uint8_t* _buffer;
    std::ifstream _fileStream;
    std::size_t _bufferSize;
    std::size_t _actualBufferSize;

    bool Open();
    void Close();

public:
    explicit Xpcap(std::string& filename, std::size_t bufferSize = 0);
    ~Xpcap();
    size_t Read();
    size_t PcapSize();
    const std::list<Packet*>* GetPacketList();
    bool Parse();
};


#endif //XPCAP_XPCAP_H
