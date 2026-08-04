class Node {
public:
    int val;
    Node* next;
    Node* prev;
    bool scheduled;

    Node(int data) {
        val = data;
        next = NULL;
        prev = NULL;
        scheduled = false;
    }
};

class Solution {
public:
    void insertAtTail(Node*& head, Node*& tail, int data) {
        Node* temp = new Node(data);

        if (head == NULL) {
            head = temp;
            tail = temp;
        } else {
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
    }

    int totalSteps(vector<int>& nums) {
        Node* head = NULL;
        Node* tail = NULL;

        for (int x : nums) {
            insertAtTail(head, tail, x);
        }

        queue<Node*> curr;

        Node* temp = head;

        while (temp != NULL) {
            if (temp->prev != NULL &&
                temp->prev->val > temp->val) {

                curr.push(temp);
                temp->scheduled = true;
            }

            temp = temp->next;
        }

        int steps = 0;

        while (!curr.empty()) {
            int sz = curr.size();

            queue<Node*> nextQueue;

            while (sz--) {
                Node* node = curr.front();
                curr.pop();

                Node* left = node->prev;
                Node* right = node->next;

                if (left != NULL) {
                    left->next = right;
                }

                if (right != NULL) {
                    right->prev = left;
                }

                if (right != NULL &&
                    right->prev != NULL &&
                    right->prev->val > right->val &&
                    !right->scheduled) {

                    right->scheduled = true;
                    nextQueue.push(right);
                }
            }

            curr = nextQueue;
            steps++;
        }

        return steps;
    }
};