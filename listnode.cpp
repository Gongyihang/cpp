#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
using namespace std;

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
    // head = reverse_list(head);
    head = reverse_k_group(head, 2);
    for(auto it = head; it != nullptr; it = it->next){
        cout << it->val << " ";
    }
    system("pause");
    return 0;
}