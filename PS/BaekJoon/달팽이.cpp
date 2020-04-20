#include <iostream>

using namespace std;

int main() {
	int n,k;
	cin>>n>>k;
	
	int a[n][n] {0};
	int x=0,y=0,current=n*n;
	int height=n, width=n-1;
	bool down=true,right=true;
	
	while(current>0) {
		if(down) {
			for(int i=0; i<height; i++) a[x++][y]=current--;
			down=false;
			x-=1;
			y+=1;
		} else {
			for(int i=0; i<height; i++) a[x--][y]=current--;
			down=true;
			x+=1;
			y-=1;
		}
		height--;
		
		if(right) {
			for(int i=0; i<width; i++) a[x][y++]=current--;
			right=false;
			y-=1;
			x-=1;
		} else {
			for(int i=0; i<width; i++) a[x][y--]=current--;
			right=true;
			y+=1;
			x+=1;
		}
		width--;
	}
	
	int px,py;
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			cout<<a[i][j]<<" ";	
			if(a[i][j]==k) {
				px=i;
				py=j;
			}
		}
		cout<<'\n';
	}
	cout<<px+1<<" "<<py+1;
	
	return 0;
}

/*
INPUT:
7
35

OUTPUT:
49 26 27 28 29 30 31
48 25 10 11 12 13 32
47 24 9 2 3 14 33
46 23 8 1 4 15 34
45 22 7 6 5 16 35
44 21 20 19 18 17 36
43 42 41 40 39 38 37
5 7
*/
