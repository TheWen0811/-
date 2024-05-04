#include<iostream>
using namespace std;
template<class T>//结点(类模板)
class Node
{
public:
    T data;//该结点数据域
    Node<T>* next;//后继结点指针域
    Node<T>* prior;//前驱结点指针域
};
template<class T>
class Double_LoopLinkList
{
private:
    Node<T>* head;//头结点
public:
    Double_LoopLinkList();//构造函数
    void CreateList();//创建双循环链表
    ~Double_LoopLinkList();//析构函数
    int Length();//求双循环链表的长度
    bool Insert(int index, T data);//在序号index位置插入元素值为data的结点
    bool PrintList();//输出双循环链表所有结点的元素值
    void ReverseDouble_LoopList(Double_LoopLinkList<T>& L);//实现双循环链表的翻转
};
template<class T>
Double_LoopLinkList<T>::Double_LoopLinkList()//初始化为空双循环链表
{
    head = new Node<T>;
    head->data = 0;
    head->prior = NULL;
    head->next = head;
}
template<class T>
void Double_LoopLinkList<T>::CreateList()
{
    int length;
    T data;
    cout << "正在创建双循环链表(尾插),请输入你要创建的双循环链表的长度" << endl;
    cin >> length;
    for (int i = 0; i < length; i++)
    {
        cout << "请输入第" << i + 1 << "个结点的元素值:";
        cin >> data;
        Insert(Length() + 1, data);//采用尾插方式进行创建单链表
    }
}
template<class T>
bool Double_LoopLinkList<T>::Insert(int index, T data)
{
    Node<T>* p = head, * s;
    if (index <= 0)
    {
        cout << "插入位置不合法，请输入为正数的插入位置" << endl;
        return false;
    }
    if (index > Length())//所插位置超出单链表长度时
    {
        while (p->next != head)
        {
            p = p->next;
        }
        //此时指针p指向终端结点
        s = new Node<T>;
        s->data = data;//给予数据
        p->next = s;//s成为p的后继结点
        s->prior = p;//p成为s的前驱结点
        s->next = head;//s成为终端结点,并指向头结点
        head->prior = s;//s成为头结点的前驱结点
        //进行双循环链表的插入;
    }
    else//所插位置位于链表长度内时
    {

        for (int i = 0; i < index - 1; i++)
        {
            p = p->next;
        }
        //此时指针p指向第index-1个结点
        s = new Node<T>;
        s->data = data;
        s->prior = p;
        s->next = p->next;
        p->next->prior = s;
        p->next = s;
        //进行双循环链表的插入
        cout << "已成功插入结点n(*≧▽≦*)n" << endl;
        return true;
    }
}
template<class T>
int Double_LoopLinkList<T>::Length()
{
    Node<T>* p = head;
    int num = 0;//累加器
    while (p->next != head)
    {
        num++;
        p = p->next;
    }
    return num;
}
template<class T>
Double_LoopLinkList<T>::~Double_LoopLinkList()//销毁双循环链表
{
    Node<T>* p = head->next;
    Node<T>* s = NULL;
    while (p != head)
    {
        s = p;
        p = p->next;
        delete s;
    }
    delete p;
    delete head;
    cout << "单链表销毁成功╭(╯^╰)╮" << endl;
}

template<class T>
bool Double_LoopLinkList<T>::PrintList()
{
    int i = 1;
    Node<T>* p = head;
    if (p->next == head)
    {
        cout << "该双循环链表为空链表!" << endl;
        return false;
    }
    else
    {
        while (p->next != head)
        {
            p = p->next;
            cout << "第" << i << "个结点的元素值为:" << p->data << endl;
            cout << "第" << i << "个结点的地址为:" << &(p->data) << endl;
            i++;
        }
        cout << "成功输出结点元素值!" << endl;
        return true;
    }
}

template<class T>
void Double_LoopLinkList<T>::ReverseDouble_LoopList(Double_LoopLinkList<T>& L)
{
        Node<T>* p = head->next,
            * q = head->prior;
        while (q != p && p->prior != q)
        {
            //交换两节点的数据元素
            int *t; t = &(p->data);
            &(p->data) = &(q->data);
            &(q->data )= t;
            //p指针从头到尾遍历，q指针从尾到头遍历
            p = p->next;
            q = q->prior;
        }
    }
int main()
{
    Double_LoopLinkList<int> list;
    list.CreateList();
    list.PrintList();
    list.ReverseDouble_LoopList(list);
    list.PrintList();
}