#include <iostream>

using namespace std;

bool d[31][31][31][436];
char ans[32];
int n, k;

bool go(int i, int a, int b, int p) {
	if(i==n) {
		if(p==k) return true;
		else return false;
	}
	
	if(d[i][a][b][p]) return false;
	d[i][a][b][p]=true;
	
	ans[i]='A';
	if(go(i+1,a+1,b,p)) return true;
	
	ans[i]='B';
	if(go(i+1,a,b+1,p+a)) return true;
	
	ans[i]='C';
	if(go(i+1,a,b,p+a+b)) return true;
	
	return false;
}

int main() {
	cin>>n>>k;
	
	if(go(0,0,0,0)) cout<<ans;
	else cout<<-1;
	
	return 0;
}
