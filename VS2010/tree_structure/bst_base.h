#ifndef _BST_BASE_H_
#define _BST_BASE_H_

template<class T, class Node>
class bst_base {
public:
	bst_base();
	bst_base(const bst_base& rhs);
	~bst_base();

	const T& findMin() const;
	const T& findMax() const;
	bool contains(const T& value) const;
	bool isEmpty() const;
	void printTree() const;

	void makeEmpty();
	void insert(const T& value);
	void remove(const T& value);
	
	const bst_base& operator=(const bst_base& rhs);

private:
	Node *m_root;

	bool findValue(const Node *node, const T& value) const;
	void printNode(const Node *node) const;
	void freeNode(Node*& node);
	virtual void insertNode(Node*& node, const T& value) = 0;
	virtual void removeNode(Node*& node, const T& value) = 0;
	virtual void removeMin(Node*& node, T& value) = 0;
	virtual Node* cloneNode(const Node *node) = 0;
};

template<class T, class Node>
bst_base<T, Node>::bst_base() : m_root(NULL)
{

}

template<class T, class Node>
bst_base<T, Node>::bst_base(const bst_base& rhs)
{
	makeEmpty();
	cloneNode(rhs.m_root);
}

template<class T, class Node>
bst_base<T, Node>::~bst_base()
{
	makeEmpty();
}

template<class T, class Node>
const T& bst_base<T, Node>::findMin() const
{
	Node *tmp = m_root;
	while(tmp->lchild) tmp = tmp->lchild;
	return tmp->value;
}

template<class T, class Node>
const T& bst_base<T, Node>::findMax() const
{
	Node *tmp = m_root;
	while(tmp->rchild) tmp = tmp->rchild;
	return tmp->value;
}

template<class T, class Node>
bool bst_base<T, Node>::findValue(const Node *node, const T& value) const
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

template<class T, class Node>
bool bst_base<T, Node>::contains(const T& value) const
{
	return findValue(m_root, value);
}

template<class T, class Node>
bool bst_base<T, Node>::isEmpty() const
{
	return (m_root==NULL);
}

template<class T, class Node>
void bst_base<T, Node>::printNode(const Node *node) const
{
	if (node == NULL)
		return;
	cout<<node->value<<' ';
	printNode(node->lchild);
	printNode(node->rchild);
}

template<class T, class Node>
void bst_base<T, Node>::printTree() const
{
	printNode(m_root);
}

template<class T, class Node>
void bst_base<T, Node>::freeNode(Node*& node)
{
	if (node==NULL)
		return;
	freeNode(node->lchild);
	freeNode(node->rchild);
	delete node;
	node = NULL;
}

template<class T, class Node>
void bst_base<T, Node>::makeEmpty()
{
	freeNode(m_root);
}

template<class T, class Node>
void bst_base<T, Node>::insert(const T& value)
{
	insertNode(m_root, value);
}

template<class T, class Node>
void bst_base<T, Node>::remove(const T& value)
{
	removeNode(m_root, value);
}

template<class T, class Node>
const bst_base<T, Node>& bst_base<T, Node>::operator=(const bst_base& rhs)
{
	if (this == &rhs)
		return *this;
	makeEmpty();
	cloneNode(rhs.m_root);
	return *this;
}

#endif