//
// Created by jaden on 10/29/2025.
//

#include "main.h"
#include "Parser.h"
#include "Entry.h"
#include "traversals.h"
using namespace std;

int main() {
    // Entry testEntry = Entry("a", "b", "c", "d", "e", "f", "g", "h");
    // testEntry.displayPath();

    Parser parser;
    parser.parseData("notAccepted.txt");
    for (Entry entry : parser.getEntries()) {
        entry.displayPath();
    }
}