class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int> mpp;
        for (int i =0 ; i<arr.size(); i++){
            mpp[arr[i]]++;
        } 
        map<int,int> mpp2;
        for(auto i: mpp){
            mpp2[i.second]++;
            if(mpp2[i.second]>1){
                return false;
            }
        }
        return true;
    }
};