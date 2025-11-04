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
    string path = "../data/" + filename;
    ifstream file(path);
    if (!file.is_open()) {
        cout << "[Debug_Parser] File failed to open." << endl;
        return false;
    } else {
        // Begin parsing
        string line;
        getline(file, line);    // Reads in the first line, the column titles. Will essentially skip it.
        // Parse each line
        while (getline(file, line)) {
            Entry thisEntry = Entry();
            bool isAccepted = false;
            string element;
            stringstream lineSS(line);
            // Parse each element of each line
            for (int i = 1; i <= 22; i++) {
                getline(lineSS, element, '\t');
                // cout << element << " " << i << endl;
                switch (i) {
                    case 5: // Column E
                        thisEntry._sciName = element;
                        break;
                    case 6: // Column F
                        thisEntry._genName = element;
                        break;
                    case 10: // Column J
                        thisEntry._kingdom = element;
                        break;
                    case 11: // Column K
                        thisEntry._phylum = element;
                        break;
                    case 12: // Column L
                        thisEntry._class = element;
                        break;
                    case 13: // Column M
                        thisEntry._order = element;
                        break;
                    case 14: // Column N
                        thisEntry._family = element;
                        break;
                    case 15: // Column O
                        thisEntry._genus = element;
                        break;
                    case 22: // Column V
                        if (element == "accepted") {
                            isAccepted = true;
                        }
                        break;
                    // default:
                    //     cout << "[Debug_Parser] Unknown entry type." << endl;
                    //     break;
                }
            }
            // cout << isAccepted << endl;
            // cout << thisEntry._genus << endl;
            if (isAccepted && !thisEntry._genus.empty()) {
                entries.push_back(thisEntry);
            }
        }
    }
    file.close();
    return true;
}
