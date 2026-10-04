class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0;i<nums.size();i++) {
            if (pq.size() < k) {
                pq.push(nums[i]);
            } else {
                if (pq.top() < nums[i]) {
                    pq.pop();
                    pq.push(nums[i]);
                }
            }
        }

        unordered_map<int,int>mp;
        while (!pq.empty()) {
            mp[pq.top()]++;
            pq.pop();
        }
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            if(mp.find(nums[i]) != mp.end()){
                ans.push_back(nums[i]);
                mp[nums[i]]--;
                if(mp[nums[i]] == 0){
                    mp.erase(nums[i]);
                }
            }
        }
        return ans;
    }
};