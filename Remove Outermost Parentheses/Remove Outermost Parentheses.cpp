class Solution {
public:
    string removeOuterParentheses(string s) {
        string a;
        int i=0;
        for (char c : s){
            if (c=='('){
                if (i!=0){
                    a.push_back(c);
                }
                i++;
            }
            else{
                i--;
                if (i!=0){
                    a.push_back(c);
                }
            }
        }
        return a;
    }
};
