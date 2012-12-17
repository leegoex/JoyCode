#ifndef _AVL_TREE_H_
#define _AVL_TREE_H_

#include "bst_base.h"
using namespace std;

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
	int height(Node* node) {
		if (node==NULL)
			return -1;
		return node->height;
	}
	int maxHeight(int a, int b) {
		return (a>b?a:b);
	}
	void rotateWithLeftChild(Node*& node) {
		Node* tmp_node = node->lchild;
		node->lchild = tmp_node->rchild;
		tmp_node->rchild = node;
		node->height = 1 +  maxHeight(height(node->lchild), height(node->rchild));
		tmp_node->height = 1 + maxHeight(height(tmp_node->lchild), height(tmp_node->rchild));
		node = tmp_node;
	}
	void rotateWithRightChild(Node*& node) {
		Node* tmp_node = node->rchild;
		node->rchild = tmp_node->lchild;
		tmp_node->lchild = node;
		node->height = 1 +  maxHeight(height(node->lchild), height(node->rchild));
		tmp_node->height = 1+ maxHeight(height(tmp_node->lchild), height(tmp_node->rchild));
		node = tmp_node;
	}
	void doubleRotateWithLeftChild(Node*& node) {
		rotateWithRightChild(node->lchild);
		rotateWithLeftChild(node);
	}
	void doubleRotateWithRightChild(Node*& node) {
		rotateWithLeftChild(node->rchild);
		rotateWithRightChild(node);
	}
	virtual void insertNode(Node*& node, const T& value) {
		if (node == NULL) 
		{
			node = new Node(value, -1, NULL, NULL);
		} 
		else 
		{
			if (node->value > value) 
			{
				insertNode(node->lchild, value);
				if (height(node->lchild) - height(node->rchild) == 2)
				{
					if (node->lchild->value > value) {
						rotateWithLeftChild(node);
					}else {
						doubleRotateWithLeftChild(node);
					}
				}
			} 
			else if (node->value < value) 
			{
				insertNode(node->rchild, value);
				if (height(node->rchild) - height(node->lchild) == 2)
				{
					if (node->rchild->value < value) {
						rotateWithRightChild(node);
					} else {
						doubleRotateWithRightChild(node);
					}
				}
			}
		}
		node->height = 1 +  maxHeight(height(node->lchild), height(node->rchild));
	}
	virtual void removeNode(Node*& node, const T& value) {
		if(node == NULL)
			return;
		if (value < node->value) {
			removeNode(node->lchild, value);
			if (height(node->rchild)-height(node->lchild) == 2) {
				if (height(node->rchild->rchild) > height(node->rchild->lchild))
					rotateWithRightChild(node);
				else
					doubleRotateWithRightChild(node);
			}
		} else if(value >  node->value) {
			removeNode(node->rchild, value);
			if (height(node->lchild)-height(node->rchild) == 2) {
				if (height(node->lchild->lchild) > height(node->lchild->rchild))
					rotateWithLeftChild(node);
				else
					doubleRotateWithLeftChild(node);
			}
		} else if(node->lchild!=NULL && node->rchild!=NULL) {
			removeMin(node->rchild, node->value);
		} else {
			Node *old_value = node;
			node = (node->lchild != NULL)?node->lchild:node->rchild;
			delete old_value;
		}
		if (node)
			node->height = 1 + maxHeight(height(node->lchild), height(node->rchild));
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
		if (node)
			node->height = 1 + maxHeight(height(node->lchild), height(node->rchild));
	}
	virtual Node* cloneNode(const Node *node) {
		if (node==NULL)
			return NULL;
		return new Node(node->value, node->height, cloneNode(node->lchild), cloneNode(node->rchild));
	}
};

#endif