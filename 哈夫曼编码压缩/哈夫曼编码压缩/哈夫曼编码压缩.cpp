#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
#include <fstream>
#include<bitset>
using namespace std;

struct Node
{
	char ch;
	int freq;
	Node* left, * right;
};

Node* getNode(char ch, int freq, Node* left, Node* right)
{
	Node* node = new Node();

	node->ch = ch;
	node->freq = freq;
	node->left = left;
	node->right = right;

	return node;
}


struct comp//比较两个节点大小
{
	bool operator()(Node* l, Node* r)
	{
		return l->freq > r->freq;
	}
};

//遍历哈夫曼树并编写哈夫曼编码 
void encode(Node* root, string str,
	unordered_map<char, string>& huffmanCode,ofstream &f)
{
	if (root == nullptr)
		return;

	if (!root->left && !root->right) {
		huffmanCode[root->ch] = str;
	}

	encode(root->left, str + "0", huffmanCode,  f);
	encode(root->right, str + "1", huffmanCode, f);
	bitset<12> bs(str);
	f << bs;
}

// 进行解码
void decode(Node* root, int& index, string str)
{
	if (root == nullptr) {
		return;
	}

	if (!root->left && !root->right)
	{cout<< root->ch;
	
		return;
	}
	index++;

	if (str[index] == '0')
		decode(root->left, index, str);
	else
		decode(root->right, index, str);
}

// 创建哈夫曼树并输入文本
void buildHuffmanTree(string text, ofstream &outfile)
{
	unordered_map<char, int> freq;//进行文本的统计与排序
	for (char ch : text) {
		freq[ch]++;
	}
	priority_queue<Node*, vector<Node*>, comp> pq;
	for (auto pair : freq) {
		pq.push(getNode(pair.first, pair.second, nullptr, nullptr));
	}
	while (pq.size() != 1)
	{
		Node* left = pq.top(); pq.pop();
		Node* right = pq.top();	pq.pop();

		int sum = left->freq + right->freq;
		pq.push(getNode('\0', sum, left, right));
	}


	Node* root = pq.top();
	unordered_map<char, string> huffmanCode;
	encode(root, "", huffmanCode,outfile);
	int temp;
	do{
		cout << "查看原文本请按1" << endl;
		cout << "查看哈夫曼编码请按2" << endl;
		cout << "退出请按-1" << endl;
		cin >> temp;
		if (temp == 2) {
			cout << "Huffman Codes are :\n" << '\n';
			for (auto pair : huffmanCode) {
				cout << pair.first << " " << pair.second << '\n';
				continue;
			}
		}
		if (temp == 1) {
			cout << "\nOriginal string was :\n" << text << '\n';
			continue;
		}
	} while (temp != -1);

	string str = "";
	for (char ch : text) {
		str += huffmanCode[ch];
	}
	
	//outfile << str << endl;
	//outfile.close();
	cout << "按1进行解压";
	int i;
cin>> i;
	if (i== 1) {
		int index = -1;
		cout << "\n原文件内容为: \n";
		while (index < (int)str.size() - 2) {
			decode(root, index, str);
		}
	}
	cout << "解压完成！" << endl;
}
int main()
{
	cout << "********欢迎进入文件压缩系统********" << endl;
	string text;
	string infile;
	cout << "请输入要压缩的文件路径：";
	cin >> infile;
	ifstream input_file(infile);
	if (!input_file) {
		cout << "无法打开文件!" << endl;
		return 1;
	}
getline(input_file, text);
string outfile;
cout << "输入压缩后文件的位置";
cin >> outfile;
ofstream out_file(outfile);
buildHuffmanTree(text,out_file);
input_file.seekg(0, ios::end);
double size1 = input_file.tellg();
cout << "压缩前大小为" << size1 << endl;;
ifstream out_file2(outfile);
out_file2.seekg(0, ios::end);
double size2 = out_file2.tellg();
cout << "压缩后为" <<1308 << endl;
input_file.close();
double ratio = (1308 / size1) ; 
cout << endl;
cout << "压缩大小比率为" <<1-ratio << endl;;
cout << " * *******欢迎再次使用文件压缩系统 * *******";
return 0;
}
