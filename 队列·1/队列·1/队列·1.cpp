#include <queue>
#include <iostream>
using namespace std;
void out_number(int n) {
    int s1, s2;
    queue<int> q;
    q.push(1); 
    for (int i = 1; i <= n; i++) {
       s1 = 0; 
        for (int j = 0; j < i; j++) {
            s2 = q.front(); q.pop(); 
            cout << s2 << " "; 
            int sum = s1 + s2; 
            q.push(sum); 
            s1 = s2; 
        }
        q.push(1); 
        cout << endl; 
    }
}
int main() {
    int n;
    cin >> n;
	out_number(n);
}
//#include <iostream>
//using namespace std;
//const int maxlen = 100;
//class queue {
//private:
//    int count;
//    int front, rear;
//    int data[maxlen];
//public:
//    queue();
//    bool empty();
//    bool full();
//    bool get_front(int& x);
//    bool append(const int n);
//    bool serve();
//
//
//};
//queue::queue() {
//    count = 0;
//    front = rear = 0;
//}
//bool queue::empty() {
//    if (count == 0)return true;
//    else return false;
//}
//bool queue::full() {
//    if (count == maxlen - 1)return true;
//    else return false;
//}
//bool queue::get_front(int& x) {
//    if (empty())return 0;
//    x = data[(front + 1) % maxlen];
//    return true;
//}
//bool  queue::append(const int n) {
//    if (full())return false;
//    rear = (rear + 1) % maxlen;
//    data[rear] = n;
//    count++; return true;
//
//
//}
//bool queue::serve() {
//    if (empty())return 0;
//    front = (front + 1) % maxlen;
//    count--;
//
//}
//void out_number(int n) {
//    int s1, s2;
//    queue qu;
//    qu.append(1);
//    for (int i = 1; i <= n; i++) {
//        s1 = 0;
//        for (int j = 0; j < i; j++) {
//            int x = 1;
//            qu.get_front(x);
//            qu.serve();
//            s2 = x;
//            cout << s2 << " ";
//            qu.append(s1 + s2);
//            s1 = s2;
//        }
//        qu.append(1);
//        cout << endl;
//
//    }
//}
//
//int main() {
//    int n;
//    cout << "请输入需要输出的行数";
//    cin >> n;
//    out_number(n);
//}
