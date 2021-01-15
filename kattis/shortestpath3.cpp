#include <iostream>
#include <algorithm>
#include <iterator>
#include <set>
#include <queue>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <chrono>

using namespace std;

void dfs(vector<vector<pair<int, int> > > &adj, vector<int> &shortest, int startNode){
    if (shortest[startNode] == 2e9){
        return;
    }
    shortest[startNode] = 2e9;
    for (int q=0; q<adj[startNode].size(); q++){
        dfs(adj, shortest, adj[startNode][q].first);
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    //auto start = high_resolution_clock::now(); 
    //freopen("input.in", "r", stdin);
    int n, m, q, s;
    int u, v, w;
    int currNode, nextNode, currWeight, nextWeight;
    while (cin >> n >> m >> q >> s){
        if (n==0){
            break;
        }
        vector<pair<pair<int, int>, int> > edge;
        vector<int> shortest(n, 1e9);
        vector<vector<pair<int, int> > > adj(n);
        for (int a=0; a<m; a++){
            cin >> u >> v >> w;
            adj[u].push_back(make_pair(v, w));
        }
        shortest[s] = 0;
        bool relaxed;
        // one pass bellman
        for (int b=0; b<n; b++){
            relaxed = true;
            for (int a=0; a<n; a++){
                if (shortest[a] == 1e9) continue;
                for (int x=0; x<adj[a].size(); x++){
                    currNode = a;
                    nextNode = adj[a][x].first;
                    currWeight = adj[a][x].second;
                    nextWeight = shortest[currNode] + currWeight;
                    if (nextWeight < shortest[nextNode]){
                        shortest[nextNode] = nextWeight;
                        relaxed = false;
                    }
                }
            }
            if (relaxed) break;
        }
        for (int a=0; a<n; a++){
            if (shortest[a] == 1e9) continue;
            for (int x=0; x<adj[a].size(); x++){
                currNode = a;
                nextNode = adj[a][x].first;
                currWeight = adj[a][x].second;
                nextWeight = shortest[currNode] + currWeight;
                if (nextWeight < shortest[nextNode] && shortest[nextNode] != 2e9){
                    dfs(adj, shortest, nextNode);
                }
            }
        }
        int query;
        while (q--){
            cin >> query;
            if (shortest[query] == 2e9){
                cout << "-Infinity" << "\n";
            }
            else if (shortest[query] == 1e9){
                cout << "Impossible" << "\n";
            }
            else{
                cout << shortest[query] << "\n";
            }
        }
        cout << "\n";
    }
}