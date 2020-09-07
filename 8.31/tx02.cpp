#include <bits/stdc++.h>
using namespace std;

struct node{
    int value;
    node* next;
};

void print(struct node *head1,struct node *head2){
    vector<int> v;
    while(head1 != NULL && head2 != NULL){
        if(head1->value < head2->value){
            head1 = head1->next;
        }else if(head1->value > head2->value){
            head2 = head2->next;
        }else{
            v.push_back(head1->value);
            head1 = head1->next;
            head2 = head2->next;
        }
    }
}

int main(){
    int n, m;
    cin >> n;
    vector<int> v1(n + 1);
    vector<int> v2(m + 1);
    vector<node> c1(n + 2);
    vector<node> c2(m + 2);
    for(int i = 1; i <= n; i++) {
        cin >> c1[i].value;
        c1[i].next = c1[i+1];
    }
    cin >> m;
    for(int i = 1; i <= m; i++) cin >> v2[i];
    
    
    return 0;
}