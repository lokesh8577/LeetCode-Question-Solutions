class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        long long windowSum = 0;
        for (int i = 0; i < k; i++) {
            windowSum += arr[i];
        }
        int total = 0;
        if (windowSum / k >= threshold) {
            total++;
        }

        for (int i = k; i < arr.size(); i++) {
            windowSum += arr[i];
            windowSum -= arr[i - k];
            if (windowSum / k >= threshold) {
            total++;
        }
        }
        return total;
    }
};