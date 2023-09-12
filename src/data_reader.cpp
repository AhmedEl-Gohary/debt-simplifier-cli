#include "../include/ledger.h"
#include "../include/data_reader.h"

#include <fstream>
#include <string>

void DataReader::readEntries(std::string& inputFileName, Ledger& ledger) {
    std::ifstream inputFile(inputFileName);

    std::string debtor, creditor;
    int money;
    while (inputFile >> debtor >> creditor >> money) {
        ledger.addEntry(debtor, creditor, money);
    }

    inputFile.close();
}
