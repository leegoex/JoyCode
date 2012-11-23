#ifndef _AVL_TREE_H_
#define _AVL_TREE_H_

#include "bst_base.h"

template<class T>
struct avl_node{
	T value;
	int height;
	avl_node *lchild;
	avl_node *rchild;

	avl_node(const T& v, int h, avl_node *l, avl_node *r):value(v),height(h),lchild(l),rchild(r){}
};

template<class T, class Node>
class avl_tree : public bst_base<T, Node>
{
public:
	avl_tree() : bst_base() {}
	~avl_tree() {}

private:
	virtual void insertNode(Node*& node, const T& value) {
		
	}
	virtual void removeNode(Node*& node, const T& value) {
		
	}
	virtual void removeMin(Node*& node, T& value) {
		
	}
	virtual Node* cloneNode(const Node *node) {
		if (node==NULL)
			return NULL;
		return new Node(node->value, node->height, cloneNode(node->lchild), cloneNode(node->rchild));
	}
};

#endif