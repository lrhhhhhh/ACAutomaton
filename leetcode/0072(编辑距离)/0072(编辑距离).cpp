class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        if(m==0 || n==0) return m+n;
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0x3f3f3f3f));
        for(int i=0; i<=m; ++i) dp[i][0] = i;
        for(int i=0; i<=n; ++i) dp[0][i] = i;
        for(int i=1; i<=m; ++i){
            for(int j=1; j<=n; ++j){
                dp[i][j] = min(dp[i][j], min(dp[i-1][j]+1, dp[i][j-1]+1));
                if(word1[i-1] != word2[j-1]){
                    dp[i][j] = min(dp[i-1][j-1]+1, dp[i][j]);
                }
                else{
                    dp[i][j] = min(dp[i][j], dp[i-1][j-1]);
                }
            }
        }
        return dp[m][n];
    }
};