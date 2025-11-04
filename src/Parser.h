//
// Created by jaden on 11/2/2025.
//

#ifndef PARSER_H
#define PARSER_H
#pragma once
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include "Entry.h"
using namespace std;



class Parser {
    // Members
    vector<Entry> entries;

    public:
    Parser();
    vector<Entry> getEntries();
    bool parseData(string filename);
};



#endif //PARSER_H
