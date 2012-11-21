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
	};
	binarysearch_node *m_root;

	bool findValue(const binarysearch_node *node, const T& value) const;
	void printNode(const binarysearch_node *node);
	void freeNode(binarysearch_node *node);
	void insertNode(binarysearch_node **node, const T& value);
	void removeNode(binarysearch_node **node, const T& value);
};

#endif