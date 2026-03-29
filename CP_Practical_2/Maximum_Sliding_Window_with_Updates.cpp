#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, k, q;
    cin >> n >> k >> q;
    
    vector<long long> a(n + 1);  // 1-indexed array
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    
    for(int i = 0; i < q; i++){
        int type;
        cin >> type;
        
        if(type == 1){
            // Type 1: Update query
            int pos;
            long long val;
            cin >> pos >> val;
            a[pos] = val;
        }
        else{
            // Type 2: Range maximum query
            int idx;
            cin >> idx;
            
            // Window of size k ending at index idx
            // Start position: idx - k + 1, End position: idx
            int start = max(1, idx - k + 1);
            int end = idx;
            
            long long maxVal = LLONG_MIN;
            for(int j = start; j <= end; j++){
                maxVal = max(maxVal, a[j]);
            }
            
            cout << maxVal << "\n";
        }
    }
    
    return 0;
}
