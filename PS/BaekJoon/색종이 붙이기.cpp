// reference: https://11001.tistory.com/21

#include <iostream>

using namespace std;
const int MAX=10;

int ans=1e9;
int a[MAX][MAX];
int paper[]={0,0,0,0,0};

bool check(int x,int y, int k) {
	// check if this size works
	
	for(int i=0; i<=k; i++) {
		for(int j=0; j<=k; j++) {
			if(a[x+i][y+j]==0) return false;
		}
	}
	
	return true;
}

void update(int x, int y, int k, int status) {
	for(int i=0; i<=k; i++) {
		for(int j=0; j<=k; j++) a[x+i][y+j]=status;
	}
}

void go(int x, int y, int used) {
	while(a[x][y]==0) {
		if(++y>=MAX) {
			if(++x>=MAX) {
				// reached a[MAX][MAX]
				ans=min(ans, used);
				return;
			}
			y=0;
		}
	}

	if(ans<=used) return;
	
	for(int k=4; k>=0; k--) {
		if(x+k>=MAX || y+k>=MAX || paper[k]==5) continue;
		
		if(check(x,y,k)) {
			update(x,y,k,0);
			paper[k]++;
			
			go(x,y,used+1);
			
			update(x,y,k,1);
			paper[k]--;
		}
	}
}

int main() {
	int total=0;
	
	for(int i=0; i<MAX; i++) {
		for(int j=0; j<MAX; j++) {
			cin>>a[i][j];
			
			if(a[i][j]) total++;
		}
	}

	if(total==MAX*MAX) {
		cout<<4;
		return 0;
	} else {
		go(0,0,0);
		
		if(ans==1e9) cout<<-1;
		else cout<<ans;
	}

	return 0;
}
