// class Solution {
//     private:
//     bool check(int number){
//         string s = to_string(number);
//         int start = s[0] - '0';
//         int index = 1;
//         while(index < s.size()){
//             start++;
//             if(s[index] - '0' != start){
//                 return false;
//             }
//             index++;
//         }
//         return true;
//     }
// public:
//     vector<int> sequentialDigits(int low, int high) {
//         vector<int>ans;
//         for(int i=low;i<=high;i++){
//             if(check(i)){
//                 ans.push_back(i);
//             }
//         }
//         return ans;
//     }
// };


class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> res;
        for (int i = 1; i <= 9; ++i) {
            int num = i;
            for (int j = i + 1; j <= 9; ++j) {
                num = num * 10 + j;
                if (num >= low && num <= high)
                    res.push_back(num);
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};