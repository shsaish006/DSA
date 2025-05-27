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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode*temp=head;
        while(temp!=nullptr && temp->next!=nullptr){
            if(temp->next->val==temp->val){
                ListNode* del=temp->next;
                temp->next=del->next;
                delete del;

            }
            else temp=temp->next;
        }
        
    return head;}
};