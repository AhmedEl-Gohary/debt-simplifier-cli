#include "../include/data_writer.h"
#include "../include/ledger.h"

#include <iostream>
#include <fstream>

void DataWriter::writeLedger(std::ostream& os, Ledger& ledger) {
    os << ledger << std::endl;
}

void DataWriter::writeLedger(const std::string& outputFileName, Ledger& ledger) {
    std::ofstream outputFile(outputFileName);
    writeLedger(outputFile, ledger);
    outputFile.close();
}

void DataWriter::writeLedger(Ledger& ledger) {
    writeLedger(std::cout, ledger);
}
