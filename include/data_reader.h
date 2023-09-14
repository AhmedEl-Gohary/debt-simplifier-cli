#include "ledger.h"

#include <string>

#ifndef DATA_READER_H
#define DATA_READER_H

class DataReader {
public:
    int readEntries(const std::string&, std::vector<std::tuple<std::string, std::string, int>>&);
};

#endif //DATA_READER_H
