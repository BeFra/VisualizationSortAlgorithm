/*
 * BinarySearchTree.hpp
 *
 *  Created on: 16.03.2015
 *      Author: befrank
 */

#ifndef COLLECTION_BINARYSEARCHTREE_HPP_
#define COLLECTION_BINARYSEARCHTREE_HPP_

namespace Collection {
	class BinarySearchTree {
	private:
		class Node {
		public:
			Node();
			~Node();
			Node *left;
			Node *right;
			int data;
		};

		Node *root;
		int size_;

		bool containsR(Node* node, const int value) const;
		Node* insertR(Node* node, const int value);
		Node* removeR(Node* node, const int value);
		int getMin(Node* node) const;
		void clearR(Node* node);

	public:
		BinarySearchTree();
		~BinarySearchTree();

		bool contains(const int value) const;
		void remove(const int value);
		void insert(const int value);


		int size() const;
		bool empty() const;
		void clear();
	};
}



#endif /* COLLECTION_BINARYSEARCHTREE_HPP_ */
