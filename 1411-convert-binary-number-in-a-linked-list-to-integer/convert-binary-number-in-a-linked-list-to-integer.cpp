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
    int getDecimalValue(ListNode* a) {
        ListNode* b = a;
        int c = 0;
        while (b) {
            c++;
            b = b->next;
        }
        b = a;
        int d = 0;
        while (b) {
            if (b->val) {
                d += (1 << (c - 1));
            }
            c--;
            b = b->next;
        }
        return d;
    }
};
