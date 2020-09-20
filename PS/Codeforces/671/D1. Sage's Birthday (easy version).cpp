#include <iostream>
#include <algorithm>
 
using namespace std;
 
int main() {
	int N;
	cin>>N;
	
	int a[N];
	for(int i=0; i<N; i++) cin>>a[i];
	sort(a, a+N);	
	
	int ans[N];
	int K=N;
	if(K%2==0) K--;
	int m=K/2;
	
	int x=0;
	for(int i=1; i<K; i+=2) ans[i]=a[x++];
	x=m;
	for(int i=0; i<K; i+=2) ans[i]=a[x++];
	
	if(K!=N) ans[N-1]=a[N-1];
	
	cout<<m<<'\n';
	for(int i=0; i<N; i++) cout<<ans[i]<<' ';
	
	return 0;
}
