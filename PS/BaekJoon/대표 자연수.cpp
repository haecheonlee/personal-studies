#include <iostream>
#include <algorithm>

using namespace std;

int a[20001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N;
	cin>>N;
	
	for(int i=1; i<=N; i++) cin>>a[i];
	sort(a+1,a+N+1);
	
	if(N%2) cout<<a[(N+1)/2];
	else cout<<a[N/2];

	return 0;
}
