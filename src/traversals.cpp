//
// Created by nitro on 11/2/2025.
//

#include "traversals.h"
/*
 * For the time being, using a graph-like structure to traverse; n-ary tree traversals won't work
 * since the amount of children is variable; same with structure of basic trie traversal
 * given in lecture. Nodes have a vector of their children in the structure
 *
 * Additionally, I haven't timed the functions within, but we should use the chrono library
 * when we actually call in main to get the execution timing.
 */


bool traversals::depth_first(TrieNode* root, const std::string& target, std::vector<std::string>& path) {
    if (root->scientificName != "") { //if traversal is started at a node other than valueless root (for some reason) add to traversal path
        path.push_back(root->scientificName);
    }

    std::stack<TrieNode*> s; //stack for DFS
    s.push(root);
    std::unordered_map<TrieNode*, TrieNode*> parent_tracker; //map nodes to their parents to backtrack the correct path

    while (!s.empty()) {
        TrieNode* current = s.top();
        s.pop();

        if (current->scientificName == target) {
            TrieNode* temp = current;
            while (temp != nullptr) {
                path.push_back(temp->scientificName); //start from bottom-most search target (e.g., species), build upwards towards domain
                temp = parent_tracker[temp];
            }
            std::reverse(path.begin(), path.end()); //backtracked path is reversed to get true path
            return true;
        }

        for (TrieNode* child : current->children) {
            s.push(child);
            parent_tracker[child] = current; //current node is the parent of pushed child, for backtracking
        }
    }
    return false;
}

//much the same as DFS just using a queue
bool traversals::breadth_first(TrieNode* root, const std::string& target, std::vector<std::string>& path) {
    if (root->scientificName != "") {
        path.push_back(root->scientificName);
    }

    std::queue<TrieNode*> q;
    q.push(root);
    std::unordered_map<TrieNode*, TrieNode*> parent_tracker;

    while (!q.empty()) {
        TrieNode* current = q.front();
        q.pop();

        if (current->scientificName == target) {
            TrieNode* temp = current;
            while (temp != nullptr) {
                path.push_back(temp->scientificName);
                temp = parent_tracker[temp];
            }
            std::reverse(path.begin(), path.end());
            return true;
        }

        for (TrieNode* child : current->children) {
            q.push(child);
            parent_tracker[child] = current;
        }
    }
    return false;
}

void traversals::print_traversal_path(std::vector<std::string>& path) {
    if (path.size() == 0) {
        std::cout << "Error: Path was not found" << std::endl;
        return;
    }

    for (int i = 0; i < path.size(); i++) {
        std::string spacer = "     "; //set spacing for root
        for (int j = 0; j < i; j++) {
            spacer += "     "; //each level after root is an additional spacer further to the right
        }

        if (i == path.size() - 1) { //last index of path
            std::cout << spacer << "L---- " << path[i] << std::endl;
        }
        else { //indexes further up path
            std::cout << spacer << "|---- " << path[i] << std::endl;
        }
    }
}