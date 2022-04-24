#include <bits/stdc++.h>
using namespace std;

void compute_dfs(int node, vector<int> &vis, vector<int> adj[], vector<int> &storeDfs) {

        storeDfs.push_back(node);
        vis[node] = 1;

        for(auto it : adj[node]) {

                if(!vis[it])
                        compute_dfs(it,vis,adj,storeDfs);
        }
}

vector<int> dfsOfGraph(int v, vector<int> adj[]) {

        vector<int> storeDfs;
        vector<int> vis(v+1,0);

        for(int i=1;i<=v;++i) {
                if(!vis) {
                        compute_dfs(i,vis,adj,storeDfs);
                }
        }

        for(int i=0;i<storeDfs.size();++i) {
                cout << storeDfs[i] << " ";
        }
        cout << endl;
}

int main() {

        int N = 6;

        vector<int> adj[6];

        adj[5].push_back(2);
        adj[5].push_back(0);
        adj[4].push_back(0);
        adj[4].push_back(1);
        adj[2].push_back(3);
        adj[3].push_back(1);

        dfsOfGraph(6, adj);

        return 0;
}
