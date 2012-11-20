#include <iostream>
#include "expression_tree.h"
using namespace std;

struct TreeNode{
	char c;
	TreeNode *firstChild;
	TreeNode *nextSibling;
};

//ǰ��������Խ��Ĵ�����������������ӽ�㱻����֮ǰ���е�
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

//�����������Խ��Ĵ�����������������ӽ�㱻����֮����е�
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
	//��ʼ��
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

	//����һ����
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

	//ǰ�����
	cout<<"Preorder traversal:"<<endl;
	printTreePreorder(&n_a);
	cout<<endl;

	//��������
	cout<<"Postorder traversal:"<<endl;
	printTreePostorder(&n_a);
	cout<<endl;

	//������Ӧ��-���ʽ��
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