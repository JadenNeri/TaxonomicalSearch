//
// Created by jaden on 10/29/2025.
//

#include "main.h"
#include "Parser.h"
#include "Entry.h"
#include "traversals.h"
#include "TaxonTrie.h"
#include <chrono>
#include <iomanip>
using namespace std;

int main() {
    // Testing Area:  Comment everything out once done testing.
    // Testing Entries
    // Entry testEntry = Entry("a", "b", "c", "d", "e", "f", "g", "h");
    // testEntry.displayPath();

    // Testing Parser
    // Parser parser;
    // parser.parseData("taxon.txt");
    // for (Entry entry : parser.getEntries()) {
    //     entry.displayPath();
    // }

    // Initialize variables
    string menu = R"(
======Taxonomical Search======
1. Read file
2. Display all Entries
3. Search
4. Quit
)";
    string prompt = "Your choice: ";
    int choice = 0;
    int choice2 = 0;
    Parser parser;
    TaxonTrie taxon;
    vector<string> path;
    bool done = false;
    string filename;
    string target;

    while (!done) {
        cout << menu;
        cout << prompt;
        cin >> choice;
        switch (choice) {
            case 1: // Read file
                cout << "Enter filename: ";
                cin.ignore(1000, '\n');
                getline(cin, filename);
                if (parser.parseData(filename)) {
                    cout << "File successfully read." << endl;
                } else {
                    cout << "File not found." << endl;
                }
            for (Entry entry : parser.getEntries()) {
                taxon.insert(entry);
            }
                break;
            case 2: // Display all Entries
                if (parser.getEntries().size() == 0) {
                    cout << "No data exists to read." << endl;
                } else if (parser.getEntries().size() > 10) {
                    while (choice2 != 1 && choice2 != 2) {
                        cout << "WARNING: There are many entries that are about to be displayed. Proceed anyway?" << endl;
                    cout << "1. Proceed \n"
                            "2. Go back \n"
                         << prompt;
                        cin >> choice2;
                        if (choice2 == 1) {
                            for (Entry entry : parser.getEntries()) {
                                entry.displayPath();
                            }
                        } else if (choice2 == 2) {
                            break;
                        } else {
                            cout << "Invalid Choice." << endl;
                        }
                    }
                    choice2 = -1; // Reset choice2 for future warnings
                } else {
                    for (Entry entry : parser.getEntries()) {
                        entry.displayPath();
                    }
                }
                break;
            case 3: { //added brackets to close case scope
                // Search
                cout << "Enter target taxon: ";
                cin.ignore(1000, '\n');
                getline(cin, target);
                std::chrono::high_resolution_clock::time_point start; //init timers for search algo's
                std::chrono::high_resolution_clock::time_point end;
                while (choice2 != 1 && choice2 != 2) {
                    cout << "Which search algorithm would you like to use?" << endl;
                    cout << "1. Breadth First Search \n"
                            "2. Depth First Search \n"
                         << prompt;
                    cin >> choice2;
                    if (choice2 == 1) { // BFS
                        path.clear();
                        start = chrono::high_resolution_clock::now(); //get time points for BFS
                        traversals::breadth_first(taxon.getRoot(), target, path);
                        end = chrono::high_resolution_clock::now();
                    } else if (choice2 == 2) {  // DFS
                        path.clear();
                        start = chrono::high_resolution_clock::now(); //and DFS
                        traversals::depth_first(taxon.getRoot(), target, path);
                        end = chrono::high_resolution_clock::now();
                    } else {
                        cout << "Invalid Choice." << endl;
                    }
                }
                choice2 = -1; // Reset choice2 for future warnings
                auto elapsed_searchtime = std::chrono::duration_cast<std::chrono::microseconds>(end - start); //end - start for total elapsed duration
                traversals::print_traversal_path(path);
                std::cout << std::fixed << std::setprecision(6) << "\n" << "Search took: " << (elapsed_searchtime.count() / 1e6) << " seconds" << std::endl; //iomanip to print decimal seconds
                break;
            }
            case 4: // Quit
                done = true;
                break;
            default:
                cout << "Invalid Choice." << endl;
                break;
        }
    }

}