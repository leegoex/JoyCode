#include <iostream>
#include "binarysearch_tree.h"
using namespace std;

template<class T>
binarysearch_tree<T>::binarysearch_tree() : m_root(NULL)
{

}

template<class T>
binarysearch_tree<T>::binarysearch_tree(const binarysearch_tree& rhs)
{
	m_root = rhs.m_root;
}

template<class T>
binarysearch_tree<T>::~binarysearch_tree()
{
	makeEmpty();
}

template<class T>
const T& binarysearch_tree<T>::findMin() const
{
	binarysearch_node *tmp = m_root;
	while(tmp->lchild) tmp = tmp->lchild;
	return tmp->value;
}

template<class T>
const T& binarysearch_tree<T>::findMax() const
{
	binarysearch_node *tmp = m_root;
	while(tmp->rchild) tmp = tmp->rchild;
	return tmp->value;
}

template<class T>
bool binarysearch_tree<T>::findValue(const binarysearch_node *node, const T& value) const
{
	if (node==NULL)
		return false;
	if (value == node->value)
		return true;
	if (value < node->value)
		return findValue(node->lchild, value);
	else
		return findValue(node->rchild, value);
}

template<class T>
bool binarysearch_tree<T>::contains(const T& value) const
{
	return findValue(m_root, value);
}

template<class T>
bool binarysearch_tree<T>::isEmpty() const
{
	return (m_root==NULL);
}

template<class T>
void binarysearch_tree<T>::printNode(const binarysearch_node *node)
{
	if (node == NULL)
		return;
	cout<<node->value<<' ';
	printNode(node->lchild);
	printNode(node->rchild);
}

template<class T>
void binarysearch_tree<T>::printTree() const
{
	printNode(m_root);
}

template<class T>
void binarysearch_tree<T>::freeNode(binarysearch_node *node)
{
	if (node==NULL)
		return;
	freeNode(node->lchild);
	freeNode(node->rchild);
	delete node;
}

template<class T>
void binarysearch_tree<T>::makeEmpty()
{
	freeNode(m_root);
	m_root = NULL;
}

template<class T>
void binarysearch_tree<T>::insertNode(binarysearch_node **node, const T& value)
{
	if (*node == NULL) {
		binarysearch_node *new_node = new binarysearch_node;
		new_node->value = value;
		new_node->lchild = NULL;
		new_node->rchild = NULL;
		*node = new_node;
		return;
	}
	if ((*node)->value < value)
		insertNode(&((*node)->rchild), value);
	if((*node)->value > value)
		insertNode(&((*node)->lchild), value);

	//插入重复的值不处理
}

template<class T>
void binarysearch_tree<T>::insert(const T& value)
{
	insertNode(&m_root, value);
}

template<class T>
void binarysearch_tree<T>::removeNode(binarysearch_node **node, const T& value)
{
	if((*node) == NULL)
		return;

	if ((*node)->value == value)
	{
		binarysearch_node *old_node = (*node);
		(*node) = old_node->lchild;
		binarysearch_node *tmp = *node;
		while (tmp->rchild) tmp = tmp->rchild;
		tmp->rchild = old_node->rchild;
		delete old_node;
	} else if((*node)->value > value) {
		
		removeNode(&((*node)->lchild), value);

	} else {
		removeNode(&((*node)->lchild), value);
	}
}

template<class T>
void binarysearch_tree<T>::remove(const T& value)
{
	removeNode(&m_root, value);
}

template<class T>
const binarysearch_tree<T>& binarysearch_tree<T>::operator=(const binarysearch_tree& rhs)
{
	if (this == &rhs)
		return *this;

	m_root = rhs.m_root;
	return *this;
}

