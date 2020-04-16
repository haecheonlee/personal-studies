/* Topological Sort for Directed Acyclic Graph */
/* boj.kr/2252 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> list[32001];
int in_degree[32001] {0};
int n,m,from,to;

int main(){
    cin>>n>>m;
    
    for(int i=0; i<m; i++) {
        cin>>from>>to;
        
        list[from].push_back(to);
        in_degree[to]+=1;
    }
    
    queue<int> q;
    for(int i=1; i<=n; i++) {
        if(in_degree[i]==0) q.push(i);
    }
    
    while(!q.empty()) {
        int current=q.front();
        q.pop();
        
        cout<<current<<" ";
        for(auto &next : list[current]) {
            in_degree[next]-=1;
            if(in_degree[next]==0) q.push(next);
        }
    }
    
    return 0;
}
