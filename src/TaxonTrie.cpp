//
// Created by jaden on 11/4/2025.
//

#include "TaxonTrie.h"



// void TaxonTrie::insert(const Entry* obj, TrieNode* t, int count = 0){
//     bool found = false;
//     for(auto it = t->children.begin(); it != t->children.end(); it++){
//         if((*it)->scientificName == obj->_kingdom && count == 0){
//             found = true;
//             insert(obj, *it, 1);
//         }
//         else if((*it)->scientificName == obj->_phylum && count == 1){
//             found = true;
//             insert(obj, *it, 2);
//         }
//         else if((*it)->scientificName == obj->_class && count == 2){
//             found = true;
//             insert(obj, *it, 3);
//         }
//         else if((*it)->scientificName == obj->_order && count == 3){
//             found = true;
//             insert(obj, *it, 4);
//         }
//         else if((*it)->scientificName == obj->_family && count == 4){
//             found = true;
//                 (*it)->insertChild(obj->_sciName, obj->_genName, true);
//         }
//     }
//     if(!found){
//         if(count == 0){
//             t->insertChild(obj->_kingdom);
//         }
//         else if(count == 1){
//             t->insertChild(obj->_phylum);
//         }
//         else if(count == 2){
//             t->insertChild(obj->_class);
//         }
//         else if(count == 3){
//             t->insertChild(obj->_order);
//         }
//         else if(count == 4){
//             t->insertChild(obj->_family);
//         }
//     }
//
// }



TrieNode* TaxonTrie::getRoot() {
    return root;
}



void TaxonTrie::insert(Entry thisEntry) {
    vector<string> path = thisEntry.getPath();
    TrieNode* current = root;
    for (string taxon : path) {
        // Figure out if the next taxon is in the children
        bool found = false;
        int foundIndex = -1;
        if (!current->children.empty()) {
            for (int i = 0; i < current->children.size(); i++) {
                if (current->children[i]->scientificName == taxon) {
                    found = true;
                    foundIndex = i;
                }
            }
        } // If current->children.size() is 0, then found will remain false
        // Introduce a new TrieNode if necessary
        if (!found) {
            current->children.push_back(new TrieNode(taxon, taxon, true, current));
            current = current->children[current->children.size() - 1];
        } else {
            current = current->children[foundIndex];
        }
        current->isCreature = true;
    }
}
