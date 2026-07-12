class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        unordered_map<int, vector<int>> mp;
        priority_queue<int, vector<int>, greater<int>> pq;
        unordered_map<int, bool> visited;
        for (int i = 0; i < arr.size(); i++) {
            if (!visited[arr[i]]) {
                pq.push(arr[i]);
                visited[arr[i]] = 1;
            }
            mp[arr[i]].push_back(i);
        }
        int rank = 1;
        while (!pq.empty()) {
            for (auto x : mp[pq.top()]) {
                arr[x] = rank;
            }
            rank++;
            pq.pop();
        }
        return arr;
    }
};