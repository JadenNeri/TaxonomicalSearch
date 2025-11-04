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



vector<string> Entry::getPath() {
    vector<string> path;
    path.push_back(_kingdom);
    path.push_back(_phylum);
    path.push_back(_class);
    path.push_back(_order);
    path.push_back(_family);
    path.push_back(_genus);
    return path;
}
