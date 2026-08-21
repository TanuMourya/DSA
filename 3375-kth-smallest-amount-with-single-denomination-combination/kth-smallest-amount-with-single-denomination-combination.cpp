class Solution {
public:
    using ll = long long;

    ll gcdll(ll a, ll b) {
        return b == 0 ? a : gcdll(b, a % b);
    }

    ll lcm(ll a, ll b, ll limit) {
        ll g = gcdll(a, b);

        if (a / g > limit / b)
            return limit + 1;

        return a / g * b;
    }

    long long findKthSmallest(vector<int>& coins, int k) {
        int n = coins.size();

        auto count = [&](ll x) {
            ll ans = 0;

            for (int mask = 1; mask < (1 << n); mask++) {
                ll L = 1;
                bool overflow = false;
                int bits = 0;

                for (int i = 0; i < n; i++) {
                    if (mask & (1 << i)) {
                        bits++;

                        L = lcm(L, coins[i], x);

                        if (L > x) {
                            overflow = true;
                            break;
                        }
                    }
                }

                if (overflow)
                    continue;

                ll cur = x / L;

                if (bits % 2)
                    ans += cur;
                else
                    ans -= cur;
            }

            return ans;
        };

        ll lo = 1;
        ll hi = 1LL * (*min_element(coins.begin(), coins.end())) * k;

        while (lo < hi) {
            ll mid = lo + (hi - lo) / 2;

            if (count(mid) >= k)
                hi = mid;
            else
                lo = mid + 1;
        }

        return lo;
    }
};