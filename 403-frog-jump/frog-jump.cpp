
class Solution {
public:
    map<pair<int, int>, bool> memo;

    bool find(vector<int>& stones, int x) {
        int lo = 0, hi = stones.size() - 1;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            if (stones[mid] == x) return true;
            else if (stones[mid] > x) hi = mid - 1;
            else lo = mid + 1;
        }

        return false;
    }

    bool fun(vector<int>& stones, int pos, int jump) {
        if (pos == stones.back()) return true;

        if (memo.count({pos, jump}))
            return memo[{pos, jump}];

        int next = pos + jump - 1;
        if (jump > 1 && find(stones, next) &&
            fun(stones, next, jump - 1))
            return memo[{pos, jump}] = true;

        next = pos + jump;
        if (jump > 0 && find(stones, next) &&
            fun(stones, next, jump))
            return memo[{pos, jump}] = true;

        next = pos + jump + 1;
        if (find(stones, next) &&
            fun(stones, next, jump + 1))
            return memo[{pos, jump}] = true;

        return memo[{pos, jump}] = false;
    }

    bool canCross(vector<int>& stones) {
        if (stones.size() < 2 || stones[1] != 1)
            return false;

        return fun(stones, 0, 0);
    }
};
