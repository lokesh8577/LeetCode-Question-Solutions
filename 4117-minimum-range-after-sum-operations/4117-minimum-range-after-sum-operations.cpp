class Solution {
public:
    int minRange(int a, int b, int c) {
        int ans = INT_MAX;
        int temp1 = a;
        int temp2 = b;
        int temp3 = c;
        //no change
        ans = min(ans,(max({temp1,temp2,temp3}) - min({temp1,temp2,temp3})));

        //change a
        temp1 = temp2 + temp3;
        ans = min(ans,(max({temp1,temp2,temp3}) - min({temp1,temp2,temp3})));
        temp1 = a;

        //change b
        temp2 = temp1 + temp3;
        ans = min(ans,(max({temp1,temp2,temp3}) - min({temp1,temp2,temp3})));
        temp2 = b;

        //change c
        temp3 = temp1 + temp2;
        ans = min(ans,(max({temp1,temp2,temp3}) - min({temp1,temp2,temp3})));
        temp3 = c;

        return ans;

    }
};