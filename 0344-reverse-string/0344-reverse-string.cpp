class Solution {
public:
    void reverseString(vector<char>& s) {
           int start=0,end=s.size()-1;
           while(start<end){
            swap(s[start++],s[end--]);
           }

        // stack<char> stac;

        // for(int i=0;i<s.size();i++){
        //     stac.push(s[i]);
        // }

        // for(int i=0;i<s.size();i++){
        //     char ans = stac.top();
        //     s[i] = ans;
        //     stac.pop();
        // }
    }
};