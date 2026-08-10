class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        vector<int> ans(n, 0);
        queue<int> q;
        sort(deck.begin(), deck.end());
        for (int i = 0; i < n; i++)
            q.push(i);

        for (int i = 0; i < n; i++) {
            int idx = q.front();
            q.pop();
            q.push(q.front());
            q.pop();
            ans[idx] = deck[i];
        }
        return ans;
    }
};