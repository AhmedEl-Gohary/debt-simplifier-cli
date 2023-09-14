#include "ledger.h"

#ifndef DATA_WRITER_H
#define DATA_WRITER_H

class DataWriter {
private:
    void writeLedger(std::ostream&, Ledger&);

public:
    void writeLedger(const std::string&, Ledger&);
    void writeLedger(Ledger&);

};

#endif //DATA_WRITER_H
