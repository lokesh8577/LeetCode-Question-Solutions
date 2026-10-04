class Solution {
public:
    int minRotations(string s) {
        int ans = 0;
        int temp = 0;
        for(auto ch : s){
           int x= ch-'0';

            int right = abs(x-temp);
            int left = 10 - right;
            ans += min(left,right);
            temp=x;
        }

        return ans;
    }
};