class Solution {
public:
    string convertToTitle(int n) {
        string result;
        while(n>0){
            n--;
            int rem = n%26;
            char ch = rem + 'A';
            result.push_back(ch);
            n/=26;
        }
        reverse(begin(result),end(result));
        return result;
    }
};