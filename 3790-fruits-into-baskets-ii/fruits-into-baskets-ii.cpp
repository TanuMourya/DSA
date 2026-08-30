class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n=fruits.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<baskets.size();j++){
                if(fruits[i]<=baskets[j]){
                    baskets.erase(baskets.begin() + j);
                    break;
                }
            }
        }
        return baskets.size();
    }
};