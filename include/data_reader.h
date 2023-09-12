#include "ledger.h"

#include <string>

#ifndef DATA_READER_H
#define DATA_READER_H

class DataReader {
public:
    void readEntries(std::string&, Ledger&);
};

#endif //DATA_READER_H
