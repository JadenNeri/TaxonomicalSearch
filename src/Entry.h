//
// Created by jaden on 10/31/2025.
//

#ifndef ENTRY_H
#define ENTRY_H
#include <string>
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
    Entry(string sN, string gN, string k, string p, string c, string o, string f, string g)
        : _sciName(sN), _genName(gN), _kingdom(k), _phylum(p), _class(c), _order(o),
          _family(f), _genus(g) {};
};



#endif //ENTRY_H
