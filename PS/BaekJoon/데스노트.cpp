/* reference: baekjoon/codeplus */

#include <iostream>
#include <cstring>

using namespace std;

int a[1000];
int d[1000][1002];
int N,M;

int go(int index, int cnt) {
	if(index==N) return 0;
	
	int &ans=d[index][cnt];
	if(ans!=-1) return ans;
	
	// next line
	int space=(M-(cnt-1));
	int cost=space*space;
	ans=go(index+1, a[index]+1)+cost;
	
	// current line
	if(cnt+a[index]<=M) {
		int cur=go(index+1, cnt+a[index]+1);
		if(ans>cur) ans=cur;
	}
	
	return ans;
}

int main() {
	cin>>N>>M;
	
	for(int i=0; i<N; i++) cin>>a[i];
	memset(d,-1,sizeof(d));
	cout<<go(1,a[0]+1);

	return 0;
}
