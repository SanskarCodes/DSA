class Solution {
public:
    vector<int> nextss(vector<int> arr){
        int n = arr.size();
        vector<int> nss(n);
        stack<int>st;
        for(int i = n-1 ; i >= 0 ; i--){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            if(st.empty()){
                nss[i] = n;
            }
            else{
                nss[i] = st.top();
            }
            st.push(i);
        }
        return nss;
    }

    vector<int> prevss(vector<int> arr){
        int n = arr.size();
        vector<int> pss(n);
        stack<int>st;
        for(int i = 0 ; i < n ; i++){
            while(!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }
            if(st.empty()){
                pss[i] = -1;
            }
            else{
                pss[i] = st.top();
            }
            st.push(i);
        }
        return pss;
    }

    int sumSubarrayMins(vector<int>& arr) {
        int total = 0;
        long long mod = 1e9 + 7;
        vector<int>nss = nextss(arr);
        vector<int>pss = prevss(arr);
        for(int i = 0 ; i <= arr.size()-1 ; i++){
            int left = i - pss[i];
            int right = nss[i] - i;
            total = (total + (arr[i] * left % mod) * right) % mod;
        }
        return total;
    }
};