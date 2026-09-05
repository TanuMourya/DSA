class Solution {
public:
    int maximumSum(vector<int>& a) {
        int n = a.size();

        int noDel = a[0];
        int oneDel = 0;
        int res = a[0];

        for (int i = 1; i < n; i++) {
            int prevNoDel = noDel;

            noDel = max(a[i], noDel + a[i]);

            oneDel = max(prevNoDel, oneDel + a[i]);

            res = max(res, max(noDel, oneDel));
        }

        return res;
    }
};