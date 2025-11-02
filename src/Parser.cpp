//
// Created by jaden on 11/2/2025.
//

#include "Parser.h"
using namespace std;

// Constructor
Parser::Parser() {
    // yay, this parser exists.
}

// Getter for entries
vector<Entry> Parser::getEntries() {
    return entries;
}

/*
 * parseData
 * Input: string filename; file directory in relation to the makefile
 *                         file must be in IRMNG DwCA (Darwin Core Archive) format
 * Output: entries member modified
 *         bool returns true if successful, false if unsuccessful
*/
bool Parser::parseData(string filename) {

    return true;
}
