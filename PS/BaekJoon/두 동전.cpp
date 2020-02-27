#include <iostream>

using namespace std;

int n,m;
string a[20];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int go(int step, int x1, int y1, int x2, int y2) {
	if(step==11) return -1;
	bool f1=false, f2=false;
	
	if(x1<0 || x1>=n || y1<0 || y1>=m) f1=true;
	if(x2<0 || x2>=n || y2<0 || y2>=m) f2=true;
	if(f1 && f2) return -1;
	if(f1 || f2) return step;
	
	int result=-1;
	for(int k=0; k<4; k++) {
		int nx1=x1+dx[k];
		int ny1=y1+dy[k];
		int nx2=x2+dx[k];
		int ny2=y2+dy[k];
		
		if(0<=nx1 && nx1<n && 0<=ny1 && ny1<m && a[nx1][ny1]=='#') {
			nx1=x1;
			ny1=y1;
		}
		if(0<=nx2 && nx2<n && 0<=ny2 && ny2<m && a[nx2][ny2]=='#') {
			nx2=x2;
			ny2=y2;
		}
		
		int temp=go(step+1,nx1,ny1,nx2,ny2);
		if(temp==-1) continue;
		if(result==-1 || result>temp) result=temp;
	}
	return result;
}

int main() {
	cin>>n>>m;
	int x1,y1,x2,y2;
	x1=y1=x2=y2=-1;
	for(int i=0; i<n; i++) {
		cin>>a[i];
		
		for(int j=0; j<m; j++) {
			if(a[i][j]=='o') {
				if(x1==-1) {
					x1=i;
					y1=j;
				} else {
					x2=i;
					y2=j;
				}
				a[i][j]='.';
			}
		}
	}
	
	cout<<go(0,x1,y1,x2,y2);
	return 0;
}

/*
boj.kr/16197

INPUT:
6 2
..
..
..
o#
o#
##

OUTPUT:
3
*/
