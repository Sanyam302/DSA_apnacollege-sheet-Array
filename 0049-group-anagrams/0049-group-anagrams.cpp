class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        ans.push_back({strs.front()});
        vector<string>sorted;
        sort(strs.front().begin(),strs.front().end());
        sorted.push_back(strs.front());
        for(int i=1;i<strs.size();i++){
            string temp=strs[i];
            bool found=false;
            sort(temp.begin(),temp.end());
            for(int j=0;j<sorted.size();j++){
                if(temp==sorted[j]){
                    ans[j].push_back(strs[i]);
                    found=true;
                    break;
                }
                
            }
            if(!found){
               sorted.push_back(temp);
            ans.push_back({strs[i]});
            }
           
            
        }
        return ans;
    }
};