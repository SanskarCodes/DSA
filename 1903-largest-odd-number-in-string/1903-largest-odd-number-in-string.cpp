class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.length();
        if((num[n-1]-'0')%2!=0){
            return num;
        }
        string ans = "";
        int found = -1;
        for(int i = n - 1; i >= 0 ; i--){
            if ((num[i] - '0')%2 != 0){
                found = i;
                break;
            }
        }
        if (found != -1){
            for(int i =0 ; i <= found ; i++){
                ans += num[i];
            }
        }
        return ans; 
    }
};