#include <iostream>
#include "expression_tree.h"
using namespace std;

struct TreeNode{
	char c;
	TreeNode *firstChild;
	TreeNode *nextSibling;
};

//前序遍历：对结点的处理工作是在它的诸儿子结点被处理之前进行的
void printTreePreorder(TreeNode *t)
{
	if (t == NULL)
		return;
	cout<<t->c<<' ';
	TreeNode *tmp = t->firstChild;
	while (tmp)
	{
		printTreePreorder(tmp);
		tmp = tmp->nextSibling;
	}
}

//后续遍历：对结点的处理工作是在它的诸儿子结点被处理之后进行的
void printTreePostorder(TreeNode *t)
{
	if (t == NULL)
		return;
	TreeNode *tmp = t->firstChild;
	while(tmp)
	{
		printTreePostorder(tmp);
		tmp = tmp->nextSibling;
	}
	cout<<t->c<<' ';
}

int main(int argc, char *argv[])
{
	//初始化
	TreeNode n_a = {'a', NULL, NULL};
	TreeNode n_b = {'b', NULL, NULL};
	TreeNode n_c = {'c', NULL, NULL};
	TreeNode n_d = {'d', NULL, NULL};
	TreeNode n_e = {'e', NULL, NULL};
	TreeNode n_f = {'f', NULL, NULL};
	TreeNode n_g = {'g', NULL, NULL};
	TreeNode n_h = {'h', NULL, NULL};
	TreeNode n_i = {'i', NULL, NULL};
	TreeNode n_j = {'j', NULL, NULL};
	TreeNode n_k = {'k', NULL, NULL};
	TreeNode n_l = {'l', NULL, NULL};
	TreeNode n_m = {'m', NULL, NULL};
	TreeNode n_n = {'n', NULL, NULL};
	TreeNode n_o = {'o', NULL, NULL};
	TreeNode n_p = {'p', NULL, NULL};
	TreeNode n_q = {'q', NULL, NULL};

	//构造一棵树
	n_a.firstChild = &n_b;
	n_b.nextSibling = &n_c;
	n_c.nextSibling = &n_d;
	n_d.firstChild = &n_h;
	n_d.nextSibling = &n_e;
	n_e.firstChild = &n_i;
	n_e.nextSibling = &n_f;
	n_f.firstChild = &n_k;
	n_f.nextSibling = &n_g;
	n_g.firstChild = &n_n;
	n_i.nextSibling = &n_j;
	n_j.firstChild = &n_p;
	n_k.nextSibling = &n_l;
	n_l.nextSibling = &n_m;
	n_p.nextSibling = &n_q;

	//前序遍历
	cout<<"Preorder traversal:"<<endl;
	printTreePreorder(&n_a);
	cout<<endl;

	//后续遍历
	cout<<"Postorder traversal:"<<endl;
	printTreePostorder(&n_a);
	cout<<endl;

	//二叉树应用-表达式树
	char expr[1024] = {0};
	cout<<"Please enter a suffix expression:\n";
	cin>>expr;
	expression_tree exprTree(expr);
	exprTree.build_tree();
	exprTree.printTreePostorder();
	exprTree.destroy_tree();
	cout<<endl;

	system("pause");

	return 0;
}