class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }
        int num = x;
        int cnt = 0;
        while(num>0){
            cnt++;
            num = num/10;
        }
        int num1 = x;
        int temp = 0;
        long long ans=0;
        while(cnt>0){
            temp = num1%10;
            ans = ans + temp*pow(10,(cnt-1));
            num1 = num1/10;
            cnt--;
        }
        if(ans!=x){
            return false;
        }
        return true;
    }
};