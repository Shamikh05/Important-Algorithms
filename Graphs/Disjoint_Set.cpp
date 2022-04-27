#include <bits/stdc++.h>
using namespace std;

vector<int> parent(101,-1);
vector<int> rank(101,0);

int findPar(int node) {

        if(node==parent[node])
                return node;

        return parent[node] = findPar(parent[node]);
}

void union(int u, int v) {

        u = findPar(u);
        v = findPar(v);

        if(rank[u] < rank[v]) {
                parent[u] = v;
        }
        else if(rank[v] < rank[u]) {
                parent[v] = u;
        }
        else {
                parent[v] = u;
                ++rank[u];
        }
}

int main() {

        // Making every node its own parent
        // Assuming that every node has its own component
        for(int i=0;i<=100;++i) {
                parent[i] = i;
        }

        // Total number of operations
        int t;
        cin >> t;

        while(t--) {
                // Two nodes to be united
                int u, v;
                cin >> u >> v;

                union(u, v);
        }

        return 0;
}
