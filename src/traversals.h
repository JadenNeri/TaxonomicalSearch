//
// Created by nitro on 11/2/2025.
//

#ifndef TRAVERSALS_H
#define TRAVERSALS_H

#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <iostream>
#include "TaxonTrie.h"

/*
 * For now, using this temporary structure for cleanliness' sake. Will need to be changed ASAP.
 */
struct temp_node {
    std::string direct_value;
    std::vector<temp_node*> children;

};

struct traversals {
    bool depth_first(temp_node* root, const std::string& target, std::vector<std::string>& path);
    bool breadth_first(temp_node* root, const std::string& target, std::vector<std::string>& path);
    static void print_traversal_path(std::vector<std::string>& path);
};

#endif //TRAVERSALS_H
