#ifndef LISTTEST_H
#define LISTTEST_H

#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x): val(x),next(nullptr) {}
    ListNode(int x, ListNode* next): val(x), next(next) {}
};


ListNode *detectCycle(ListNode *head)
{
        if(head == nullptr || head->next == nullptr) return nullptr;

        ListNode* slow=head, *fast=head;
        while(fast != nullptr || fast->next != nullptr)
        {

            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) break;
        }

        slow = head;
        while(slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }

void detectCycle_test()
{
    ListNode* n1 = new ListNode(3);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(0);
    ListNode* n4 = new ListNode(-4);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n2;

    ListNode *res = detectCycle(n1);
    cout<<res->val<<endl;
}



// 单向链表
struct MyListNode
{
    int val;
    MyListNode* next;
    MyListNode(): val(-1), next(nullptr) {}
    MyListNode(int val): val(val), next(nullptr) {}
    MyListNode(int val, MyListNode* next): val(val), next(next) {}
};


class MyLinkedList {
public:
    int count;
    MyListNode* head;  //虚拟头结点

    /** Initialize your data structure here. */
    MyLinkedList() {
        count = 0;
        head = new MyListNode(-1);
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if(index < 0 || index >= count) return -1;

        MyListNode* cur = head->next;
        for(int i=0; i<index; i++)
        {
            cur = cur->next;
        }
        if(cur) return cur->val;
        return -1;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        MyListNode* root = new MyListNode(val);
        MyListNode* first = head->next;
        head->next = root;
        root->next = first;

        count++;
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        MyListNode* node = new MyListNode(val);
        MyListNode* cur = head->next;
        MyListNode* pre = head;
        while(cur)
        {
            pre = cur;
            cur = cur->next;
        }
        pre->next = node;

        count++;
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if(index > this->count) return;

        MyListNode* node = new MyListNode(val);
        MyListNode* cur = head->next;
        MyListNode* pre = head;
        for(int i=0; i<index; i++)
        {
            pre = cur;
            cur = cur->next;
        }
        node->next = cur;
        pre->next = node;

        count++;
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if(index<0 || index>=this->count) return;

        MyListNode* cur = head->next;
        MyListNode* pre = head;
        for(int i=0; i<index; i++)
        {
            pre = cur;
            cur = cur->next;
        }
        if(cur)
        {
            pre->next = cur->next;
            delete cur;
        }

        count--;
    }
};

// 双向链表
struct MyListNode2
{
    int val;
    MyListNode2* next;
    MyListNode2* pre;
    MyListNode2(): val(-1), next(nullptr), pre(nullptr) {}
    MyListNode2(int val): val(val), next(nullptr), pre(nullptr) {}
    MyListNode2(int val, MyListNode2* next, MyListNode2* pre): val(val), next(next), pre(pre) {}
};

class MyLinkedList2 {
public:
    int count;
    MyListNode2* head;  //虚拟头结点
    MyListNode2* tail;

    /** Initialize your data structure here. */
    MyLinkedList2()
    {
        count = 0;
        head = new MyListNode2(-1);
        tail = new MyListNode2(-1);
        head->next = tail;
        tail->pre = head;
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if(index < 0 || index >= count) return -1;

        MyListNode2* cur = head->next;
        for(int i=0; i<index; i++)
        {
            cur = cur->next;
        }
        if(cur) return cur->val;
        return -1;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        MyListNode2* root = new MyListNode2(val);
        MyListNode2* first = head->next;
        head->next = root;

        root->pre = head;

        if(first)
        {
            root->next = first;
            first->pre = root;
        }

        count++;
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        MyListNode2* node = new MyListNode2(val);
        node->next = tail;
        node->pre = tail->pre;

        tail->pre->next = node;
        tail->pre = node;

        count++;
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if(index > this->count) return;

        MyListNode2* node = new MyListNode2(val);
        MyListNode2* cur = head->next;
        MyListNode2* pre = head;
        for(int i=0; i<index; i++)
        {
            pre = cur;
            cur = cur->next;
        }
        node->next = cur;
        node->pre = pre;

        pre->next = node;
        cur->pre = node;

        count++;
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if(index<0 || index>=this->count) return;

        MyListNode2* cur = head->next;
        for(int i=0; i<index; i++)
        {
            cur = cur->next;
        }
        if(cur)
        {
            cur->pre->next = cur->next;
            if(cur->next)
                cur->next->pre = cur->pre;
            delete cur;
        }

        count--;
    }
};

#endif // LISTTEST_H
