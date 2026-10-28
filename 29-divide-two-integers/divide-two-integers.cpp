class Solution {
public:
    int divide(int a, int b) {
        long long ans = 0;
        long long i = llabs((long long)a);
        long long j = llabs((long long)b);

        while (i >= j) {
            long long temp = j, multiple = 1;
            while (i >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }
            i -= temp;
            ans += multiple;
        }

        if (ans > INT_MAX) {
            if (a < 0 && b < 0) return INT_MAX;
            return INT_MIN;
        }
        if ((a < 0) != (b < 0)) return -ans;
        return ans;
    }
};