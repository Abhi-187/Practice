class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.length();

        for(int l = 1;l<=n/2;l++){
            if(n%l == 0){
                int times = n/l;
                string sub = s.substr(0,l);
                string check = "";

                while(times--){
                    check += sub;
                }
                if(check==s) return true;
            }
        }
    return false;
        
    }
};