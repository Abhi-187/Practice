class Solution {
public:
// https://www.youtube.com/watch?v=PzBYQA6FshA
    int candy(vector<int>& ratings) {
        int n = ratings.size();

        vector<int> lefty(n,1);
        vector<int> righty(n,1);
        if(n==1) return 1;

        //left to right
        for(int i =1;i<n;i++){
            if(ratings[i]>ratings[i-1])
                lefty[i]=lefty[i-1]+1;
        }

        //right to left
        for(int i =n-2;i>=0;i--){
            if(ratings[i]>ratings[i+1])
                righty[i]=righty[i+1]+1;
        }   
        int total=0;
        for(int i=0;i<n;i++) total+=max(lefty[i],righty[i]);
        return total;
    }
};