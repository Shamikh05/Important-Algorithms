#include <bits/stdc++.h>
using namespace std;

void perform_dijktra_algo(int n, int source, vector<pair<int, int>> adj[], vector<int> &dist) {

        priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int>>> pq;

        pq.push({0,source});
        dist[source] = 0;

        while(!pq.empty()) {

                auto it = pq.top();

                int distance = it.first;
                int node = it.second;

                for(auto it2 : adj[node]) {

                        int adjNode = it2.first;
                        int adjDist = it2.second;

                        int newDist = dist[node] + adjDist;

                        if(newDist < dist[adjNode]) {
                                pq.push({adjDist,adjNode});
                                dist[adjNode] = newDist;
                        }
                }

                pq.pop();
        }
}

int main() {

        int n=5, m=6, source=1;
	vector<pair<int,int> > g[n+1]; 	// assuming 1 based indexing of graph
	// Constructing the graph
	g[1].push_back({2,2});
	g[1].push_back({4,1});
	g[2].push_back({1,2});
	g[2].push_back({5,5});
	g[2].push_back({3,4});
	g[3].push_back({2,4});
	g[3].push_back({4,3});
	g[3].push_back({5,1});
	g[4].push_back({1,1});
	g[4].push_back({3,3});
	g[5].push_back({2,5});
	g[5].push_back({3,1});

        vector<int> dist(n+1,INT_MAX);

        perform_dijktra_algo(n, source, g, dist);

        for(int i=1;i<=n;++i) {
                cout << dist[i] << " ";
        }
        cout << endl;

        return 0;
}
