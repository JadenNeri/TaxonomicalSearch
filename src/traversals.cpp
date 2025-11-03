//
// Created by nitro on 11/2/2025.
//

#include "traversals.h"
/*
 * For the time being, using a graph-like structure to traverse; n-ary tree traversals won't work
 * since the amount of children is variable; same with structure of basic trie traversal
 * given in lecture. Assuming nodes will have a vector of their children.
 *
 * Additionally, I haven't timed the functions within, but we should use the chrono library
 * when we actually call in main to get the execution timing.
 */


bool traversals::depth_first(temp_node* root, const std::string& target, std::vector<std::string>& path) {
    if (root->direct_value != "") { //if traversal is started at a node other than valueless root (for some reason) add to traversal path
        path.push_back(root->direct_value);
    }

    std::stack<temp_node*> s; //stack for DFS
    s.push(root);

    while (!s.empty()) {
        temp_node* current = s.top();
        s.pop();

        if (current->direct_value == target) {
            return true;
        }

        for (temp_node* child : current->children) {
            s.push(child);
            path.push_back(child->direct_value);
        }
    }
    return false;
}

bool traversals::breadth_first(temp_node* root, const std::string& target, std::vector<std::string>& path) {
    if (root->direct_value != "") {
        path.push_back(root->direct_value);
    }

    std::queue<temp_node*> q;
    q.push(root);

    while (!q.empty()) {
        temp_node* current = q.front();
        q.pop();

        if (current->direct_value == target) {
            return true;
        }

        for (temp_node* child : current->children) {
            q.push(child);
            path.push_back(child->direct_value);
        }
    }
    return false;
}