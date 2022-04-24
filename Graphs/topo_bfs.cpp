#include <bits/stdc++.h>
using namespace std;

class Solution {
        void findTopoSort(int N, vector<int> &indegree, vector<int> &ans, vector<int> adj[]) {

                queue<int> q;

                for(int i=0;i<N;++i) {
                        if(indegree[i]==0)
                                q.push(i);
                }

                while(!q.empty()) {

                        int frontNum = q.front();

                        for(auto it : adj[frontNum]) {

                                indegree[it]--;

                                if(indegree[it]==0) {
                                        q.push(it);
                                }
                        }

                        q.pop();
                        ans.push_back(frontNum);
                }
        }
public:
        vector<int> topoSort(int N, vector<int> adj[]) {

                vector<int> indegree(N,0);

                for(int i=0;i<N;++i) {

                        for(int it : adj[i]) {
                                indegree[it]++;
                        }
                }

                vector<int> ans;

                findTopoSort(N,indegree,ans,adj);

                return ans;
        }
};

int main() {

        int N = 6;

        vector<int> adj[6];

        adj[5].push_back(2);
    	adj[5].push_back(0);
    	adj[4].push_back(0);
    	adj[4].push_back(1);
    	adj[3].push_back(1);
    	adj[2].push_back(3);

        Solution obj;

        vector<int> res = obj.topoSort(6, adj);

        cout << "Toposort of the given graph is : " << endl;

        for (int i=0;i<res.size();i++) {
                cout << res[i] << " ";
        }

        return 0;
}
