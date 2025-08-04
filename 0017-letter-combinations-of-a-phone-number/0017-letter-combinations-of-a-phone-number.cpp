class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        vector<string>str(10);

        str[0]="";
        str[1]="";
        int a=97;
        for(int i=2;i<=9;i++){
         
          if(i==7||i==9){
          str[i]+= char(a++);  
          str[i]+= char(a++);  
          str[i]+= char(a++);
          str[i]+= char(a++);
          }  
          else{
             str[i]+= char(a++);  
          str[i]+= char(a++);  
          str[i]+= char(a++);
          }

        }
         vector<string>result={""};
        
        vector<string>d;
        for(int i=0;i<digits.size();i++){
           d.push_back(str[digits[i] - '0']);
        }

       
       for(int i=0;i<d.size();i++){
        string s= d[i];
        vector<string>temp;
        for(string prefix:result){
            for(char a:s){
                temp.push_back(prefix+a);
            }
            
        }
        result=temp;
       }
       return result;
    }
};