/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        int n=0;
        for(auto t=head;t;t=t->next) n++;
        if(n==1) return nullptr;

        auto t=head;
        for(int i=0;i<n/2-1;i++) t=t->next;
        t->next=t->next->next;

        return head;
    }
};