
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode dummy1(0);
        ListNode dummy2(0);

        ListNode* L1 = &dummy1;
        ListNode* L2 = &dummy2;

        while (head) {
            if (head->val < x) {
                L1->next = head;
                L1 = L1->next;
            }
            else {
                L2->next = head;
                L2 = L2->next;
            }

            head = head->next;
        }

        L2->next = nullptr;
        L1->next = dummy2.next;

        return dummy1.next;
    }
};