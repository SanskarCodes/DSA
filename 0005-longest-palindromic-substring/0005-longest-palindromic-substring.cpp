class Solution {
public:
    string longestPalindrome(string s) {
                int maxi = 1;
        int start=0;
        for(int i = 0; i < s.size() ; i++){
            
            int left = i;
            int right = i;
            while( left >= 0 && right < s.size() && s[left] == s[right]){
                if(right - left +1 > maxi){
                    start = left;  
                    maxi = right - left + 1;
                }
                left --;
                right ++;
            }
            left = i;
            right = i+1;
            while( left >= 0 && right < s.size() && s[left] == s[right]){
                if(right - left +1 > maxi){
                    start = left;  
                    maxi = right - left + 1;
                }
                left --;
                right ++;
            }
        }
        return s.substr(start,maxi);
    }
};