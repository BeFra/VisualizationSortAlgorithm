/*
 * BinarySearchTree.cpp
 *
 *  Created on: 16.03.2015
 *      Author: befrank
 */
#include <stdlib.h>
#include "BinarySearchTree.hpp"

namespace Collection {
	BinarySearchTree::Node::Node()
		:left(NULL), right(NULL), data(0) {

	}

	BinarySearchTree::Node::~Node() {

	}

	BinarySearchTree::BinarySearchTree()
		:root(NULL), size_(0)
	{

	}

	BinarySearchTree::~BinarySearchTree() {
		clear();
	}
	void BinarySearchTree::clear() {
		root = NULL;
		size_ = 0;
	}

	void BinarySearchTree::clearR(Node* node) {
		if( node == NULL) {
			return;
		} else {
			clearR(node->left);
			clearR(node->right);
			delete node;
		}
	}

	bool BinarySearchTree::contains(const int value) const {
		return containsR(root, value);
	}

	bool BinarySearchTree::containsR(Node *node, const int value) const {
		if (node == NULL) {
			return false;
		} else if( value < node->data) {
			return containsR(node->left, value);
		} else if(value > node->data) {
			return containsR(node->right, value);
		} else {
			return true;
		}
	}

	void BinarySearchTree::insert(const int value) {
		root = insertR(root, value);
	}

	BinarySearchTree::Node* BinarySearchTree::insertR(Node *node, const int value) {
		if(node == NULL) {
			node = new Node();
			node->data = value;
			size_++;
		} else if (value < node->data) {
			node->left = insertR(node->left, value);
		} else if(value > node->data) {
			node->right = insertR(node->right, value);
		} else {
			/* value is duplicated, do nothing */
		}
		return node;
	}

	void BinarySearchTree::remove(const int value) {
		root = removeR(root, value);
	}

	BinarySearchTree::Node* BinarySearchTree::removeR(Node* node, const int value) {
		Node* result;
		if(node == NULL) {
			result = NULL;
		} else if (value < node->data) {
			node->left = removeR(node->left, value);
			result = node;
		} else if (value > node->data) {
			node->right = removeR(node->right, value);
			result = node;
		} else {
			if (node->left == NULL || node->right == NULL) { /* if one or zero child */
				result = ( node->left != NULL) ? node->left : node->right;
				delete node;
				size_--;
			} else { /* two child */
				result = node;
				result->data = getMin(node->right);
				result->right = removeR(node->right, node->data);
			}
		}
		return result;
	}

	int BinarySearchTree::getMin(Node* node) const {
		while(node->left == NULL) {
			node = node->left;
		}
		return node->data;

	}

	bool BinarySearchTree::empty() const{
		return size_ == 0;
	}

	int BinarySearchTree::size() const {
		return size_;
	}
}


