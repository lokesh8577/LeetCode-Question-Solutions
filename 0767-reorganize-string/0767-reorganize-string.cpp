class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> mp;
        for (char ch : s) {
            mp[ch]++;
        }
        auto comp = [](const pair<char, int>& a, const pair<char, int>& b) {
            return a.second < b.second;
        };

        priority_queue<pair<char, int>, vector<pair<char, int>>, decltype(comp)>
            maxHeap(comp);
        for (const auto& entry : mp) {
            maxHeap.push({entry.first, entry.second});
        }

        string ans = "";
        pair<char, int> prev = {'#', 0};
        while (!maxHeap.empty()) {
            auto curr = maxHeap.top();
            maxHeap.pop();
            ans += curr.first;

            if (prev.second > 0) {
                maxHeap.push(prev);
            }

            curr.second--;
            prev = curr;
        }
        if (ans.size() != s.size()) {
            return "";
        }
        return ans;
    }
};