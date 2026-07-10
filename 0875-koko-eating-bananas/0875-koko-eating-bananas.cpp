class Solution {
public:
    long long totalHrs(vector<int>& piles,int speed){
    long long totalH = 0;
    for(int bananas : piles){
        totalH += ((long long)bananas + speed - 1) / speed;
    }
    return totalH;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
    int n = piles.size();
    int low = 1;
    int high = *max_element(piles.begin(),piles.end());
    int ans = high;
    while(low<=high){
        int mid = low + (high - low)/2;
        long long totalHr = totalHrs(piles,mid);
        if(totalHr <= h){
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