class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>m;
        stack<int>s;
        vector<int>ans;
        for(int j=nums2.size()-1;j>=0;j--){
            int num=nums2[j];

            while(!s.empty() && s.top()<num) s.pop();
            if(s.empty()) m[num]=-1;
            else m[num]=s.top();

            s.push(num);

        }

        for(int num: nums1){
          ans.push_back(m[num]);
        }
        return ans;

    }
};