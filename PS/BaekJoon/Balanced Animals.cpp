/* reference: JUDGE */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N;
	cin>>N;

	vector<int> a(N);
	for(int i=0; i<N; i++) cin>>a[i];
	sort(a.begin(), a.end());

	int L=0, R=N-1;
	int left_group=0, right_group=0;
	int ans=-1;
	
	while(L<=R) {
		if(left_group==right_group && a[L]==a[R]) {
			ans=a[L];
			break;
		}
		
		if(left_group<=right_group) left_group+=a[L++];
		else right_group+=a[R--];
	}
	
	if(ans==-1) ans=a[L-1]+1;
	cout<<ans;
	
	return 0;
}
