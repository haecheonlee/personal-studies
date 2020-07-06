/* BOJ */

#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
using pi=pair<int,int>;

int N,M;
bool check[101][101];
string a[101];
int dx[]={0,0,-1,1};
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
                if(a[nx][ny]=='#' && check[nx][ny]==false) {
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
    
    int T;
    cin>>T;
    
    while(T--) {
        memset(check,false,sizeof(check));
        
        int ans=0;
        cin>>N>>M;
    
        for(int i=0; i<N; i++) cin>>a[i];
        
        for(int i=0; i<N; i++) {
            for(int j=0; j<M; j++) {
                if(a[i][j]=='#' && check[i][j]==false) {
                    bfs(i,j);
                    ans++;
                }
            }
        }
        
        cout<<ans<<'\n';
    }

    return 0;
}
