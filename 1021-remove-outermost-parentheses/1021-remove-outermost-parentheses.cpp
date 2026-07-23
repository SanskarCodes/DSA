class Solution {
public:
    string removeOuterParentheses(string s) {
        string result = "";
        int cnt = 0;
        for(char i : s){
            if(i == '('){
                cnt++;
                if(cnt>1){
                    result += i;
                }
            }
            else if( i == ')'){
                cnt--;
                if(cnt>0){
                    result +=i;
                }
            }
        }
        return result;
    }
};