#include <bits/stdc++.h>
using namespace std;

vector<int> bfsOfGraph(int v, vector<int> adj[]) {

        vector<int> ans;
        vector<int> vis(v+1, 0);

        for(int i=0;i<v;++i) {

                if(!vis[i]) {

                        queue<int> q;

                        q.push(i);
                        vis[i] = 1;

                        while(!q.empty()) {

                                int node = q.front();
                                q.pop();

                                ans.push_back(node);

                                for(auto it : adj[node]) {

                                        if(!vis[it]) {
                                                q.push(it);
                                                vis[it] = 1;
                                        }
                                }
                        }
                }
        }

        return ans;
}

void addEdge(vector < int > adj[], int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
}

int main() {

        vector<int> adj[5];

        addEdge(adj, 0, 1);
        addEdge(adj, 0, 2);
        addEdge(adj, 0, 3);
        addEdge(adj, 2, 4);


        vector <int> ans = bfsOfGraph(5,adj);


        for(int i=0;i<ans.size();++i) {
                cout << ans[i] << " ";
        }
        cout << endl;


        return 0;

}
