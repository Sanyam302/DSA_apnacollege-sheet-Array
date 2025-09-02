class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<int>q;
        int ans=0;
        for(int i=0;i<tickets.size();i++){
            q.push(i);
        }
        while(tickets[k]!=0){
            ans++;
            tickets[q.front()]--;
            if( tickets[q.front()]!=0) q.push(q.front());
            q.pop();
        }
        return ans;
        
    }
};