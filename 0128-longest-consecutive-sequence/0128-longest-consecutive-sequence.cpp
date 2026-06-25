class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n==0){
            return 0;
        }
        unordered_set<int>st;
        for(auto it:nums){
            st.insert(it);
        }
        int maxi = 1;
        for(auto num : st){
            if(st.find(num - 1)==st.end()){
                int x = num;
                int cons = 1;
                while(st.find(x+1)!=st.end()){
                    cons++;
                    x++;
                }
                maxi = max(maxi,cons); 
            }
        }
        return maxi;
    }
};