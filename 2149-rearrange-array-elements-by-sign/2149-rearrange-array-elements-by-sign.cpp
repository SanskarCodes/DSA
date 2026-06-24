class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {        int n = nums.size();
        vector<int>new_arr(n);
        int j =0 ;
        int k =1;
        for(int i = 0 ; i < n ; i++){
                if(nums[i]>0){
                    new_arr[j] = nums[i];
                    j+=2;
                }
                else{
                    new_arr[k]=nums[i];
                    k+=2;
                }
            }
            nums = new_arr;
            return nums;
        }
        
};