class Solution {
public:

    vector<int> prevgs(vector<int>& nums) {
        int n = nums.size();
        vector<int> pgs(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {

            while (!st.empty() && nums[st.top()] <= nums[i]) {
                st.pop();
            }

            if (st.empty()) {
                pgs[i] = -1;
            }
            else {
                pgs[i] = st.top();
            }

            st.push(i);   // index
        }

        return pgs;
    }


    vector<int> nextgs(vector<int>& nums) {
        int n = nums.size();
        vector<int> ngs(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {

            while (!st.empty() && nums[st.top()] < nums[i]) {
                st.pop();
            }

            if (st.empty()) {
                ngs[i] = n;
            }
            else {
                ngs[i] = st.top();
            }

            st.push(i);   // index
        }

        return ngs;
    }


    vector<int> prevss(vector<int>& nums) {
        int n = nums.size();
        vector<int> pss(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {

            while (!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }

            if (st.empty()) {
                pss[i] = -1;
            }
            else {
                pss[i] = st.top();
            }

            st.push(i);   // index
        }

        return pss;
    }


    vector<int> nextss(vector<int>& nums) {
        int n = nums.size();
        vector<int> nss(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {

            while (!st.empty() && nums[st.top()] > nums[i]) {
                st.pop();
            }

            if (st.empty()) {
                nss[i] = n;
            }
            else {
                nss[i] = st.top();
            }

            st.push(i);   // index
        }

        return nss;
    }


    long long minsum(vector<int>& nums) {
        int n = nums.size();

        long long total = 0;

        vector<int> nss = nextss(nums);
        vector<int> pss = prevss(nums);

        for (int i = 0; i < n; i++) {

            long long left = i - pss[i];
            long long right = nss[i] - i;

            total += left * right * nums[i];
        }

        return total;
    }


    long long maxsum(vector<int>& nums) {
        int n = nums.size();

        long long total = 0;

        vector<int> ngs = nextgs(nums);
        vector<int> pgs = prevgs(nums);

        for (int i = 0; i < n; i++) {

            long long left = i - pgs[i];
            long long right = ngs[i] - i;

            total += left * right * nums[i];
        }

        return total;
    }


    long long subArrayRanges(vector<int>& nums) {

        return maxsum(nums) - minsum(nums);
    }
};