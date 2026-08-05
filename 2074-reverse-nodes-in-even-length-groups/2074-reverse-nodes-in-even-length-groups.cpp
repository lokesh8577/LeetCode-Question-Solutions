class Solution {
    int Len(ListNode* head) {
        int cnt = 0;

        while (head != NULL) {
            cnt++;
            head = head->next;
        }

        return cnt;
    }

    ListNode* ReverseList(ListNode* head, int k) {
        ListNode* prev = NULL;
        ListNode* curr = head;

        while (k--) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        head->next = curr;

        return prev;
    }

public:
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        int n = Len(head);

        ListNode dummy(0);
        dummy.next = head;

        ListNode* prevGroup = &dummy;
        ListNode* curr = head;

        int groupSize = 1;
        int used = 0;

        while (curr != NULL) {
            int len = min(groupSize, n - used);

            if (len % 2 == 0) {
                ListNode* nextGroup = curr;

                for (int i = 0; i < len; i++) {
                    nextGroup = nextGroup->next;
                }

                ListNode* newHead = ReverseList(curr, len);

                prevGroup->next = newHead;
                prevGroup = curr;
                curr = nextGroup;
            } else {
                for (int i = 0; i < len; i++) {
                    prevGroup = curr;
                    curr = curr->next;
                }
            }

            used += len;
            groupSize++;
        }

        return dummy.next;
    }
};