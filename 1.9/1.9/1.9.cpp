#include <iostream>
using namespace std;
typedef struct Node {
	int data;//数据域
	struct Node* pNext;//指针域
}NODE, * PNODE;
//NODE单价于struct Node,PNODE等价于struct Node *
PNODE create_list(void);
void traverse_list(PNODE pHead);
bool is_emty(PNODE pHead);
int length_list(PNODE);
bool insert_list(PNODE, int, int);
bool delete_list(PNODE, int, int*);
void sort_list(PNODE) ; 


int main()
{
	PNODE pHead = NULL;//等价于struct Node *pHead=NULL
	int val;
	pHead = create_list();//create_list()功能：创建一个非循环单链表，并将该链表的头结点的地址赋给pHead 
	traverse_list(pHead);
	int len = length_list(pHead);
	cout << "链表长度是" << len;
	if (is_emty(pHead))
		cout << "链表为空";
	else cout << "链表不空";
	cout << "排序后";
	sort_list(pHead);
	traverse_list(pHead);
	cout << "插入后";
	insert_list(pHead, 4, 33);
	traverse_list(pHead);
	if (delete_list(pHead, 4, &val)) {
		cout << "删除成功";
	}
	traverse_list(pHead);

}
PNODE create_list() {
	int len;
	int val;//用来临时存放用户输入节点的值 
	PNODE pHead = (PNODE)malloc(sizeof(NODE));
	if (NULL == pHead) {
		cout << "分配失败";
		exit(-1);
	}
	PNODE pTail = pHead;
	pTail->pNext = NULL;
	cout << "输入链表节点的个数";
	cin >> len;
	int i;
	for (i = 0; i < len; ++i) {
		cout << "请输入第" << i + 1 << "个节点的值";
		cin >> val;
		PNODE pNew = (PNODE)malloc(sizeof(NODE));
		if (NULL == pNew) {
			cout << "分配失败";
			exit(-1);
		}
		pNew->data = val;
		pTail->pNext = pNew;
		pNew->pNext = NULL;
		pTail = pNew;

	}
	return pHead;
}
void traverse_list(PNODE pHead) {
	PNODE p = pHead->pNext;
	while (NULL != p) {
		cout << p->data<<" ";
		p = p->pNext;
	}
}
bool is_emty(PNODE pHead) {
	if (NULL == pHead->pNext)
		return true;
	else return false; 
}
int length_list(PNODE pHead) {
	PNODE p = pHead->pNext;
	int len = 0;
	while (NULL != p) {
		len++;
		p = p->pNext;
	}return  len;
}
void sort_list(PNODE pHead) {
	int i, j, t;
	PNODE p, q;
	int len = length_list(pHead);
	for (i = 0, p = pHead->pNext; i < len - 1; i++, p = p->pNext) {
		for (j = i + 1, q = p->pNext; j < len; j++, q = q->pNext) {
			if (p->data > q->data) {
				t = p->data;
				p->data = q->data;
				q->data = t;
			}
		}
	}
}
	bool insert_list(PNODE pHead, int pos, int val) 
	{
		int i = 0;
		PNODE p = pHead;
		while (NULL != p && i < pos - 1) {
			p = p->pNext;
			i++;
		}
		if (i > pos - 1 || NULL == p)
			return false;
		PNODE pNew = (PNODE)malloc(sizeof(NODE));
		
			if (NULL == pNew) {
				cout << "动态内存分配失败";
				exit(-1);
			}
			pNew->data = val;
			PNODE q = p->pNext;
			p->pNext = pNew;
			pNew->pNext = q;
}
	bool delete_list(PNODE pHead, int pos, int*pval) {
		int i = 0;
		PNODE p = pHead;
		while (NULL != p->pNext && i < pos - 1) {
			p = p->pNext;
			i++;
		}
		if (i > pos - 1 || NULL == p->pNext)
			return false;
		PNODE q = p->pNext;
		*pval = q->data;
		//删除p节点后的节点
		p->pNext = p->pNext->pNext;
		free(q);
		q = NULL;
		return true;
		}
		

	

