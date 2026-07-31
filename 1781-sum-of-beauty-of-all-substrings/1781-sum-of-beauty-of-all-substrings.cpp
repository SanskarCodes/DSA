class Solution {
public:
    int beautySum(string s) {
        int sum = 0 ; 
        for(int i = 0 ; i < s.size() ; i++){
            unordered_map<int,int> mpp ;
            for(int j = i; j < s.size() ; j++){
                mpp[s[j]]++;
                int maxi = INT_MIN;
                int mini = INT_MAX;
                for(auto k: mpp){
                    mini = min(mini,k.second);
                    maxi = max(maxi,k.second);
                }
                sum += (maxi - mini);
            }
        }
        return sum;
    }
};