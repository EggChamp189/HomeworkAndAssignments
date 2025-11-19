//
//  bst.h
//
//  Defines a class for a binary search tree.
//  You SHOULD modify this file.
//
//  IMPORTANT NOTE: For this particular assignment you may not add
//  any additional utility functions.
//
//  Copyright 2019 David Kopec
//
//  Permission is hereby granted, free of charge, to any person
//  obtaining a copy of this software and associated documentation files
//  (the "Software"), to deal in the Software without restriction,
//  including without limitation the rights to use, copy, modify, merge,
//  publish, distribute, sublicense, and/or sell copies of the Software,
//  and to permit persons to whom the Software is furnished to do so,
//  subject to the following conditions:
//
//  The above copyright notice and this permission notice
//  shall be included in all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
//  OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
//  THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR
//  OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
//  ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
//  OTHER DEALINGS IN THE SOFTWARE.

#ifndef bst_hpp
#define bst_hpp

#include <list>
#include <optional>
#include <random>

#include "MemoryLeakDetector.h"

using namespace std;

namespace csi281 {

  template <typename T> class BST {
  public:
    // *Node* represents one node in the tree
    struct Node {
      Node(T k, Node *l, Node *r) : key(k), left(l), right(r) {}
      T key;
      Node *left;
      Node *right;
    };

    // Delete a node and all of its children
    void deleteHelper(Node *node) {
      if (node == nullptr) {
        return;
      }
      deleteHelper(node->left);
      deleteHelper(node->right);
      delete node;
    }

    // Delete all nodes
    ~BST() {
      deleteHelper(root);
    }

    // Add a new node to the tree with *key*
    // Make sure to insert it into the correct place
    // NOTE: We are allowing duplicates, so, <= and >, or < and >=
    // for traversing left and right should be used
    // TIP: If the tree is empty, remember that you
    // need to initialize root
    void insert(T key) {
      // YOUR CODE HERE
      // just make the root if the tree is empty
      if (root == nullptr) {
        root = new Node(key, nullptr, nullptr);
        count++;
        return;
      }

      // iteratively go down the tree
      Node *curr = root;
      while (true) {
        // less than or equal to keys go to the left subtree first
        if (key <= curr->key) {
          // found empty spot on the left
          if (curr->left == nullptr) {
            curr->left = new Node(key, nullptr, nullptr);
            count++;
            return;
          }
          // go to the next if there isn't space
          curr = curr->left;
        } else {
          // greater keys go to right
          if (curr->right == nullptr) {
            curr->right = new Node(key, nullptr, nullptr);
            count++;
            return;
          }
          // go to the next if there isn't space
          curr = curr->right;
        }
      }
    }

    // Do a search through the tree and return
    // whether or not it contains *key*
    bool contains(const T &key) {
      // YOUR CODE HERE
      Node *curr = root;

      while (curr != nullptr) {
        // key found!
        if (key == curr->key) return true;

        // decide which to check next
        curr = (key < curr->key) ? curr->left : curr->right;
      }

      // no key found
      return false;
    }

    // Helper for inOrderWalk() to call for entire bst
    void inOrderWalk(list<T> &accumulated) { inOrderWalk(accumulated, root); }

    // Walk through the entire tree in ascending order, starting
    // from *current*, and accumulate the values in the
    // list *accumulated*
    // TIP: See page 288 of Chapter 12 of Introduction to Algorithms
    void inOrderWalk(list<T> &accumulated, Node *current) {
      // YOUR CODE HERE
      // base case nothing
      if (current == nullptr) return;

      // linear traversal:
      // 1. check left
      inOrderWalk(accumulated, current->left);

      // 2. check current
      accumulated.push_back(current->key);

      // 3. check right
      inOrderWalk(accumulated, current->right);
    }

    // Find the minimum key in the tree
    // If the tree is empty, return nullopt
    optional<T> minimum() {
      // YOUR CODE HERE
      // if the tree is empty, there just won't be a min
      if (root == nullptr) return nullopt;

      // the min will always be left
      Node *curr = root;
      while (curr->left != nullptr) {
        curr = curr->left;
      }
      return curr->key;
    }

    // Find the maximum key in the tree
    // If the tree is empty, return nullopt
    optional<T> maximum() {
      // YOUR CODE HERE
      // if the tree is empty, there just won't anything
      if (root == nullptr) return nullopt;

      // max is always at the right
      Node *curr = root;
      while (curr->right != nullptr) {
        curr = curr->right;
      }
      return curr->key;
    }

    // How many nodes are in the tree?
    int getCount() { return count; }

  private:
    Node *root = nullptr;
    int count = 0;
  };

}  // namespace csi281

#endif /* bst_hpp */
