#include <iostream>

#define EAST 1
#define WEST 2
#define NORTH 3
#define SOUTH 4

using namespace std;

int N,M,x,y,K;
int board[21][21];
int dice[]={0,0,0,0,0,0};
int position[]={0,4,5,1,3,2};

/*
      indexes of a dice: index is set to 0 when the game begins

        1
      3 0 2        =>        0 4 5 1 3 2
        4
        5
    
      How the position of a dice changes
      EAST         =>        3 4 2 1 5 0
      WEST         =>        2 4 3 1 0 5
      NORTH        =>        4 5 1 0 3 2
      SOUTH        =>        1 0 4 5 3 2 
*/

bool is_possible(int dir) {
	if(dir==EAST) {
		if(y+1>=M) return false;
	} else if(dir==WEST) {
		if(y-1<0) return false;
	} else if(dir==NORTH) {
		if(x-1<0) return false;
	} else if(dir==SOUTH) {
		if(x+1>=N) return false;
	}
	
	return true;
}

void rotate(int dir) {
    if(dir==EAST) {
    	int temp=position[0];
    	
    	position[0]=position[4];
    	position[4]=position[2];
    	position[2]=position[5];
    	position[5]=temp;
    	
    	y++;
    } else if(dir==WEST) {
    	int temp=position[5];
    	
    	position[5]=position[2];
    	position[2]=position[4];
    	position[4]=position[0];
    	position[0]=temp;
    	
    	y--;
    } else if(dir==NORTH) {
    	int temp=position[0];
		
		position[0]=position[1];
		position[1]=position[2];
		position[2]=position[3];
		position[3]=temp;
		
		x--;
    } else if(dir==SOUTH) {
    	int temp=position[3];
		
		position[3]=position[2];
		position[2]=position[1];
		position[1]=position[0];
		position[0]=temp;
		
		x++;
    }
}

int main() {
    cin>>N>>M>>x>>y>>K;

    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) cin>>board[i][j];
    }
	
    for(int i=0; i<K; i++) {
        int dir;
        cin>>dir;

	if(is_possible(dir)) {
		rotate(dir);
			
		// 0: top, 2: bottom
		int &top=dice[position[0]];
		int &bottom=dice[position[2]];
			
		if(board[x][y]==0) board[x][y]=bottom;
		else {
			bottom=board[x][y];
			board[x][y]=0;	
		}
			
		cout<<top<<'\n';
	}
    }
	
    return 0;
}
