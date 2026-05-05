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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next) return head;

        ListNode* a = head;
        int cnt = 1;

        while (a->next) {
            a = a->next;
            cnt++;
        }

        a->next = head;
        k %= cnt;

        int val = cnt - k;
        while (val--) a = a->next;

        ListNode* nums = a->next;
        a->next = NULL;

        return nums;
    }
};