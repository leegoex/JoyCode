#ifndef _EXPRESSION_TREE_H_
#define _EXPRESSION_TREE_H_

#include <string>
using namespace std;

//根据后缀表达式生成一个表达式树
struct BinaryNode{
	char c;
	BinaryNode *lchild;
	BinaryNode *rchild;
};

class expression_tree {
public:
	expression_tree(const string& expr);
	~expression_tree();

	void build_tree();
	void destroy_tree();

	void printTreePreorder();
	void printTreePostorder();
	void printTreeInorder();

protected:
	void print_preorder(BinaryNode *node);
	void print_postorder(BinaryNode *node);
	void print_inorder(BinaryNode *node);
	void free_tree(BinaryNode *node);

private:
	string m_expr;
	BinaryNode *m_root;
};

#endif