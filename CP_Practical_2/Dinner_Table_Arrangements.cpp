#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while(t--) {
        int n;
        cin >> n;
        
        // Store allergies as bitmasks for each friend
        vector<int> allergies(n, 0);
        
        for(int i = 0; i < n; i++) {
            int m;
            cin >> m;
            for(int j = 0; j < m; j++) {
                int allergy;
                cin >> allergy;
                // Set the bit for this allergy
                allergies[i] |= (1 << (allergy - 1));
            }
        }
        
        // Check if two friends can sit adjacent (no common allergies)
        auto canSitTogether = [&](int friend1, int friend2) -> bool {
            return (allergies[friend1] & allergies[friend2]) == 0;
        };
        
        // Special case: single friend
        if(n == 1) {
            cout << "YES\n";
            continue;
        }
        
        // DP with bitmask: dp[mask][last] = true if we can arrange friends in 'mask' with 'last' friend at the end
        // We fix friend 0 as the starting point (arbitrary choice for circular arrangement)
        vector<vector<bool>> dp(1 << n, vector<bool>(n, false));
        
        // Base case: start with friend 0
        dp[1][0] = true;
        
        // Fill DP table
        for(int mask = 0; mask < (1 << n); mask++) {
            for(int last = 0; last < n; last++) {
                if(!dp[mask][last]) continue;
                if(!(mask & (1 << last))) continue; // last must be in mask
                
                // Try adding next friend
                for(int next = 0; next < n; next++) {
                    if(mask & (1 << next)) continue; // next already placed
                    if(canSitTogether(last, next)) {
                        dp[mask | (1 << next)][next] = true;
                    }
                }
            }
        }
        
        // Check if we can form a valid circular arrangement
        // All friends must be placed, and the last friend must be able to sit next to friend 0
        bool validArrangement = false;
        int fullMask = (1 << n) - 1;
        
        for(int last = 0; last < n; last++) {
            if(last != 0 && dp[fullMask][last] && canSitTogether(last, 0)) {
                validArrangement = true;
                break;
            }
        }
        
        cout << (validArrangement ? "YES" : "NO") << "\n";
    }
    
    return 0;
}
