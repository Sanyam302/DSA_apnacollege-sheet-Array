class Solution {
public:
bool issafe(int i,int j,vector<vector<int>> &placed){
   int a=placed.size();
      if(!placed.empty() ){
        for(int x=0;x<a;x++)
       { if(i==placed[x][0] || j==placed[x][1]){
            return false;
        }
        if(abs(placed[x][0]-i)==abs(placed[x][1]-j)){
            return false;
        }}
 }
      return true;
}
void Nqueens(int n,vector<vector<string>>&ans,int i,vector<vector<int>>&placed,vector<string>&temp){
    if(i==n){
        ans.push_back(temp);
        return;
    }
      
      for(int col=0;col<n;col++){
           if(issafe(i,col,placed)){
             placed.push_back({i,col});
             string block="";
              for(int x=0;x<n;x++){
                if(x==col){
                    block+="Q";
                }
                else{
                    block+=".";
                }
              }
              temp.push_back(block);
              
              Nqueens(n,ans,i+1,placed,temp);
              placed.pop_back();
              temp.pop_back();
              }
      }
    }
    vector<vector<string>> solveNQueens(int n) {
           vector<vector<string>>ans;
        vector<vector<int>>placed;
        vector<string>temp;

         Nqueens(n,ans,0,placed,temp);
         return ans;
        
    }
};