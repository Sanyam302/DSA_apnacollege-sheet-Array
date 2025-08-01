class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        if(numRows==1)  {ans.push_back({1});
        return ans;
        }
        ans.push_back({1});
        ans.push_back({1,1});
        vector<int>previous={1,1};
        
        for(int i=2;i<numRows;i++){
            vector<int>current;
            current.push_back(1);
            for(int j=1;j<i;j++){
               current.push_back(previous[j-1]+previous[j]);
            }
            current.push_back(1);
            ans.push_back(current);
            previous.clear();
            previous=current;

        }
        return ans;
    }
};