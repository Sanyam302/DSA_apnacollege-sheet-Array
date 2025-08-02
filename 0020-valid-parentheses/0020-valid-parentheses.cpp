class Solution {
public:
    bool isValid(string s) {
        if(s[0]==')'||s[0]=='}'||s[0]==']') return 0;
        vector<string>p;
        p.push_back(string(1, s[0]));
       for(int i=1;i<s.length();i++){
        if(p.empty()){
           if(s[i]==')'||s[i]==']'||s[i]=='}'){
            return false;
           
           }
            else{
                p.push_back(string(1,s[i]));
            }
        }
       else if(p.back()[0]=='('){
            if(s[i]==')'){
                p.pop_back();
            }
            else  if(s[i]==']'||s[i]=='}'){
                return false;
            }
            else{
                p.push_back(string(1, s[i]));
        }
        }
       else if(p.back()[0]=='['){
            if(s[i]==']'){
                p.pop_back();
            }
            else  if(s[i]==')'||s[i]=='}'){
                return false;
            }
            else {
                p.push_back(string(1, s[i]));
        }
        }
       else if(p.back()[0]=='{'){
            if(s[i]=='}'){
                p.pop_back();
            }
            else  if(s[i]==']'||s[i]==')'){
                return false;
            }
            else{
                p.push_back(string(1, s[i]));
        }
        }
       }
       return p.empty();
    }
};