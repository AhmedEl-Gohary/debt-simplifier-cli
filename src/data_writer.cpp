#include "../include/data_writer.h"

#include <iostream>
#include <fstream>

void DataWriter::writeLedger(std::ostream& os, Ledger& ledger) {
    os << ledger;
}

void DataWriter::writeLedger(std::string outputFileName, Ledger& ledger) {
    std::ofstream outputFile(outputFileName);
    writeLedger(outputFile, ledger);
    outputFile.close();
}

void DataWriter::writeLedger(Ledger& ledger) {
    writeLedger(std::cout, ledger);
}