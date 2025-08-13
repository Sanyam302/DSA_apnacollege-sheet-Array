class Solution {
  public:
  
  void path(vector<vector<int>>& maze,int row,int column,string &temp,vector<string>&ans,int n){
    if(row < 0 || column < 0 || row >= n || column >= n) return;
    
    if(maze[row][column]==0) return;
if(row==n-1 && column==n-1){
          ans.push_back(temp);
          return;
      }
      
      maze[row][column]=0;
      
      if(row+1<n && maze[row+1][column]==1){
          temp+="D";
          path( maze,row+1,column,temp,ans, n);
          temp.pop_back();
          
      }
      if(column-1>=0 &&maze[row][column-1]==1){
          temp+="L";
          path( maze,row,column-1,temp,ans, n);
          temp.pop_back();
      }
      
       if(column+1<n &&maze[row][column+1]==1){
          temp+="R";
          path( maze,row,column+1,temp,ans, n);
          temp.pop_back();
      }
      
       if(row-1>=0 &&maze[row-1][column]==1){
          temp+="U";
          path( maze,row-1,column,temp,ans, n);
          temp.pop_back();
      }
      
       
      maze[row][column]=1;
      
  }
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        
        
        int n = maze.size();
        string temp="";
        int row=0;
        int column=0;
        vector<string>ans;
        path( maze,row,column,temp,ans, n);
        return ans;
        
        
    }
};