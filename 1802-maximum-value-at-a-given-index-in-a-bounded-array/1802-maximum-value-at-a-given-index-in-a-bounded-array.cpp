class Solution {
public:
    long long getSum(long long peak, long long len) {
        if (peak > len) {
            long long first = peak - len;
            long long last = peak - 1;
            return (first + last) * len / 2;
        } else {
            long long decreasing = (peak - 1) * peak / 2;
            long long ones = len - (peak - 1);
            return decreasing + ones;
        }
    }

    int maxValue(int n, int index, int maxSum) {
        long long low = 1, high = maxSum;
        long long ans = 1;

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            long long left = getSum(mid, index);
            long long right = getSum(mid, n - index - 1);

            long long total = left + right + mid;

            if (total <= maxSum) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return (int)ans;
    }
};