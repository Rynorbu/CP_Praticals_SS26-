#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        
        int result = 0;
        
        // Try to set each bit from MSB (29) to LSB (0)
        // This greedy approach works because we want the maximum AND value
        for(int bit = 29; bit >= 0; bit--){
            int candidate = result | (1 << bit);
            bool found = false;
            
            // Check all subarrays of length k
            for(int i = 0; i <= n - k; i++){
                int andVal = a[i];
                
                // Calculate AND of subarray [i, i+k-1]
                for(int j = i + 1; j < i + k; j++){
                    andVal &= a[j];
                }
                
                // Check if this subarray has all bits of candidate set
                // i.e., (andVal & candidate) == candidate
                if((andVal & candidate) == candidate){
                    found = true;
                    break;
                }
            }
            
            // If we found a subarray with candidate bits, update result
            if(found){
                result = candidate;
            }
        }
        
        cout << result << "\n";
    }
    
    return 0;
}
