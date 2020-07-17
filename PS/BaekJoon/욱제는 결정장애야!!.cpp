#include <iostream>
#include <cstring>

using namespace std;

int a[100001];

int main() {
	memset(a,-1,sizeof(a));
	
	int N;
	cin>>N;
	
	int len=N*2;
	int cnt=0, ans=0;
	for(int i=0; i<len; i++) {
		int x;
		cin>>x;
		
		if(a[x]==-1) {
			a[x]=0;
			cnt++;
		} else if(a[x]==0) {
			a[x]=1;
			cnt--;
		}
		
		ans=max(ans,cnt);
	}
	
	cout<<ans;
	
	return 0;
}
