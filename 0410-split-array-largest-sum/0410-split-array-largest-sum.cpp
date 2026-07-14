class Solution {
public:
    bool minSum(vector<int>& nums,int k , int mid){
    long long sum = 0;
    long long cnt = 1;
    for(int i= 0 ; i < nums.size() ; i++){
        sum += nums[i];
        if(sum > mid){
            cnt ++;
            sum = nums[i];
        }
    }
    return cnt <= k;
}
    int splitArray(vector<int>& nums, int k) {
    int low = *max_element(nums.begin(),nums.end());
    long long high = 0;
    int ans = -1;
    for(int i = 0 ; i < nums.size() ; i++){
        high += nums[i];
    }
    while(low<=high){
        int mid = low + (high - low)/2;
        if(minSum(nums,k,mid) == true){
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return ans;
    }
};