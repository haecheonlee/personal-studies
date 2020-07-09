/* BOJ */

#include <iostream>

using namespace std;

const int dirs[4][3][2] {
    { {0,0},{0,-1},{1,0} },
    { {0,0},{-1,0},{0,-1} },
    { {0,0},{-1,0},{0,1} },
    { {0,0},{1,0},{0,1} }
};

int ans=0;
int N,M;
int a[10][10];
bool check[10][10];

bool isPossible(int x, int y, int type) {
    for(int i=0; i<3; i++) {
        int nx=x+dirs[type][i][0];
        int ny=y+dirs[type][i][1];
        
        if(0<=nx && nx<N && 0<=ny && ny<M) {
            if(check[nx][ny]) return false;
        } else {
            return false;
        }
    }
    
    return true;
}

int update(int x, int y, int type, bool status) {
    int sum=0;
    
    for(int i=0; i<3; i++) {
        int nx=x+dirs[type][i][0];
        int ny=y+dirs[type][i][1];
        
        check[nx][ny]=status;
        
        if(i==0) sum+=(2*a[nx][ny]);
        else sum+=a[nx][ny];
    }
    
    return sum;
}

void go(int x, int y, int sum) {
    ans=max(ans, sum);
  
    for(int i=x-1; i<N; i++) {
        for(int j=y-1; j<M; j++) {
            if(check[i][j]) continue;
            for(int k=0; k<4; k++) {
                if(isPossible(i, j, k)==false) continue;
                sum+=update(i, j, k, true);
                go(i,j,sum);
                sum-=update(i, j, k, false);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>N>>M;

    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) cin>>a[i][j];
    }

    go(0,0,0);
    cout<<ans;
    
    return 0;
}
