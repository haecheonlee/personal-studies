/* reference: https://suuntree.tistory.com/62 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N,K;
vector<int> a;

bool check(int M) {
	int i=0, cnt=0;
	while(cnt<K && i<N) {
		i=upper_bound(a.begin(), a.end(), a[i]+M*2)-a.begin();
		cnt++;
	}
	return i==N;
}

int main() {
	cin>>N>>K;
	
	a.resize(N);
	for(int i=0; i<N; i++) cin>>a[i];
	sort(a.begin(), a.end());
	
	int ans=0;
	int L=0, R=1e9;
	while(L<=R) {
		int M=(L+R)/2;
		if(check(M)) {
			ans=M;
			R=M-1;
		} else {
			L=M+1;
		}
	}
	cout<<ans;
	
	return 0;
}
