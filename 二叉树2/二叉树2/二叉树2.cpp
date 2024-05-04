#include<iostream>
using namespace std;
struct Tree {
	int data;					//	存放数据域
	struct Tree* lchild;			//	遍历左子树指针
	struct Tree* rchild;			//	遍历右子树指针

};
Tree* CreateLink()
{
	int data;
	int temp;
	Tree* T;
	cin >> data;	//	输入数据
	temp = getchar();			//	吸收空格

	if (data == -1) {			//	输入-1 代表此节点下子树不存数据，也就是不继续递归创建

		return NULL;

	}
	else {
		T = new Tree;			//		分配内存空间
		T->data = data;								//		把当前输入的数据存入当前节点指针的数据域中
		cout << "请输入" << data << "的左子树: ";
		T->lchild = CreateLink();					//		开始递归创建左子树
		cout << "请输入" << data << "的右子树: ";
		T->rchild = CreateLink();					//		开始到上一级节点的右边递归创建左右子树
		return T;							//		返回根节点
	}

}
void rode(Tree* T, static int& n)			//		先序遍历二叉树
{

	if (T == NULL)						//	递归中遇到NULL，返回上一层节点
	{
		n++;
		cout << "第" << n << "次到达根节点的下一个空地址" << endl;
		return;
	}
	//cout << T->data;
	rode(T->lchild, n);			//	递归遍历左子树
	rode(T->rchild, n);			//	递归遍历右子树
	
}
int maxrode(Tree* T)			//		先序遍历二叉树
{
	if (T == NULL) {
		return 0;
	}
	else {
		int left=maxrode(T->lchild);			//	递归遍历左子树
		int right=maxrode(T->rchild);			//	递归遍历右子树
		return max(left, right) + 1;
	}
}

int main()
{
	Tree* S;
	cout << "请输入第一个节点的数据" << endl;
	S = CreateLink();	//		接受创建二叉树完成的根节点
	int n = 0;
	rode(S, n);
	cout << "一共有" << n / 2 << "个路径" << endl;;//根节点的左右都为NULL，所以除以2
	int max=maxrode(S);
	cout << "最长路径为"<<max;
}
