#include <iostream>

using namespace std;

char a[51][51];
int n,m;

int check(int x, int y, char k) {
	int count=0;

	for(int i=1; i<max(n,m); i++) {
		if(x+i<n && y+i<m) {
			int right=a[x+i][y];
			int lbot=a[x][y+i];
			int rbot=a[x+i][y+i];
			
			if(k==right && right==lbot && lbot==rbot) {
				count=i;
			}
		} else {
			break;
		}
	}
	
	return count;
}

int main() {
	cin>>n>>m;
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) cin>>a[i][j];
	}

	int ans=0;
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			ans=max(check(i,j,a[i][j]),ans);
		}
	}

	cout<<(ans+1)*(ans+1);

	return 0;
}

/*
INPUT:
3 5
42101
22100
22101

OUTPUT:
9
*/
