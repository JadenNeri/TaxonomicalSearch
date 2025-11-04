//
// Created by jaden on 10/31/2025.
//

#ifndef ENTRY_H
#define ENTRY_H
#include <string>
#include <iostream>
#pragma once
using namespace std;


struct Entry {
    string _sciName;
    string _genName;
    string _kingdom;
    string _phylum;
    string _class;
    string _order;
    string _family;
    string _genus;
    Entry(string sN, string gN, string k, string p, string c, string o, string f, string g) :
          _sciName(sN), _genName(gN), _kingdom(k), _phylum(p), _class(c), _order(o),
          _family(f), _genus(g) {};
    Entry() : _sciName(""), _genName(""), _kingdom(""), _phylum(""), _class(""), _order(""),
              _family(""), _genus("") {};
    void displayPath();
};



#endif //ENTRY_H
