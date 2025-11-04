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

   TrieNode* root;

 public:

   TaxonTrie();
   ~TaxonTrie();
   void insert(const Entry* obj, TrieNode* t, int count);

 };

void TaxonTrie::insert(const Entry* obj, TrieNode* t, int count = 0){
  bool found = false;
  for(auto it = t->children.begin(); it != t->children.end(); it++){
    if((*it)->scientificName == obj->_kingdom && count == 0){
      found = true;
      insert(obj, *it, 1);
    }
    else if((*it)->scientificName == obj->_phylum && count == 1){
      found = true;
      insert(obj, *it, 2);
    }
    else if((*it)->scientificName == obj->_class && count == 2){
      found = true;
      insert(obj, *it, 3);
    }
    else if((*it)->scientificName == obj->_order && count == 3){
      found = true;
      insert(obj, *it, 4);
    }
    else if((*it)->scientificName == obj->_family && count == 4){
      found = true;
      (*it)->insertChild(obj->_sciName, obj->_genName, true);
    }
  }
  if(!found){
    if(count == 0){
      t->insertChild(obj->_kingdom);
    }
    else if(count == 1){
      t->insertChild(obj->_phylum);
    }
    else if(count == 2){
      t->insertChild(obj->_class);
    }
    else if(count == 3){
      t->insertChild(obj->_order);
    }
    else if(count == 4){
      t->insertChild(obj->_family);
    }
  }

}