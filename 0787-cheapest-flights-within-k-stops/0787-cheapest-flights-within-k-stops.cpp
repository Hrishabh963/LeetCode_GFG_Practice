class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
     vector<pair<int,int>> adj[n];
        for(auto it: flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        queue<pair<pair<int,int>,int>> q;
        vector<int> dist(n,1e9);
        q.push({{src,0},0});
        dist[src] = 0;
        while(!q.empty()){
            int node = q.front().first.first;
            int currW = q.front().first.second;
            int stop = q.front().second;
            q.pop();
            if(stop>k) continue;
            for(auto it : adj[node]){
                int adjNode = it.first;
                int edge = it.second;
                if(currW + edge < dist[adjNode]){
                    dist[adjNode] = currW + edge;
                    q.push({{adjNode,currW+edge},stop+1});
                }
            }
        }
        if(dist[dst] == 1e9) return -1;
        return dist[dst];
    }
};