/* reference: https://jaimemin.tistory.com/1072 */

#include <iostream>

using namespace std;
const int MAX=64;

int N;
int a[MAX][MAX];

void compress(int size, int x, int y) {
	if(size==1) {
		cout<<a[x][y];
		return;
	}
	
	bool zero=true, one=true;
	for(int i=x; i<x+size; i++) {
		for(int j=y; j<y+size; j++) {
			if(a[i][j]) zero=false;
			else one=false;
		}
	}
	
	if(zero) cout<<0;
	else if(one) cout<<1;
	else {
		cout<<"(";
		compress(size/2,x,y);
		compress(size/2,x,y+(size/2));
		compress(size/2,x+(size/2),y);
		compress(size/2,x+(size/2),y+(size/2));
		cout<<")";
	}
}

int main() {
	cin>>N;
	
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) scanf("%1d", &a[i][j]);
	}
	
	compress(N,0,0);
	
	return 0;
}
