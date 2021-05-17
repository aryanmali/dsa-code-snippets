//https://leetcode.com/problems/valid-number/

class Solution {
public:
    bool isNumber(string s) {
        bool pointPresent=0,ePresent=0,numPresent=0,numAfterE=0;
        for(int i=0;i<s.size();i++) {
            if(isdigit(s[i])) {
                numPresent = numAfterE = 1;
            }
            else if(s[i]=='.') {
                if(pointPresent || ePresent)
                    return 0;
                pointPresent = 1;
            }
            else if(s[i]=='e' || s[i]=='E') {
                if(!numPresent || ePresent)
                    return 0;
                numAfterE = 0;
                ePresent = 1;
            }
            else if(s[i]=='-' || s[i]=='+') {
                if(i>0 && s[i-1]!='e' && s[i-1]!='E')
                    return 0;
            }
            else
                return 0;
        }
        return numAfterE && numPresent;
    }
};