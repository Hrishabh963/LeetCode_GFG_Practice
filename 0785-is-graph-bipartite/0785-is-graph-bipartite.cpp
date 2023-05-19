class Solution {
public:
    bool dfs(vector<vector<int>> &graph ,int parent,vector<int> &colored){
        if(colored[parent]==-1) colored[parent] = 1;
        for(auto it : graph[parent]){
            if(colored[it]==-1){
                colored[it] = 1 - colored[parent];
                if(!dfs(graph,it,colored))return false;
            }
            else if(colored[it] == colored[parent])return false;
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> colored(graph.size(),-1);
        for(int i = 0; i<graph.size(); i++){
            if(colored[i]==-1){
                if(!dfs(graph,i,colored))return false;
            }
        }
        return true;
    }
};