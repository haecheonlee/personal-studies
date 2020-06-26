/* BOJ */

#include <iostream>
#include <queue>
#include <tuple>
#include <iomanip>

using namespace std;
using pi=pair<int,int>;
using pii=tuple<int,int,int>;

int N,M,T;
int a[1001][1001];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int cx1, cx2, cy1, cy2;

inline bool isNotCleaner(int x, int y) {
    if(x==cx1 && y==cy1) return false;
    if(x==cx2 && y==cy2) return false;
    
    return true;
}

void update(queue<pii> &dust) {
    while(!dust.empty()) {
        int x,y,z;
        tie(x,y,z)=dust.front();
        dust.pop();
        
        a[x][y]+=z;
    }
}

void fill(queue<pii> &dust) {
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            if(a[i][j]>=5) dust.push(make_tuple(i,j,a[i][j]));
        }
    }
}

void counter_clockwise() {
    int x=cx1, y=cy1;
    
    int prev_value=0;
    
    // right
    for(int i=y+1; i<M; i++) {
        int temp=a[x][i];
        a[x][i]=prev_value;
        prev_value=temp;
    }
    
    // up
    for(int i=x-1; i>=0; i--) {
        int temp=a[i][M-1];
        a[i][M-1]=prev_value;
        prev_value=temp;
    }
    
    // left
    for(int i=M-2; i>=0; i--) {
        int temp=a[0][i];
        a[0][i]=prev_value;
        prev_value=temp;
    }
    
    // down
    for(int i=1; i<x; i++) {
        int temp=a[i][0];
        a[i][0]=prev_value;
        prev_value=temp;
    }    
}

void clockwise() {
    int x=cx2, y=cy2;
    
    int prev_value=0;
    // right
    for(int i=y+1; i<M; i++) {
        int temp=a[x][i];
        a[x][i]=prev_value;
        prev_value=temp;
    }
    
    // down
    for(int i=x+1; i<N; i++) {
        int temp=a[i][M-1];
        a[i][M-1]=prev_value;
        prev_value=temp;
    }
    
    // left
    for(int i=M-2; i>=0; i--) {
        int temp=a[N-1][i];
        a[N-1][i]=prev_value;
        prev_value=temp;
    }
    
    // up
    for(int i=N-2; i>x; i--) {
        int temp=a[i][0];
        a[i][0]=prev_value;
        prev_value=temp;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N>>M>>T;
    
    queue<pii> dust;
    cx1=cx2=cy1=cy2=-1;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cin>>a[i][j];
            if(a[i][j]==-1) {
                if(cx1==-1) {
                    cx1=i;
                    cy1=j;
                } else {
                    cx2=i;
                    cy2=j;
                }
            }
            if(a[i][j]>=5) dust.push(make_tuple(i,j,a[i][j]));
        }
    }
    
    while(T--) {
        // dust spread
        queue<pii> next_dust;
        while(!dust.empty()) {
            int x,y,z;
            tie(x,y,z)=dust.front();
            dust.pop();

            int spreaded=0;            
            for(int k=0; k<4; k++) {
                int nx=x+dx[k];
                int ny=y+dy[k];
                
                if(0<=nx && nx<N && 0<=ny && ny<M) {
                    if(isNotCleaner(nx,ny)) {
                        next_dust.push(make_tuple(nx,ny,z/5));
                        spreaded+=z/5;
                    }
                }
            }
            
            // add current position of dust with subtraction of total of spreaded amount
            next_dust.push(make_tuple(x,y,-spreaded));
        }
        
        update(next_dust);
        
        // cleaner works
        counter_clockwise();
        clockwise();
        
        fill(dust);
    }

    int ans=0;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            if(a[i][j]>=1) ans+=a[i][j];
        }
    }
    cout<<ans;

    return 0;
}
