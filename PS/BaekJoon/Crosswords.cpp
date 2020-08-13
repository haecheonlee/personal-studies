#include <iostream>

using namespace std;

char s[51][51];
bool check[51][51];

int main() {
	int N,M;
	cin>>N>>M;
	
	for(int i=1; i<=N; i++) {
		for(int j=1; j<=M; j++) cin>>s[i][j];
	}
	
	int total=0;
	for(int x=1; x<=N; x++) {
		for(int y=1; y<=M; y++) {
			// horizontal
			int py=y-1;
			int ny=y+2;
			if(py<=0 || (py>=1 && s[x][py]=='#')) {
				if(s[x][y]=='.' && s[x][y+1]=='.' && s[x][y+2]=='.') check[x][y]=true;
			}
			
			// vertical
			int px=x-1;
			int nx=x+2;
			if(px<=0 || (px>=1 && s[px][y]=='#')) {
				if(s[x][y]=='.' && s[x+1][y]=='.' && s[x+2][y]=='.') check[x][y]=true;
			}
			
			if(check[x][y]) total++;
		}
	}
	
	cout<<total<<'\n';
	for(int i=1; i<=N; i++) {
		for(int j=1; j<=M; j++) {
			if(check[i][j]) cout<<i<<" "<<j<<'\n';
		}
	}
	
	return 0;
}
