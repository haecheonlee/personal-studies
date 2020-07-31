/* reference: baekjoon/codeplus */

#include <iostream>

using namespace std;
using ll=long long;

int A[10000];
int P,N;

int main() {
	cin>>P>>N;
	
	for(int i=0; i<N; i++) cin>>A[i];
	
	ll left=0;
	ll right=2e9*1e6;

	while(left<=right) {
		ll mid=(left+right)/2;
		ll begin, end;
		
		begin=0;
		end=N;
		
		for(int i=0; i<N; i++) end+=mid/A[i];
		begin=end;
		for(int i=0; i<N; i++) {
			if(mid%A[i]==0) begin-=1;
		}
		begin+=1;
		
		if(P<begin) {
			right=mid-1;
		} else if(P>end) {
			left=mid+1;
		} else {
			for(int i=0; i<N; i++) {
				if(mid%A[i]==0) {
					if(P==begin) {
						cout<<i+1;
						return 0;
					}
					begin+=1;
				}
			}
		}
	}

	return 0;
}
