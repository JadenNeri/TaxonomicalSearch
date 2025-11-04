//
// Created by jaden on 11/2/2025.
//

#include "Entry.h"
using namespace std;


void Entry::displayPath() {
    cout << "Path to " << _sciName << ", AKA " << _genName << ": \n"
         << _kingdom << ", " << _phylum << ", " << _class << ", "
         << _order << ", " << _family << ", " << _genus << endl;
}
