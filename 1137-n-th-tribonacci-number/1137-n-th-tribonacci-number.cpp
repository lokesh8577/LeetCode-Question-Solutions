class Solution {
public:
    int tribonacci(int n) {
        if(n == 0) return 0;
        if(n <= 2) return 1;

        int first = 0;
        int second = 1;
        int third = 1;

        while(n - 2){
            int temp = first + second + third;
            first = second;
            second = third;
            third = temp;
            n--;
        }

        return third;
    }
};