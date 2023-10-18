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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode lres;
        ListNode *pres = &lres;
        int carry = 0;
        while (l1 || l2 || carry) {
            int sum = carry;
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }//if ()

            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }//if ()

            pres->next = new ListNode (sum%10);
            pres = pres->next;
            carry = sum / 10;
        }//while ()
        return lres.next;
    }//ListNode* addTwoNumbers()
};// Solution
