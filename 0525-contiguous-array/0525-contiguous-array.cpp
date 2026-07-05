class Solution {
public:
    int findMaxLength(vector<int>& nums) {
            for(int i = 0 ; i < nums.size() ; i++){
        if(nums[i] == 0){
            nums[i] = -1;
        }
    }
    map<int,int> mpp;
    mpp[0] = -1;
    int prefixSum = 0;
    int maxi = 0;
    for(int i = 0 ; i < nums.size() ; i++){
        prefixSum += nums[i];
        if(mpp.find(prefixSum) != mpp.end()){
            maxi = max(maxi,i-mpp[prefixSum]);
        }
        else{
            mpp[prefixSum] = i;
        }
    }
    return maxi;
    }
};