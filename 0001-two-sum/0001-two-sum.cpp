class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int,int> mpp;
        for(int i  = 0 ; i < n ; i++){
            int j = nums[i];
            int more  = target - j ; 
            if(mpp.find(more) != mpp.end()){
                return {mpp[more],i};
            }
            else{
                mpp[nums[i]] = i;
            }
        }
        return {-1,-1};
    }
};