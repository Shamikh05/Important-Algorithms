/*
Input:
5 12
0 1 2
0 3 6
1 0 2
1 2 3
1 3 8
1 4 5
2 1 3
2 4 7
3 0 6
3 1 8
4 1 5
4 2 7

Expected Output:
0 - 1
1 - 2
0 - 3
1 - 4
*/


#include <bits/stdc++.h>
using namespace std;

int main() {

        // N is number of nodes and m is number of edges
        int N, m;
        cin >> N >> m;

        vector<pair<int, int> > adj[N];

        for(int i=0;i<m;++i) {
                int a, b, wt;
                cin >> a >> b >> wt;
                adj[a].push_back({b,wt});
                adj[b].push_back({a,wt});
        }

        vector<int> key(N, INT_MAX);
        vector<int> parent(N, -1);
        vector<int> mst(N,0);

        key[0] = 0;

        priority_queue< pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;

        // Prims Algorithm starts from here

        pq.push({0, 0});

        for(int i=0;i<N-1;++i) {

                int minKeyIdx = pq.top().second;
                pq.pop();

                mst[minKeyIdx] = 1; // Including minKeyIdx into MST

                // Exploring the adjacent nodes of minKeyIdx
                for(auto it : adj[minKeyIdx]) {

                        int node = it.first;
                        int weight = it.second;

                        if(mst[node]==0 and weight < key[node]) {
                                pq.push({key[node], node});
                                key[node] = weight;
                                parent[node] = minKeyIdx;
                        }
                }
        }

        for(int i=1;i<N;++i) {
                cout << parent[i] << " - " << i << endl;
        }

        return 0;
}
