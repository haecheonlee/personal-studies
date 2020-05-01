#include <iostream>
#include <cstring>
#include <tuple>

using namespace std;

int a[10][10];
bool c[10][10];
bool c2[10][10];
bool c3[10][10];
bool domino[10][10];
int n=9;
int dx[]={0,1};
int dy[]={1,0};

pair<int,int> convert(string s) {
	return make_pair(s[0]-'A',s[1]-'1');
}

int square(int x, int y) {
	return (x/3)*3+(y/3);
}

bool can(int x, int y, int num) {
	return c[x][num]==false && c2[y][num]==false && c3[square(x,y)][num]==false;
}

void check(int x, int y, int num, bool what) {
	c[x][num]=what;
	c2[y][num]=what;
	c3[square(x,y)][num]=what;
}

bool check_range(int x, int y) {
	return 0<=x && x<n && 0<=y && y<n;
}

bool go(int z) {
	if(z==81) {
		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++) cout<<a[i][j];
			cout<<'\n';
		}
		return true;
	}
	
	int x=z/n;
	int y=z%n;
	if(a[x][y]!=0) return go(z+1);
	else {
		for(int k=0; k<2; k++) {
			int nx=x+dx[k];
			int ny=y+dy[k];
			
			if(!check_range(nx,ny)) continue;
			if(a[nx][ny]!=0) continue;
			
			for(int i=1; i<=9; i++) {
				for(int j=1; j<=9; j++) {
					if(i==j) continue;
					if(domino[i][j]) continue;
					
					if(can(x,y,i) && can(nx,ny,j)) {
						check(x,y,i,true);
						check(nx,ny,j,true);
						domino[i][j]=domino[j][i]=true;
						a[x][y]=i;
						a[nx][ny]=j;
						
						if(go(z+1)) return true;
						
						check(x,y,i,false);
						check(nx,ny,j,false);
						domino[i][j]=domino[j][i]=false;
						a[x][y]=a[nx][ny]=0;
					}
				}
			}
		}
	}
	return false;
}

int main() {
	int t=1;
	
	while(true) {
		memset(c,false,sizeof(c));
		memset(c2,false,sizeof(c2));
		memset(c3,false,sizeof(c3));
		memset(domino,false,sizeof(domino));
		memset(a,0,sizeof(a));
        
		int m;
		cin>>m;
		if(m==0) break;
		
		// set up
		for(int i=0; i<m; i++) {
			int n1,n2;
			string s1,s2;
			
			cin>>n1>>s1>>n2>>s2;
			
			int x1,y1,x2,y2;
			tie(x1,y1)=convert(s1);
			tie(x2,y2)=convert(s2);
			a[x1][y1]=n1;
			a[x2][y2]=n2;
			domino[n1][n2]=domino[n2][n1]=true;
			check(x1,y1,n1,true);
			check(x2,y2,n2,true);
		}
		
		// solve
		for(int i=1; i<=9; i++) {
			string s;
			cin>>s;
			
			int x,y;
			tie(x,y)=convert(s);
			a[x][y]=i;
			check(x,y,i,true);
		}
		cout<<"Puzzle "<<t++<<'\n';
		go(0);
	}

	return 0;
}

/*
INPUT:
10
6 B2 1 B3
2 C4 9 C3
6 D3 8 E3
7 E1 4 F1
8 B7 4 B8
3 F5 2 F6
7 F7 6 F8
5 G4 9 G5 
7 I8 8 I9
7 C9 2 B9
C5 A3 D9 I4 A9 E5 A2 C6 I1
11
5 I9 2 H9
6 A5 7 A6
4 B8 6 C8
3 B5 8 B4
3 C3 2 D3
9 D2 8 E2
3 G2 5 H2
1 A2 8 A1
1 H8 3 I8
8 I3 7 I4
4 I6 9 I7
I5 E6 D1 F2 B3 G9 H7 C9 E5
0

OUTPUT:
Puzzle 1
872643195
361975842
549218637
126754983
738169254
495832761
284597316
657381429
913426578
Puzzle 2
814267593
965831247
273945168
392176854
586492371
741358629
137529486
459683712
628714935
*/
