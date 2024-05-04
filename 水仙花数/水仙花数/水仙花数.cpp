#include<iostream>
using namespace std;

struct Node

{

	int data;

	Node* next;

};

Node* head; //全局变量 如果删除，函数不能直接访问，需要头指针作为参数传给函数才行

int N = 10000; //全局变量，控制数据数量

void Insert(int data) //尾插

{

	Node* temp1 = new Node;

	temp1->data = data;

	temp1->next = NULL;

	if (head == NULL)

	{

		head = temp1;

		return;

	}

	Node* temp2 = head;

	while (temp2->next != NULL)

	{

		temp2 = temp2->next;

	}

	temp2->next = temp1;

}

void Print() //打印链表

{

	//static int count = 0;

	Node* temp = head;

	cout << "Link is:";

	while (temp != NULL)

	{

		cout << temp->data << " ";

		temp = temp->next;

		//count++; //增加静态局部变量，记录循环次数

	}

	cout << endl;

}

void BubbleSort() //冒泡函数排序

{

	if (!head || !head->next)

		return;

	Node* temp = new Node;

	temp->next = head;

	Node* tail = NULL;

	while (tail != head) {

		Node* pre = temp;

		Node* cur = pre->next;

		Node* nxt = cur->next;

		while (nxt != tail)

		{

			if (nxt->data < cur->data)

			{

				pre->next = nxt;

				cur->next = nxt->next;

				nxt->next = cur;

			}

			else

			{

				cur = cur->next;

			}

			pre = pre->next;

			nxt = nxt->next;

		}

		tail = cur;

	}

	head = temp->next;

	temp = NULL;

	delete temp;

}

int main()

{

	for (int i = 0; i < N; i++)

	{

		int x = rand() % N;

		Insert(x);

	}

	Print();

	BubbleSort();

	cout << "-------------------After BubbleSort------------------------" << endl;

	Print();

	return 0;

}