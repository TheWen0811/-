#include <iostream>
#include<stack>
#include<string>
using namespace std;
void calculator(string str) {
	string::iterator it = str.begin();//迭代器
	stack<char> s1;//s1是用来存放运算符的栈
	stack<int> s2;//s3是用来存放数字的栈
	while (it != str.end()) {
		//运算符优先级：) > *、/、% > +、- > ( 且 ( 特例，直接入栈
		if (*it == '+' || *it == '-' || *it == '*' || *it == '/' || *it == '%' || *it == '(') {
			//当遇到栈顶为 *、/、% 读取的字符为 +、- 时，即读取的运算符优先级低于符号栈顶元素优先级 
			//或
			//当遇到栈顶为 *、/、% 读取的字符为*、/、%时，即读取的运算符优先级等于符号栈顶元素优先级时
			if (!s1.empty() && (s1.top() == '*' || s1.top() == '/' || s1.top() == '%') && *it != '(') {//注意这里要加上栈判空，否则会导致开始的时候出错
				int num2 = s2.top();
				s2.pop();
				int num1 = s2.top();
				s2.pop();
				if (s1.top() == '*') {
					s2.push(num1 * num2);
				}
				else if (s1.top() == '/') {
					s2.push(num1 / num2);
				}
				else {
					s2.push(num1 % num2);
				}
				s1.pop();
				s1.push(*it);
			}
			//当遇到栈顶为 +、- 读取的字符为 +、- 时，即读取的运算符优先级等于符号栈顶元素优先级
			else if (!s1.empty() && (s1.top() == '+' || s1.top() == '-') && (*it == '+' || *it == '-')) {//注意这里要在前面加栈的判空，否则会导致开始的时候出错
				int num2 = s2.top();
				s2.pop();
				int num1 = s2.top();
				s2.pop();
				if (s1.top() == '+') {
					s2.push(num1 + num2);
				}
				else {
					s2.push(num1 - num2);
				}
				s1.pop();
				s1.push(*it);
			}
			//当遇到栈顶为 +、- 读取的字符为 *、/、% 时，即读取的运算符优先级高于符号栈顶元素优先级
			//或
			//当遇到栈顶为 ( 读取的字符为 +、-、 *、/、% 时，即读取的运算符优先级高于符号栈顶元素优先级
			//或
			//读取的字符为 ( 时
			else {
				s1.push(*it);
			}
		}
		else if (*it == ')') {//匹配到右括号
			while (s1.top() != '(') {
				int num2 = s2.top();
				s2.pop();
				int num1 = s2.top();
				s2.pop();
				if (s1.top() == '+') {
					s2.push(num1 + num2);
				}
				else if (s1.top() == '-') {
					s2.push(num1 - num2);
				}
				else if (s1.top() == '*') {
					s2.push(num1 * num2);
				}
				else if (s1.top() == '/') {
					s2.push(num1 / num2);
				}
				else {
					s2.push(num1 % num2);
				}
				s1.pop();
			}
			s1.pop();
		}
		else {//匹配到数字
			s2.push((int)(*it - '0'));//转换为整型
		}
		it++;
	}

	//处理最后两个数字
	int num2 = s2.top();
	s2.pop();
	int num1 = s2.top();
	s2.pop();
	if (s1.top() == '+') {
		s2.push(num1 + num2);
	}
	else if (s1.top() == '-') {
		s2.push(num1 - num2);
	}
	else if (s1.top() == '*') {
		s2.push(num1 * num2);
	}
	else if (s1.top() == '/') {
		s2.push(num1 / num2);
	}
	else {
		s2.push(num1 % num2);
	}
	cout << s2.top() << endl;
}
int main() {
	string str;
	cin >> str;
	calculator(str);
}