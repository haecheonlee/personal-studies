#include <iostream>

using namespace std;

const int MAX=1<<6;

int N;
int a[MAX][MAX];
bool check[MAX][MAX];

int main() {
	cin>>N;
	
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) cin>>a[i][j];
	}

	check[0][0]=true;
	for(int x=0; x<N; x++) {
		for(int y=0; y<N; y++) {
			if(check[x][y]) {
				// down
				int nx=x+a[x][y];
				// right
				int ny=y+a[x][y];
				
				if(0<=nx && nx<N) check[nx][y]=true;
				if(0<=ny && ny<N) check[x][ny]=true;
			}
		}
	}
	
	if(check[N-1][N-1]) cout<<"HaruHaru";
	else cout<<"Hing";
	
	return 0;
}
