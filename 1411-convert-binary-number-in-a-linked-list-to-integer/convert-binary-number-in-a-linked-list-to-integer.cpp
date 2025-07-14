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
// class Solution {
// public:
//     int getDecimalValue(ListNode* head) {
//         ListNode* temp=head;
//         int len=0;
//         while(temp){
//             len++;
//             temp=temp->next;
//         }
//         temp=head;
//         int num=0;
//         while(temp){
//             if(temp->val){
//                 num+= (1<<(len-1));

//             }
//             len--;
//             temp=temp->next;
//         }
//         return num;
        
//     }
// };
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int ans = 0;
        for (; head; head = head->next) {
            ans = ans << 1 | head->val;
        }
        return ans;
    }
};