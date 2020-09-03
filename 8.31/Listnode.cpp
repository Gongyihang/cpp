#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
using namespace std;


struct ListNode {
	int val;
	struct ListNode *next;
};


class Solution {
public:
    /**
     * 
     * @param head1 ListNode类 
     * @param head2 ListNode类 
     * @return ListNode类
     */
    ListNode* addInList(ListNode* head1, ListNode* head2) {
        // write code here
        string s1,s2;
        while(head1 != nullptr){
            s1 += to_string(head1->val);
            head1 = head1->next;
        }
        while(head2 != nullptr){
            s2 += to_string(head2->val);
            head2 = head2->next;
        }
        string s3 = to_string(stoi(s1) + stoi(s2));
        
        ListNode *res = nullptr;
        ListNode *p = res;

        for(int i = 0; i < (int)s3.size(); i++){
            res->next->val = s3[i] - '0';
            res = res->next;
        }
        return p->next;
    }
};

int main(){
    
    system("pause");
    return 0;
}