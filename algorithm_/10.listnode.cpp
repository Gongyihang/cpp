#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
using namespace std;
//一航代码
//链表节点定义
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :val(x), next(NULL) {
    }
};
//头插法（生成的链表中结点的顺序与输入的顺序相反）
void creatlist_head(ListNode* head)
{
    int val;
    cin >> val;
    head->val = val;
    while (cin >> val) {
        ListNode* temp = new ListNode(val);
        temp->next = head->next;
        head->next = temp;
    }
}
//尾插法（生成的链表中结点的顺序与输入的顺序相同）
void creatlist_tail(ListNode* head)
{
    ListNode *re = head;
    int val;
    cin >> val;
    head->val = val;
    while (cin >> val) {
        ListNode* temp = new ListNode(val);
        re->next = temp;
        re = temp;
    }
    re->next = nullptr;
}
//反转整个链表递归法
ListNode* reverseList(ListNode* head) {
    if (head == nullptr || head->next == nullptr) return head;
    ListNode* last = reverseList(head->next);
    head->next->next = head;
    head->next = nullptr;
    return last;
}

//反转整个链表迭代法
ListNode* reverse_list(ListNode* head) {
    ListNode* pre = nullptr;
    ListNode* cur = head;
    ListNode* nex = nullptr;
    
    while(cur){
        nex = cur->next;//暂存后一个node
        cur->next = pre;//存好以后将cur指向前一个node
        pre = cur;//将前一个指针指向现在的指针
        cur = nex;//现在的指针指向nex
    }
    return pre;//返回pre
}

//反转[m,n]区间的链表，递归法
ListNode* successor = nullptr; // 后驱节点
// 反转以 head 为起点的 n 个节点，返回新的头结点
ListNode* reverseN(ListNode* head, int n) {
    if (n == 1) { 
        // 记录第 n + 1 个节点
        successor = head->next;
        return head;
    }
    // 以 head.next 为起点，需要反转前 n - 1 个节点
    ListNode* last = reverseN(head->next, n - 1);

    head->next->next = head;
    // 让反转之后的 head 节点和后面的节点连起来
    head->next = successor;
    return last;
}
ListNode* reverseBetween_cur(ListNode* head, int m, int n) {
    // base case
    if (m == 1) {
        return reverseN(head, n);
    }
    // 前进到反转的起点触发 base case
    head->next = reverseBetween_cur(head->next, m - 1, n - 1);
    return head;
}


//反转区间[m,n]之间的结点，迭代法
ListNode* reverseBetween_ite(ListNode* head, int m, int n)
{
    if (n == 1 || !head)
        return head; // 特殊情况处理（当然不写也行）
    ListNode *prev = NULL, *curr = head; // 定义prev和curr指针，用于翻转链表
    while (m > 1) {
        prev = curr;
        curr = curr->next; // 将prev与curr定位到需要翻转的初始位置
        m--;
        n--; // 这里很重要！
    }
    ListNode *before = prev, *after = curr; // 定义prev前面一位和curr后面一位的指针，方便翻转完链表后重新连起来
    while (n > 0) {
        // 翻转链表四步大法
        ListNode* nextptr = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextptr;
        n--;
    }
    if (before)
        before->next = prev; // 将链表重新连起来
    else
        head = prev; // 将链表重新连起来
    after->next = curr; // 将链表重新连起来
    return head;
}

ListNode* reverse_k_group(ListNode* head, int k) {
    ListNode *dummy = new ListNode(-1);
    ListNode *pre = dummy, *cur = head, *tem;
    dummy->next = head;
    int len = 0;
    while(head != nullptr){
        len++;
        head = head->next;
    }
    for(int i = 0; i < len / k; i++){
        for(int j = 0; j < k - 1; j++){
            tem = cur->next;
            cur->next = tem->next;
            tem->next = pre->next;
            pre->next = tem;
        }
        pre = cur;
        cur = pre->next;
    }
    return dummy->next;
}

int main(){
    ListNode *head = new ListNode(-1);//不带头结点
    // creatlist_head(head);//生成的链表中结点的顺序与输入的顺序相反
    creatlist_tail(head);//生成的链表中结点的顺序与输入的顺序相同
    //1 2 3 4 5 6 7^Z
    // head = reverseList(head); //递归
    // head = reverse_list(head);   //迭代
    head = reverseBetween_cur(head, 3, 6);
    // head = reverseBetween_ite(head, 3, 6);
    // head = reverse_k_group(head, 2);
    for(auto it = head; it != nullptr; it = it->next){
        cout << it->val << " ";
    }
    system("pause");
    return 0;
}