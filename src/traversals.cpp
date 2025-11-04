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
    std::unordered_map<temp_node*, temp_node*> parent_tracker; //map nodes to their parents to backtrack the correct path

    while (!s.empty()) {
        temp_node* current = s.top();
        s.pop();

        if (current->direct_value == target) {
            temp_node* temp = current;
            while (temp != nullptr) {
                path.push_back(temp->direct_value); //start from bottom-most search target (e.g., species), build upwards towards domain
                temp = parent_tracker[temp];
            }
            std::reverse(path.begin(), path.end()); //backtracked path is reversed to get true path
            return true;
        }

        for (temp_node* child : current->children) {
            s.push(child);
            parent_tracker[child] = current; //current node is the parent of pushed child, for backtracking
        }
    }
    return false;
}

//much the same as DFS just using a queue
bool traversals::breadth_first(temp_node* root, const std::string& target, std::vector<std::string>& path) {
    if (root->direct_value != "") {
        path.push_back(root->direct_value);
    }

    std::queue<temp_node*> q;
    q.push(root);
    std::unordered_map<temp_node*, temp_node*> parent_tracker;

    while (!q.empty()) {
        temp_node* current = q.front();
        q.pop();

        if (current->direct_value == target) {
            temp_node* temp = current;
            while (temp != nullptr) {
                path.push_back(temp->direct_value);
                temp = parent_tracker[temp];
            }
            std::reverse(path.begin(), path.end());
            return true;
        }

        for (temp_node* child : current->children) {
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