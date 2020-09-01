#include <iostream>

using namespace std; 

const int MAX=5e2+1;

bool area[MAX][MAX];

int main() {
	int N;
	cin>>N;
	
	while(N--) {
		int x1,y1,x2,y2;
		cin>>x1>>y1>>x2>>y2;
		
		for(int x=x1; x<x2; x++) {
			for(int y=y1; y<y2; y++) area[x][y]=true;
		}
	}
	
	int ans=0;
	for(int i=0; i<MAX; i++) {
		for(int j=0; j<MAX; j++) ans+=area[i][j];
	}
	cout<<ans;
	
	return 0;
}
