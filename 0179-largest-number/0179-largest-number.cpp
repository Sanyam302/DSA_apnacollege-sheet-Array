class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> ans;
        for(int n:nums){
            ans.push_back(to_string(n));
        }
        sort(ans.begin(),ans.end(),[](string &a, string &b){
            return a+b>b+a;
        });
        if(ans[0]=="0"){
            return "0";
        }
        string result;
        for(string i:ans){
            result+=i;
        }
        
        return result;
    }
};
