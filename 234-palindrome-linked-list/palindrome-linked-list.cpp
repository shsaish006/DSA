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
    bool isPalindrome(ListNode* head) {
        ListNode* temp=head;
        vector<int>nums;
        while(temp!=nullptr){
            nums.push_back(temp->val);
            temp=temp->next;
        }
        int i=0,j=nums.size()-1;
        while(i<=j){
            if(nums[i]==nums[j]){
            i++;
            j--;
            }
            else return false;
        }
        return true;
        
    }
};