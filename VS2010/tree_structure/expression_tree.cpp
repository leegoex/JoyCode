#include "expression_tree.h"
#include <iostream>
#include <stack>
using namespace std;

static string op = "+-*/%";

expression_tree::expression_tree(const string& expr) : m_expr(expr), m_root(NULL)
{

}

expression_tree::~expression_tree()
{
	free_tree(m_root);
}

void expression_tree::build_tree()
{
	if (m_expr.length()==0)
		return;

	stack<BinaryNode*> nodes;
	string::const_iterator it = m_expr.begin();
	for (; it!=m_expr.end(); ++it)
	{
		BinaryNode *new_node = new BinaryNode;
		new_node->c = *it;
		new_node->lchild = NULL;
		new_node->rchild = NULL;

		if(op.find(*it) != string::npos) { //操作符
			if (nodes.size()<2)
			{
				cout<<"Build error! The expression is not a suffix expression!\n";
				break;
			}
			//先出的结点为右孩子结点
			new_node->rchild = nodes.top();
			nodes.pop();
			new_node->lchild = nodes.top();
			nodes.pop();
		} 
		//将该结点入栈
		nodes.push(new_node);
	}
	m_root = nodes.top();
}

void expression_tree::destroy_tree()
{
	free_tree(m_root);
	m_root = NULL;
}

void expression_tree::print_preorder(BinaryNode *node)
{
	if (node == NULL)
		return;
	cout<<node->c<<' ';
	print_preorder(node->lchild);
	print_preorder(node->rchild);
}

void expression_tree::printTreePreorder()
{
	print_preorder(m_root);
}

void expression_tree::print_postorder(BinaryNode *node)
{
	if (node == NULL)
		return;
	print_postorder(node->lchild);
	print_postorder(node->rchild);
	cout<<node->c<<' ';
}

void expression_tree::printTreePostorder()
{
	print_postorder(m_root);
}

void expression_tree::print_inorder(BinaryNode *node)
{
	if (node == NULL)
		return;
	print_inorder(node->lchild);
	cout<<node->c<<' ';
	print_inorder(node->rchild);
}

void expression_tree::printTreeInorder()
{
	print_inorder(m_root);
}

void expression_tree::free_tree(BinaryNode *node)
{
	if (node==NULL)
		return;
	free_tree(node->lchild);
	free_tree(node->rchild);
	delete node;
}