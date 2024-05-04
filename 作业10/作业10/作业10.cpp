#include <iostream>
#include <queue>
using namespace std;
//二叉树节点定义
typedef struct Tree//二叉树的结点数据结构
{
	int data;
	Tree* lchild, * rchild;
};

Tree* CreateTree(int* a, int n, int start)//*a为data，n为数组长度，start为根节点
{
	if (a[start] == -1)return NULL;//当根节点为空，即空树

	Tree* root = new Tree;//新建一个根结点
	root->data = a[start];//给根结点root的成员变量data,lchild,rchild赋初值
	root->lchild = NULL;
	root->rchild = NULL;

	int lnode = 2 * start + 1;//用根节点确定左节点的位置
	int rnode = 2 * start + 2;//用根节点确定右节点的位置

	if (lnode > n - 1) root->lchild = NULL;
	else root->lchild = CreateTree(a, n, lnode);//lnode替换start，为左子树的根节点

	if (rnode > n - 1) root->rchild = NULL;
	else root->rchild = CreateTree(a, n, rnode);//rnode替换start，为右子树的根节点

	return root;
}
void ShowXianxu(Tree *T)
{
	if (T) {
		cout << T->data << " ";
		ShowXianxu(T->lchild);
		ShowXianxu(T->rchild);
	}
}
//	中序遍历
void ShowZhongXu(Tree* T)			//		先序遍历二叉树
{
	if (T == NULL)						//	递归中遇到NULL，返回上一层节点
	{
		return;
	}

	ShowZhongXu(T->lchild);			//	递归遍历左子树
	cout << T->data<<" ";
	ShowZhongXu(T->rchild);			//	递归遍历右子树

}
//	后序遍历
void ShowHouXu(Tree* T)			//		后序遍历二叉树
{
	if (T == NULL)						//	递归中遇到NULL，返回上一层节点
	{
		return;
	}

	ShowHouXu(T->lchild);			//	递归遍历左子树
	ShowHouXu(T->rchild);			//	递归遍历右子树
	cout << T->data<<" ";
}


int maxrode(Tree* T)			//		先序遍历二叉树
{
	if (T == NULL) {
		return 0;
	}
	else {
		int left = maxrode(T->lchild);			//	递归遍历左子树
		int right = maxrode(T->rchild);			//	递归遍历右子树
		return max(left, right) + 1;
	}
}
void test() {
	Tree* t;
	int data[] = { 1, 2, 3, 4, 5, -1, 6, 7 };
	//前序遍历：1 2 4 7 5 3 6
	t = CreateTree(data, sizeof(data) / sizeof(data[0]), 0);
	cout << "先序遍历";
	ShowXianxu(t); cout << endl;
	cout << "中序遍历";
	ShowZhongXu(t); cout << endl;
	cout << "后序遍历";
	ShowHouXu(t); cout << endl;
	int max=maxrode(t);
	cout << max;
}
	
int main()
{
	test();
	return 0;
}


