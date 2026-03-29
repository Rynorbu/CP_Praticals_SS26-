#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, int> pli;

const ll INF = 1e18;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    
    vector<vector<pair<int, ll>>> adj(n + 1);  // adjacency list: {node, weight}
    
    for(int i = 0; i < m; i++){
        int u, v;
        ll w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});  // bidirectional
    }
    
    // Dijkstra's algorithm
    vector<ll> dist(n + 1, INF);
    priority_queue<pli, vector<pli>, greater<pli>> pq;
    
    dist[1] = 0;
    pq.push({0, 1});
    
    while(!pq.empty()){
        auto [d, u] = pq.top();
        pq.pop();
        
        if(d > dist[u]) continue;
        
        for(auto [v, w] : adj[u]){
            if(dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    
    if(dist[n] == INF){
        cout << -1 << "\n";
    }
    else{
        cout << dist[n] << "\n";
    }
    
    return 0;
}
