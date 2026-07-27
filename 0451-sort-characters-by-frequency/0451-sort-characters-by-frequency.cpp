class Solution {
public:
    static bool cmp(pair<char, int> a, pair<char, int> b) {
        return a.second > b.second;
    }
    string frequencySort(string s) {
        unordered_map <char,int> mpp;
        for(int i = 0 ; i < s.size() ; i++){
            mpp[s[i]]++;
        }
        vector<pair<char, int>> v;
        for(auto i : mpp){
            v.push_back(i);
        }
        sort(v.begin(),v.end(),cmp);

        string ans="";
        for(auto i:v){
            ans+= string(i.second,i.first);
        }

        return ans;
    }
};