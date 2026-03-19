class Solution {
public:
    int strStr(string haystack, string needle) {
        for ( int i=0; i<haystack.length(); i++){
            if (haystack[i]==needle[0]){
                int j=1;
                for (j=1; j<needle.length(); j++){
                    if (haystack[i+j]!=needle[j]){
                        break;
                    }
                }
                if (j==needle.length()){
                    return i;
                }
            }
        }
        return -1;
    }
};
