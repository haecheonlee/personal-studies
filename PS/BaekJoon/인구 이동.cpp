/* BOJ */

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
using pi=pair<int,int>;

vector<vector<pi>> list;
vector<int> total;
bool check[51][51];
int a[51][51];
int N,L,R;
int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};

void bfs(int sx, int sy) {    
    vector<pi> sub_list;
    
    queue<pi> q;
    q.push(make_pair(sx,sy));
    int sum=0;

    while(!q.empty()) {
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        
        for(int k=0; k<4; k++) {
            int nx=x+dx[k];
            int ny=y+dy[k];
            
            if(0<=nx && nx<N && 0<=ny && ny<N) {                
                int diff=abs(a[x][y]-a[nx][ny]);
                if(diff>=L && diff<=R) {
                    if(check[nx][ny]==false) {
                        check[nx][ny]=true;
                        sum+=a[nx][ny];
                        sub_list.push_back(make_pair(nx,ny));
                        q.push(make_pair(nx,ny));
                    }
                }
            }
        }
    }
    
    if(sub_list.size()>=2) {
        sum=sum/sub_list.size();
        total.push_back(sum);
        list.push_back(sub_list);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N>>L>>R;
    
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) cin>>a[i][j];
    }
    
    int ans=0;
    while(1) {
        memset(check,false,sizeof(check));
        list.clear();
        total.clear();
        
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                if(check[i][j]==false) bfs(i,j);
            }
        }
                
        if(list.size()>0) {            
            for(int i=0; i<list.size(); i++) {
                for(auto p : list[i]) a[p.first][p.second]=total[i];
            }
            
            ans++;
        } else {
            break;
        }
    }
    
    cout<<ans;
        
    return 0;
}
