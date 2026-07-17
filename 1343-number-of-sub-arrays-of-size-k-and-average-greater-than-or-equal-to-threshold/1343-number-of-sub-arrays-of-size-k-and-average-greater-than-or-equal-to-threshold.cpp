class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        long long windowSum = 0;
        for (int i = 0; i < k; i++) { // taking first window and store total sum
                                      // of that window in windowSum
            windowSum += arr[i];
        }
        int total = 0;
        if (windowSum / k >=
            threshold) { // check the condition is averagge of window is greater
                         // or equal to threshold or not
            total++;
        }

        for (int i = k; i < arr.size(); i++) { // now checking all the window of
                                               // size k and check the condition
            windowSum += arr[i];
            windowSum -= arr[i - k];
            if (windowSum / k >= threshold) {
                total++;
            }
        }
        return total;//return total sub array which statisfy the condition
    }
};