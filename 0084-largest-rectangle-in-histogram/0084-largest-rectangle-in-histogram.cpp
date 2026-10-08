class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxArea = 0;
        for(int i = 0; i < heights.size(); i++) {
            while(!st.empty() && heights[st.top()] > heights[i]) {
                int index = st.top();
                st.pop();
                int width;
                if(st.empty())
                    width = i;
                else
                    width = i - st.top() - 1;
                maxArea = max(maxArea, heights[index] * width);
            }
            st.push(i);
        }
        while(!st.empty()) {
            int index = st.top();
            st.pop();
            int width;
            if(st.empty())
                width = heights.size();
            else
                width = heights.size() - st.top() - 1;
            maxArea = max(maxArea, heights[index] * width);
        }
        return maxArea;
    }
};