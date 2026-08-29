class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        int count = 0;

        // Check if there are at least k nodes
        while (temp != NULL && count < k) {
            temp = temp->next;
            count++;
        }

        // Fewer than k nodes → leave them unchanged
        if (count < k)
            return head;

        // Reverse first k nodes
        ListNode* prev = NULL;
        ListNode* curr = head;

        for (int i = 0; i < k; i++) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        // head is now the last node of the reversed group
        head->next = reverseKGroup(curr, k);

        // prev is the new head of this group
        return prev;
    }
};