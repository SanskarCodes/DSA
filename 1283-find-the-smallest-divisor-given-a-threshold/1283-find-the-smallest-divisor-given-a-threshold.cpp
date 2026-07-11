class Solution {
public:
    int sums(vector<int>& nums,int divisor){
    int sum = 0;
    for(int j : nums){
        sum += ceil((double)j/divisor);
    }
    return sum;
}
    int smallestDivisor(vector<int>& nums, int threshold) {
            int high = *max_element(nums.begin(),nums.end());
    int low = 1;
    int ans = -1;
    while(low<=high){
        int mid = low + (high - low)/2;
        if(sums(nums,mid)<=threshold){
            ans = mid;
            high = mid -1;
        }
        else{
            low = mid + 1;
        }
    }
    return ans;
    }
};