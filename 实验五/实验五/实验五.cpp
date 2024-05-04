#include<iostream>
using namespace std;
#include <unordered_set>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};
class LinkedList {
private:
    ListNode* head;

public:
    LinkedList() : head(nullptr) {}

    void insert(int val) {
        ListNode* newNode = new ListNode(val);
        newNode->next = head;
        head = newNode;
    }

    LinkedList operator+(const LinkedList& other) const {
        LinkedList result;
        unordered_set<int> set;
        ListNode* p = head;
        while (p != nullptr) {
            set.insert(p->val);
            p = p->next;
        }
        p = other.head;
        while (p != nullptr) {
            set.insert(p->val);
            p = p->next;
        }
        for (int val : set) {
            result.insert(val);
        }
        return result;
    }

    LinkedList operator*(const LinkedList& other) const {
        LinkedList result;
        unordered_set<int> set;
        ListNode* p = head;
        while (p != nullptr) {
            set.insert(p->val);
            p = p->next;
        }
        p = other.head;
        while (p != nullptr) {
            if (set.count(p->val) > 0) {
                result.insert(p->val);
            }
            p = p->next;
        }
        return result;
    }

    LinkedList operator-(const LinkedList& other) const {
        LinkedList result;
        unordered_set<int> set;
        ListNode* p = other.head;
        while (p != nullptr) {
            set.insert(p->val);
            p = p->next;
        }
        p = head;
        while (p != nullptr) {
            if (set.count(p->val) == 0) {
                result.insert(p->val);
            }
            p = p->next;
        }
        return result;
    }

    LinkedList& operator=(const LinkedList& other) {
        if (this != &other) {
            deleteList();
            ListNode* p = other.head;
            while (p != nullptr) {
                insert(p->val);
                p = p->next;
            }
        }
        return *this;
    }

    friend ostream& operator<<(ostream& os, const LinkedList& list) {
        ListNode* p = list.head;
        while (p != nullptr) {
            os << p->val;
            if (p->next != nullptr) {
                os << ",";
            }
            p = p->next;
        }
        return os;
    }

    ~LinkedList() {
        deleteList();
    }

private:
    void deleteList() {
        ListNode* p = head;
        while (p != nullptr) {
            ListNode* temp = p;
            p = p->next;
            delete temp;
        }
        head = nullptr;
    }
};
int main() {
    LinkedList A, B;
    A.insert(4);
    A.insert(5);
    A.insert(6);
    B.insert(2);
    B.insert(3);
    B.insert(4);
    cout << "A = " << A << endl;
    cout << "B = " << B << endl;
    LinkedList C = A + B;
    cout << "C = A + B = " << C << endl;
    LinkedList D = A * B;
    cout << "D = A * B = " << D << endl;
    LinkedList E = A - B;
    cout << "E = A - B = " << E << endl;
    return 0;
}
