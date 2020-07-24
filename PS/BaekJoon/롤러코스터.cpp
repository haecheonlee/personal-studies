/* reference: baekjoon/codeplus */

#include <iostream>
#include <algorithm>

using namespace std;

int A[1000][1000];
void append(string &s, char c, int count) {
	for(int i=0; i<count; i++) s+=c;
}

int main() {
	int N,M;
	cin>>N>>M;
	
	for(int i=0; i<N; i++) {
		for(int j=0; j<M; j++) cin>>A[i][j];
	}
	
	string s="";
	if(N%2==1) {
		for(int i=0; i<N; i++) {
			if(i%2==0) {
				append(s, 'R', M-1);
				if(i!=N-1) append(s, 'D', 1);
			} else {
				append(s, 'L', M-1);
				append(s, 'D', 1);
			}
		}
	} else if(M%2==1) {
		for(int j=0; j<M; j++) {
			if(j%2==0) {
				append(s, 'D', N-1);
				if(j!=M-1) append(s,'R',1);
			} else {
				append(s, 'U', N-1);
				append(s, 'R', 1);
			}
		}
	} else {
		int x,y;
		x=0;
		y=1;
		
		for(int i=0; i<N; i++) {
			for(int j=0; j<M; j++) {
				if((i+j)%2==1) {
					if(A[x][y]>A[i][j]) {
						x=i;
						y=j;
					}
				}
			}
		}
		
		int x1=0, y1=0;
		int x2=N-1, y2=M-1;
		string s2="";
		while(x2-x1>1) {
			if(x1/2<x/2) {
				append(s, 'R', M-1);
				append(s, 'D', 1);
				append(s, 'L', M-1);
				append(s, 'D', 1);
				x1+=2;
			}
			
			if(x/2<x2/2) {
				append(s2, 'R', M-1);
				append(s2, 'D', 1);
				append(s2, 'L', M-1);
				append(s2, 'D', 1);
				x2-=2;
			}
		}
		
		while(y2-y1>1) {
			if(y1/2<y/2) {
				append(s, 'D', 1);
				append(s, 'R', 1);
				append(s, 'U', 1);
				append(s, 'R', 1);
				y1+=2;
			}
			
			if(y/2<y2/2) {
				append(s2, 'D', 1);
				append(s2, 'R', 1);
				append(s2, 'U', 1);
				append(s2, 'R', 1);
				y2-=2;
			}
		}
		
		if(y==y1) {
			append(s, 'R', 1);
			append(s, 'D', 1);
		} else {
			append(s, 'D', 1);
			append(s, 'R', 1);
		}
		
		reverse(s2.begin(), s2.end());
		s+=s2;
	}
	
	cout<<s;
	
	return 0;
}
