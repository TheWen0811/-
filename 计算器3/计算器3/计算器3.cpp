#include<iostream>  
#include<stack>
#include<string>  
using namespace std;
bool isp(char n) {
    if (n >= '0' && n <= '9') return 1;
    return 0;
}
//判断自负优先级
int isr(char n) {
    if (n == '+' || n == '-'||n=='|'||n=='&'||n=='!')
        return 1;
    else if (n == '*' || n == '/')
        return 2;
    else if (n == '(' || n == ')')
        return 0;
    else
        return  -1;
}
//进行四则运算
int jisuan(char x, stack<int>& num) {
    int a, b;
    int c = 0;
    if (x == '+') {
        int a = num.top();
        num.pop();
        b = num.top();
        num.pop();
        c = a + b;
    }
    else if (x == '-') {
        a = num.top();
        num.pop();
        b = num.top();
        num.pop();
        c = b - a;
    }
    else if (x == '*') {
        a = num.top();
        num.pop();
        b = num.top();
        num.pop();
        c = a * b;
    }
    else if (x == '/') {
        a = num.top();
        num.pop();
        b = num.top();
        num.pop();
        c = b / a;
    }
    else if (x == '&') {
        a = num.top();
        num.pop();
        b = num.top();
        num.pop();
        c = b & a;
    }
    else if (x == '|') {
        a = num.top();
        num.pop();
        b = num.top();
        num.pop();
        c = b | a;
    }
    else if (x == '!') {
        a = num.top();
        num.pop();
        b = num.top();
        num.pop();
        c = b != a;
    }
    return c;
}
//字符转换为数字
int change(char x) {
    int y;
    y = x - 48;
    return y;
}

int calculator(string a) {
    //中缀表达式并求值
    stack<int> s1;
    stack<char> s2;
    a += '#';
    s2.push('#');
    for (int i = 0; i <= a.size()-1; i++) {
        if (isp(a[i])) {
            int sum = change(a[i]);
            while (isp(a[i+1])) {
                //处理多位数情况
                i++;
                sum = sum * 10 + change(a[i]);
            }
            s1.push(sum);
        }
        else {
            int k = 1;
            char x, y;
            x = s2.top();
            //循环处理运算符
            while (k) {
                if (isr(a[i]) > isr(x) || a[i] == '(') {
                    s2.push(a[i]);
                    break;
                }
                else {
                    if (isr(a[i]) == isr(x) && isr(a[i]) == 0 || isr(a[i]) == isr(x) && isr(a[i]) == -1) {
                        s2.pop();
                        break;
                    }
                    else {
                        s1.push(jisuan(x, s1));
                        s2.pop();
                        y = s2.top();
                        x = y;
                    }
                }
            }
        }
    }
    int p;
    p = s1.top();
    return p;
}

int main() {
    string a;
    cin >> a;
    cout << calculator(a) << endl;
    return 0;
}
