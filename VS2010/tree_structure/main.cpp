#include <iostream>
#include "expression_tree.h"
#include "bst_tree.h"
#include "avl_tree.h"
#include "trace.h"
using namespace std;

template <typename T>
struct TreeNode{
	T c;
	TreeNode *firstChild;
	TreeNode *nextSibling;
};

//前序遍历：对结点的处理工作是在它的诸儿子结点被处理之前进行的
template <typename T>
void printTreePreorder(TreeNode<T> *t)
{
	if (t == NULL)
		return;
	cout<<t->c<<' ';
	TreeNode<T> *tmp = t->firstChild;
	while (tmp)
	{
		printTreePreorder(tmp);
		tmp = tmp->nextSibling;
	}
}

//后续遍历：对结点的处理工作是在它的诸儿子结点被处理之后进行的
template <typename T>
void printTreePostorder(TreeNode<T> *t)
{
	if (t == NULL)
		return;
	TreeNode<T> *tmp = t->firstChild;
	while(tmp)
	{
		printTreePostorder(tmp);
		tmp = tmp->nextSibling;
	}
	cout<<t->c<<' ';
}


int main(int argc, char *argv[])
{
	srand(time(NULL));
	int arr[] = {5, 12, 7, 4, 16, 9};
	int size = sizeof(arr)/sizeof(int);
	//srand((unsigned int)time(NULL));
	//bst_tree<int, bst_node<int>> btree;
	avl_tree<int, avl_node<int>> btree;
	int i = 0;
	int temp[100];
	for (i = 0; i < 100; i++) {
		temp[i] = rand();
		btree.insert(temp[i]);
	}
	cout<<btree.findMin()<<endl;
	cout<<btree.findMax()<<endl;
// 	cout<<btree.isEmpty()<<endl;
// 	cout<<btree.contains(19)<<endl;
// 	cout<<btree.contains(12)<<endl;
	btree.printTree();
	for (i = 0; i < 100; i++)
	{
		btree.remove(temp[i]);
		btree.printTree();
		cout<<endl;
	}
	cout<<btree.isEmpty()<<endl;
	
	cout<<"\n***********************************************\n";

	//初始化
	TreeNode<char> n_a = {'a', NULL, NULL};
	TreeNode<char> n_b = {'b', NULL, NULL};
	TreeNode<char> n_c = {'c', NULL, NULL};
	TreeNode<char> n_d = {'d', NULL, NULL};
	TreeNode<char> n_e = {'e', NULL, NULL};
	TreeNode<char> n_f = {'f', NULL, NULL};
	TreeNode<char> n_g = {'g', NULL, NULL};
	TreeNode<char> n_h = {'h', NULL, NULL};
	TreeNode<char> n_i = {'i', NULL, NULL};
	TreeNode<char> n_j = {'j', NULL, NULL};
	TreeNode<char> n_k = {'k', NULL, NULL};
	TreeNode<char> n_l = {'l', NULL, NULL};
	TreeNode<char> n_m = {'m', NULL, NULL};
	TreeNode<char> n_n = {'n', NULL, NULL};
	TreeNode<char> n_o = {'o', NULL, NULL};
	TreeNode<char> n_p = {'p', NULL, NULL};
	TreeNode<char> n_q = {'q', NULL, NULL};

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