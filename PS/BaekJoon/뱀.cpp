/* BOJ */

#include <iostream>

using namespace std;

int N,K,L;
int board[101][101];
int apple[101][101];
int direction[101][101];
int order[10001];
int hx,hy,tx,ty;    // position of head & tail
int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};
int len=1;

int change_direction(int current_direction, char order) {
    if(order=='D') {
        if(++current_direction==5) current_direction=1;
        return current_direction;
    } else {
        if(--current_direction==0) current_direction=4;
        return current_direction;
    }
}

bool is_outside(int x, int y) {
    if(x>N || x<=0 || y>N || y<=0) return true;
    return false;
}

bool is_apple(int x, int y) {
    if(apple[x][y]) {
        apple[x][y]=0;
        return true;
    }
    
    return false;
}

void update_tail() {
    // 1: up, 2: right, 3: down, 4: left
    
    // contains before tx, ty changes    
    if(direction[tx][ty]==1) {
        board[tx][ty]=0;
        tx--;
    } else if(direction[tx][ty]==2) {
        board[tx][ty]=0;
        ty++;
    } else if(direction[tx][ty]==3) {
        board[tx][ty]=0;
        tx++;
    } else if(direction[tx][ty]==4) {
        board[tx][ty]=0;
        ty--;  
    }
}

bool move() {  
    // 1: up, 2: right, 3: down, 4: left  
    if(direction[hx][hy]==1) {
        if(is_outside(hx-1,hy) || board[hx-1][hy]) return false;
        
        board[hx-1][hy]=1;
        direction[hx-1][hy]=direction[hx][hy];
        hx--;
        
        if(is_apple(hx, hy)==false) update_tail();
    } else if(direction[hx][hy]==2) {
        if(is_outside(hx,hy+1) || board[hx][hy+1]) return false;
        
        board[hx][hy+1]=1;
        direction[hx][hy+1]=direction[hx][hy];        
        hy++;
        
        if(is_apple(hx,hy)==false) update_tail();
    } else if(direction[hx][hy]==3) {
        if(is_outside(hx+1,hy) || board[hx+1][hy]) return false;
        
        board[hx+1][hy]=1;
        direction[hx+1][hy]=direction[hx][hy];        
        hx++;
        
        if(is_apple(hx,hy)==false) update_tail();
    } else if(direction[hx][hy]==4) {
        if(is_outside(hx,hy-1) || board[hx][hy-1]) return false;
        
        board[hx][hy-1]=1;
        direction[hx][hy-1]=direction[hx][hy];
        hy--;
        
        if(is_apple(hx,hy)==false) update_tail();
    }
    
    return true;
}

void print() {
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) cout<<board[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N>>K;
    
    for(int i=0; i<K; i++) {
        int px, py;
        cin>>px>>py;
        
        apple[px][py]=1;    // position of an apple
    }
    
    // direction changed based on time
    cin>>L;
    for(int i=0; i<L; i++) {
        int time;
        char dir;
        
        cin>>time>>dir;
        order[time]=dir;
    }
    
    // setting
    int current_time=0;
    
    board[1][1]=1;
    hx=hy=tx=ty=1;
    // 1: up, 2: right, 3: down, 4: left
    direction[1][1]=2;
    
    // game starts
    while(1) {
        current_time++;
        
        if(move()==false) {
            // game finished
            break;
        }
        
        // after x second is finished, change direction if there's a request
        if(order[current_time]) {
            direction[hx][hy]=change_direction(direction[hx][hy],order[current_time]);
        }
    }
    
    cout<<current_time;
    
    return 0;
}
