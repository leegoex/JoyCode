#ifndef _BINARY_SEARCH_TREE_H_
#define _BINARY_SEARCH_TREE_H_

template<class T>
class binarysearch_tree {
public:
	binarysearch_tree();
	binarysearch_tree(const binarysearch_tree& rhs);
	~binarysearch_tree();

	const T& findMin() const;
	const T& findMax() const;
	bool contains(const T& value) const;
	bool isEmpty() const;
	void printTree() const;

	void makeEmpty();
	void insert(const T& value);
	void remove(const T& value);
	
	const binarysearch_tree& operator=(const binarysearch_tree& rhs);

private:
	struct binarysearch_node{
		T value;
		binarysearch_node *lchild;
		binarysearch_node *rchild;

		binarysearch_node(const T& v, binarysearch_node *l, binarysearch_node *r):value(v),lchild(l),rchild(r){}
	};
	binarysearch_node *m_root;

	bool findValue(const binarysearch_node *node, const T& value) const;
	void printNode(const binarysearch_node *node) const;
	void freeNode(binarysearch_node*& node);
	void insertNode(binarysearch_node*& node, const T& value);
	void removeNode(binarysearch_node*& node, const T& value);
	binarysearch_node* cloneNode(const binarysearch_node *node) {
		if (node==NULL)
			return NULL;
		return new binarysearch_node(node->value, cloneNode(node->lchild), cloneNode(node->rchild));
	}
};

template<class T>
binarysearch_tree<T>::binarysearch_tree() : m_root(NULL)
{

}

template<class T>
binarysearch_tree<T>::binarysearch_tree(const binarysearch_tree& rhs)
{
	makeEmpty();
	cloneNode(rhs.m_root);
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
void binarysearch_tree<T>::printNode(const binarysearch_node *node) const
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
void binarysearch_tree<T>::freeNode(binarysearch_node*& node)
{
	if (node==NULL)
		return;
	freeNode(node->lchild);
	freeNode(node->rchild);
	delete node;
	node = NULL;
}

template<class T>
void binarysearch_tree<T>::makeEmpty()
{
	freeNode(m_root);
}

template<class T>
void binarysearch_tree<T>::insertNode(binarysearch_node*& node, const T& value)
{
	if (node == NULL) {
		binarysearch_node *new_node = new binarysearch_node(value, NULL, NULL);
		node = new_node;
		return;
	}
	if (node->value < value)
		insertNode(node->rchild, value);
	if(node->value > value)
		insertNode(node->lchild, value);

	//插入重复的值不处理
}

template<class T>
void binarysearch_tree<T>::insert(const T& value)
{
	insertNode(m_root, value);
}

template<class T>
void binarysearch_tree<T>::removeNode(binarysearch_node*& node, const T& value)
{
	if(node == NULL)
		return;
	if (value < node->value) {
		removeNode(value, node->lchild);
	} else if(value >  node->value) {
		removeNode(value, node->rchild);
	} else if(node->lchild!=NULL && node->rchild!=NULL) {
		//找到右子树中的最小值，替换该节点
		//遍历删除该最小节点
	} else {
		binarysearch_node *old_value = node;
		node = (node->lchild != NULL)?node->lchild:node->rchild;
		delete node;
		node = NULL;
	}
}

template<class T>
void binarysearch_tree<T>::remove(const T& value)
{
	removeNode(m_root, value);
}

template<class T>
const binarysearch_tree<T>& binarysearch_tree<T>::operator=(const binarysearch_tree& rhs)
{
	if (this == &rhs)
		return *this;

	makeEmpty();
	cloneNode(rhs.m_root);
	return *this;
}

#endif