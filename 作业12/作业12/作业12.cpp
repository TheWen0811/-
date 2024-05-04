#include<iostream>
#include<string>
using namespace std;

template<typename T>
struct BuildTreeNode
{
	T data;
	bool ltag;
	bool rtag;
	BuildTreeNode<T>* Lson;
	BuildTreeNode<T>* Rson;
	BuildTreeNode<T>* father;
};

template<typename T>
class BuildTree
{
public:
	BuildTree();
	~BuildTree();
	void build();                //建树
	void erase();                //删除
	void ToPoClueBuildTree();              //转换为后序线索二叉树
	void PoTraversal();             //后序线索遍历
protected:
	void build(BuildTreeNode<T>*& father, BuildTreeNode<T>*& root);
	void erasebyRecursion(BuildTreeNode<T>*& root);
	void ToPoClueBuildTreeAssist(BuildTreeNode<T>*& root, string& str);   //转换函数的辅助函数
private:
	BuildTreeNode<T>* root;
	bool isclued;            //标记是否被线索化
	bool isbuilt;            //标记是否已建树
};

template<typename T>
BuildTree<T>::BuildTree()
{
	root = new BuildTreeNode<T>;
	isclued = false;
	isbuilt = false;
}

template<typename T>
BuildTree<T>::~BuildTree()
{
	this->erase();
}

\
template<typename T>
void BuildTree<T>::erase()
{
	if (isbuilt)
	{
		BuildTreeNode<T>* node = new BuildTreeNode<T>;
		while (root != NULL)
		{
			node = root;
			if (root->ltag) root = root->Lson;
			else
			{
				if (root->Rson != NULL && !node->rtag) root = root->Rson;
				else root = root->Lson;
			}
			delete node;
		}
	}
	else  this->erasebyRecursion(this->root);
	isbuilt = 0;
	isclued = 0;
	root = NULL;
}

template<typename T>
void BuildTree<T>::erasebyRecursion(BuildTreeNode<T>*& node)
{
	if (node == NULL) return;
	erasebyRecursion(node->Lson);
	erasebyRecursion(node->Rson);
	delete node;
}

template<typename T>
void BuildTree<T>::build()
{
	if (isbuilt)
	{
		cout << "The binary Tree has been built , if you want to rebuild , please erase it ! " << endl;
		return;
	}
	this->isbuilt = true;
	BuildTreeNode<T>* null = NULL;
	build(null, this->root);
}

template<typename T>
void BuildTree<T>::build(BuildTreeNode<T>*& father, BuildTreeNode<T>*& root)
{
	char ch = cin.get();
	if (ch == '.')
	{
		root = NULL;
		return;
	}
	root = new BuildTreeNode<T>;
	root->father = father;
	root->data = ch;
	root->ltag = false;
	root->rtag = false;
	build(root, root->Lson);
	build(root, root->Rson);
}

template<typename T>
void BuildTree<T>::ToPoClueBuildTreeAssist(BuildTreeNode<T>*& root, string& str)
{
	if (root->Lson != NULL) ToPoClueBuildTreeAssist(root->Lson, str += '0');
	if (root->Rson != NULL)    ToPoClueBuildTreeAssist(root->Rson, str += '1');
	if (root->Lson == NULL)
	{
		if (root->Rson != NULL)
		{
			root->ltag = true;
			root->Lson = root->Rson;
		}
		else
		{
			BuildTreeNode<T>* node = root;
			for (int i = str.size() - 1; i > 0; i--)
			{
				if (str[i] == '1')
				{
					root->ltag = true;
					if (node->father->Lson != NULL)
					{
						root->Lson = node->father->Lson;
						break;
					}
				}
				node = node->father;
			}
		}
	}
	if (root->Rson == NULL)
	{
		root->rtag = true;
		if (str[str.size() - 1] = '1') root->Rson = root->father;
		else
		{
			BuildTreeNode<T>* Node = root->father->Rson;
			if (Node == NULL) root->Rson = root->father;
			else
			{
				while (Node->Lson != NULL) { Node = Node->Lson; }
				root->Rson = Node;
			}
		}
	}
}

template<typename T>
void BuildTree<T>::ToPoClueBuildTree()
{
	if (isclued)
	{
		cout << "The binary Tree has been clued , your instruction is to be canceled ! " << endl;
		return;
	}
	this->isclued = true;
	string empty = "";
	ToPoClueBuildTreeAssist(this->root, empty);
}

template<typename T>
void BuildTree<T>::PoTraversal()
{
	string OppositeResult, Result;
	BuildTreeNode<T>* node = this->root;
	while (node != NULL)
	{
		OppositeResult += node->data;
		if (node->ltag) node = node->Lson;
		else
		{
			if (node->Rson != NULL && !node->rtag) node = node->Rson;
			else node = node->Lson;
		}
	}
	for (int i = OppositeResult.size() - 1; i >= 0; i--)  Result += OppositeResult[i];
	cout << "The result of postorder clue binary tree traversal is:" << Result << endl;
}

int main()
{
	BuildTree<char> tree;
	tree.build();
	tree.ToPoClueBuildTree();
	tree.PoTraversal();
	return 0;
}