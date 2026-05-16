class Solution {
public:
    string reverseWords(string s) {
        string ans="", temp="";
        int i=s.size()-1;
        while (i>=0){
            if (s[i]!=' '){
                temp+=s[i];
            }
            else{
                reverse(temp.begin(),temp.end());

                if (temp!=""){
                    if (ans!=""){
                        ans+=" ";
                    }
                    ans+=temp;
                }
                temp="";
            }
            i--;
        }
        reverse(temp.begin(),temp.end());
        if (temp!=""){
            if (ans!=""){
                ans+=" ";
            }
            ans+=temp;
        }
        return ans;  
    }
};
