class Solution {
public:
    int totalDays(vector<int>& weights, int capacity){
    long long totaldays = 1 ;
    long long current = 0;
    for(int w : weights){
        if(current+w <= capacity){
            current+=w;
        }
        else{
            totaldays++;
            current = w;
        }
    } 
    return totaldays;
    }
    int shipWithinDays(vector<int>& weights, int days) {
    int n = *max_element(weights.begin(),weights.end());
    int ans = -1;
    int low = *max_element(weights.begin(), weights.end());
    long long high = accumulate(weights.begin(), weights.end(), 0);
    while(low<=high){
        int mid = low + (high - low)/2;
        long long totalD = totalDays(weights,mid);
        if(totalD<=days){
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