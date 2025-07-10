// User function Template for C++

class Solution {
  public:
    bool pairInSortedRotated(vector<int>& arr, int target) {
        int l=0;
        int r=arr.size()-1;
        int n=arr.size();
        int pivot=-1;
        for(int i=0;i<n-1;i++){
            if(arr[i]>arr[i+1]){
                pivot=i;
                break;
            }
        }
        if(pivot==-1) pivot=n-1;
        int a=(pivot+1)%n;
        int b=pivot;
        while(a!=b)
        {if(arr[a]+arr[b]==target) return true;
        else if(arr[a]+arr[b]>target){
            b=(b+n-1)%n;
            }
            
            else{
                a=(a+1)%n;
                
        }}
        
        return 0;
    }
};