class Solution {
public:
    int myAtoi(string s) {
        int i = 0 ;
        while( i < s.size() && s[i] == ' '){
            i++;
        }
        int sign = 1;
        if(i < s.size()){
            if(s[i] == '-'){
                sign = -1;
                i++;
            }
            else if (s[i] == '+'){
                i++;
            }
        }
        int num = 0;
        while(i < s.size() && isdigit(s[i])){
            int digit = s[i] - '0';
            if (num > INT_MAX / 10 ||
            (num == INT_MAX / 10 && digit > 7)) {
            return (sign == 1) ? INT_MAX : INT_MIN;
        }
            num = num*10 + digit;
            i++;
        }



        return num*sign;
    }
};