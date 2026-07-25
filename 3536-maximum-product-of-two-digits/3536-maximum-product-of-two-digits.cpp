class Solution {
public:
    int maxProduct(int n) {
        vector<int>Store(10,0);
        while(n > 0){
            int digit = n % 10;
            Store[digit]++;
            n /= 10;
        }

        //taking two highest digit in string
        int first = INT_MIN;
        int second = INT_MIN;
        for(int i=9;i>=0;i--){
            if(Store[i] == 0){
                continue;
            }

            if(Store[i] != 0){
                while(Store[i] > 0){
                    if(first == INT_MIN){
                        first = i;
                        Store[i]--;
                    }
                    else{
                        second = i;
                        Store[i]--;
                    }
                    if(first != INT_MIN && second != INT_MIN){
                        break;
                    }
                }
            }
            if(first != INT_MIN && second != INT_MIN){
                break;
            }
        }
        return first * second;
    }
};