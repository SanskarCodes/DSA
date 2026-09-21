class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        for(int ast : asteroids){
            bool destroyed = false;
            while(!st.empty() && st.top() > 0 && ast < 0){
                if(st.top() < -ast){
                    st.pop();
                }
                else if(st.top() > -ast){
                    destroyed = true;
                    break;
                }
                else{
                    st.pop();
                    destroyed = true;
                    break;
                }
            }
            if(!destroyed){
                st.push(ast);
            }
        }
        vector<int>ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};