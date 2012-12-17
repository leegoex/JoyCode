#ifndef _BST_TREE_H_
#define _BST_TREE_H_

#include "bst_base.h"

template<class T>
struct bst_node {
	T value;
	bst_node *lchild;
	bst_node *rchild;

	bst_node(const T& v, bst_node *l, bst_node *r):value(v),lchild(l),rchild(r){}
};

template<class T, class Node>
class bst_tree : public bst_base<T, Node>
{
public:
	bst_tree() : bst_base() {}
	~bst_tree() {}

private:
	virtual void insertNode(Node*& node, const T& value) {
		if (node == NULL) {
			node = new Node(value, NULL, NULL);
			return;
		}
		if (node->value < value)
			insertNode(node->rchild, value);
		if(node->value > value)
			insertNode(node->lchild, value);
	}
	virtual void removeNode(Node*& node, const T& value) {
		if(node == NULL)
			return;
		if (value < node->value) {
			removeNode(node->lchild, value);
		} else if(value >  node->value) {
			removeNode(node->rchild, value);
		} else if(node->lchild!=NULL && node->rchild!=NULL) {
			removeMin(node->rchild, node->value);
		} else {
			Node *old_value = node;
			node = (node->lchild != NULL)?node->lchild:node->rchild;
			delete old_value;
		}
	}
	virtual void removeMin(Node*& node, T& value) {
		if (node->lchild) {
			removeMin(node->lchild, value);
		} else {
			value = node->value;
			Node *tmp = node;
			node = (node->rchild != NULL)?node->rchild:NULL;
			delete tmp;
		}
	}
	virtual Node* cloneNode(const Node *node) {
		if (node==NULL)
			return NULL;
		return new Node(node->value, cloneNode(node->lchild), cloneNode(node->rchild));
	}
};


#endif