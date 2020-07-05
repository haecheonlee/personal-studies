/* BOJ */

#include <iostream>
#include <queue>

using namespace std;
using pi=pair<int,int>;

int N,M;
string a[1001];
bool check[1001][1001];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

void bfs(int sx, int sy) {
    queue<pi> q;
    q.push(make_pair(sx,sy));
    check[sx][sy]=true;
    
    while(!q.empty()) {
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        
        for(int k=0; k<4; k++) {
            int nx=x+dx[k];
            int ny=y+dy[k];
            
            if(0<=nx && nx<N && 0<=ny && ny<M) {
                if(check[nx][ny]==false && a[nx][ny]=='0') {
                    check[nx][ny]=true;
                    q.push(make_pair(nx,ny));
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N>>M;
    
    for(int i=0; i<N; i++) cin>>a[i];
    
    for(int j=0; j<M; j++) {
        if(check[0][j]==false && a[0][j]=='0') {
            bfs(0,j);
        }
    }
    
    for(int i=0; i<M; i++) {
        if(check[N-1][i]) {
            cout<<"YES";
            return 0;
        }
    }
    
    cout<<"NO";
    
    return 0;
}
