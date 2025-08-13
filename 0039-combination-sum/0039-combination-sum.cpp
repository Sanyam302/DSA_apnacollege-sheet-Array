class Solution {
public:
    void helper(vector<int>& candidates, int target,int idx,vector<int>&temp,vector<vector<int>>&result){
        if(target==0){
            result.push_back(temp);
            return;
        }
        for(int i=idx;i<candidates.size();i++){
            if(candidates[i] > target) break;

            temp.push_back(candidates[i]);
            helper(candidates,target-candidates[i],i,temp,result); //pas the same i th element as it can be used infinite times till it is not equal to target also decrement the target 
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>result;
        vector<int>temp;
        sort(candidates.begin(),candidates.end());
        helper(candidates,target,0,temp,result);
        return result;
    }
};