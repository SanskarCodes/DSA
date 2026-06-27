class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
    int n = nums.size();
    int prefixSum = 0;
    unordered_map<int,int> prefixSumCount;
    prefixSumCount[prefixSum] = 1;
    int count = 0;
    for(int i =0 ; i<n ; i++){
        prefixSum+=nums[i];
        int remove = prefixSum - k;
        if(prefixSumCount.find(remove) != prefixSumCount.end()){
            count += prefixSumCount[remove];;
        }
        prefixSumCount[prefixSum]++;
    }
    return count;       
    }
};