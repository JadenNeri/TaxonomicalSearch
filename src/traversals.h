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
#pragma once

/*
 * For now, using this temporary structure for cleanliness' sake. Will need to be changed ASAP.
 */


struct traversals {
    static bool depth_first(TrieNode* root, const std::string& target, std::vector<std::string>& path);
    static bool breadth_first(TrieNode* root, const std::string& target, std::vector<std::string>& path);
    static void print_traversal_path(std::vector<std::string>& path);
};

#endif //TRAVERSALS_H
