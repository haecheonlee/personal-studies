#include <iostream>

using namespace std;

int a[501][501];
int d[501];

int main() {
	int h,w,h1;
	cin>>h>>w;
	
	for(int i=0; i<h; i++) {
		for(int j=0; j<w; j++) a[i][j]=0;
	}
	
	for(int i=0; i<w; i++) {
		cin>>h1;
		d[i]=h1;
		
		do{
			a[h-h1][i]=1;
		} while(h1--);
	}

	pair<int,int> p{0,0};	// first-height, second-index
	for(int i=0; i<w; i++) {
		if(p.first==0) {
			p.first=d[i];
			p.second=i;
		}
		else {
			for(int j=p.second; j<i; j++) {
				int min_height=min(p.first,d[i]);
				for(int k=h; k>=(h-min_height); k--) {
					if(a[k][j]==0) a[k][j]=2;
				}	
			}
			
			if(p.first<=d[i]) {
				p.first=d[i];
				p.second=i;
			}
		}
	}
	
	int ans=0;
	for(int i=0; i<h; i++) {
		for(int j=0; j<w; j++) {
			if(a[i][j]==2) ans++;
		}
	}
	cout<<ans;
	
	return 0;
}

/*
INPUT:
4 8
3 1 2 3 4 1 1 2

OUTPUT:
5
*/
