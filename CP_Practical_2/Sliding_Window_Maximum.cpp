#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, k;
    cin >> n >> k;
    
    vector<long long> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    
    // Deque to store indices of elements
    deque<int> dq;
    vector<long long> result;
    
    for(int i = 0; i < n; i++){
        // Remove elements outside current window from front
        if(!dq.empty() && dq.front() < i - k + 1){
            dq.pop_front();
        }
        
        // Remove elements from back that are smaller than current element
        while(!dq.empty() && a[dq.back()] <= a[i]){
            dq.pop_back();
        }
        
        // Add current element's index to deque
        dq.push_back(i);
        
        // When window is complete, add maximum to result
        if(i >= k - 1){
            result.push_back(a[dq.front()]);
        }
    }
    
    // Print result
    for(int i = 0; i < result.size(); i++){
        if(i > 0) cout << " ";
        cout << result[i];
    }
    cout << "\n";
    
    return 0;
}
