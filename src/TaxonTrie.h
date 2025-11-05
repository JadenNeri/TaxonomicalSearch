//
// Created by guill on 10/30/2025.
//
#include<vector>
#include<iostream>
#include<algorithm>
#include "Entry.h"
#pragma once
using namespace std;

#ifndef TAXONTRIE_H
#define TAXONTRIE_H

#endif //TAXONTRIE_H


struct TrieNode{

  string scientificName;
  string genericName;
  bool isCreature;;
  vector<TrieNode*> children;
  TrieNode* parent;

public:

    TrieNode(const string& t = "", const string& s = "", bool isC = false, TrieNode* p = nullptr){
      scientificName = t;
      genericName = s;
      isCreature = isC;
      parent = p;
    }

    ~TrieNode(){
      for(TrieNode* child : children){
        delete child;
      }
    }

    void insertChild(string t, string s = "", bool isCreature = false){
      this->children.push_back(new TrieNode(t, s, isCreature, this));
    }



 };


 class TaxonTrie{

   TrieNode* root = new TrieNode();

 public:

   // TaxonTrie();
   ~TaxonTrie() { //this should just recurse, as root is a trienode, trienode's destructor deletes it's children, etc
     delete root;
   }
   // void insert(const Entry* obj, TrieNode* t, int count);
   void insert(Entry thisEntry);
   TrieNode* getRoot();

 };
