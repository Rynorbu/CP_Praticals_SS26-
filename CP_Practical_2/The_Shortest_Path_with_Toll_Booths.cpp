#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m, k;
    cin >> n >> m >> k;
    
    vector<int> toll(n);
    for(int i = 0; i < n; i++){
        cin >> toll[i];
    }
    
    // dp[i][j][s] = minimum time to reach booth i with j coins left and s skips used
    const int INF = 1e9;
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m + 1, vector<int>(k + 1, INF)));
    
    // Start at booth 0 with m coins and 0 skips used
    dp[0][m][0] = 0;
    
    // Process each booth
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j <= m; j++){
            for(int s = 0; s <= k; s++){
                if(dp[i][j][s] == INF) continue;
                
                // Option 1: Pay toll to move to next booth
                if(j >= toll[i]){
                    int newCoins = j - toll[i];
                    int newTime = dp[i][j][s] + 1;
                    dp[i + 1][newCoins][s] = min(dp[i + 1][newCoins][s], newTime);
                }
                
                // Option 2: Skip booth (if we haven't exceeded skip limit)
                if(s < k){
                    int newTime = dp[i][j][s] + 2;
                    dp[i + 1][j][s + 1] = min(dp[i + 1][j][s + 1], newTime);
                }
            }
        }
    }
    
    // Find minimum time to reach booth n-1
    int result = INF;
    for(int j = 0; j <= m; j++){
        for(int s = 0; s <= k; s++){
            result = min(result, dp[n - 1][j][s]);
        }
    }
    
    if(result == INF){
        cout << -1 << "\n";
    }
    else{
        cout << result << "\n";
    }
    
    return 0;
}
