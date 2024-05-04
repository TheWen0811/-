#include<iostream>
#include<queue>
using namespace std;
struct ChildBrotherTree {
	int data;					//	存放数据域
	struct ChildBrotherTree* firstChild;			//	遍历孩子指针
	struct ChildBrotherTree* nextSilbling;			//	遍历兄弟指针

};
ChildBrotherTree* CreateLink()
{
	int data;
	int temp;
	ChildBrotherTree* T;
	cin >> data;	//	输入数据
	temp = getchar();			//	吸收空格

	if (data == -1) {			//	输入-1 代表此节点下子树不存数据，也就是不继续递归创建

		return NULL;

	}
	else {
		T = new ChildBrotherTree;			//		分配内存空间
		T->data = data;								//		把当前输入的数据存入当前节点指针的数据域中
		cout << "请输入" << data << "的孩子: ";
		T->firstChild = CreateLink();					//		开始递归创建孩子树
		cout << "请输入" << data << "的兄弟: ";
		T->nextSilbling = CreateLink();					//		开始到上一级节点的右边递归创建兄弟树
		return T;							//		返回根节点
	}

}
int maxrode(ChildBrotherTree* T)			//		先序遍历二叉树
{
	if (T == NULL) {
		return 0;
	}
	else {
		int left = maxrode(T->firstChild);			
		int right = maxrode(T->nextSilbling);			
		return max(left, right) + 1;
	}
}
int GetDepth(ChildBrotherTree* root)
{
	int depth = 0;
	ChildBrotherTree* p = root;
	queue<ChildBrotherTree*> q;
	q.push(p);  //根指针入队
	while (!q.empty())
	{
		depth++;  //高度加一
		int width = q.size();  //获取当前层次宽度
		for (int i = 0; i < width; i++)
		{
			p = q.front();  //获取队顶元素
			q.pop();  //弹出队顶元素
			if (p->firstChild != NULL)  //孩子入队
				q.push(p->firstChild);
			if (p->nextSilbling != NULL)  //兄弟入队
				q.push(p->nextSilbling);
		}

	}
	return depth;
}

int main()
{
	ChildBrotherTree* S;
	printf("请输入第一个节点的数据:\n");
	S = CreateLink();			//		接受创建树完成的根节点
	int a=maxrode(S);
	int b = GetDepth(S);
	cout << a<<" "<<b;
	
}
//层序遍历和递归遍历在处理树时的时间复杂度都是 O(n),但递归遍历的空间复杂度更小，适用于处理大型树。
