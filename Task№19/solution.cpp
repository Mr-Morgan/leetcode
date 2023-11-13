class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* iterator_n = head;
				
	for (int i = 0; i <= n; i++) {
            if (iterator_n) iterator_n = iterator_n->next;
            else return head->next;
        }// for 
				
	ListNode* iterator_erace = head;

        while (iterator_n) {
            iterator_erace = iterator_erace->next;
            iterator_n = iterator_n->next;
        }// while

	iterator_erace->next = iterator_erace->next->next;
        return head;
    }//ListNode* removeNthFromEnd(ListNode* head, int n)
};// Solution
