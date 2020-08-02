#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll=long long;

int main() {
	int N;
	cin>>N;
	
	ll ans=0;
	vector<int> A;
	int minus=0, zero=0;
	for(int i=0; i<N; i++) {
		int x;
		cin>>x;
		
		if(x==1) {
			ans++;
		}
		else {
			if(x<0) minus++;
			else if(x==0) zero++;

			if(x!=0) A.push_back(x);
		}
	}
	
	sort(A.begin(), A.end());
	
	// check minus
	if(minus%2==0) {
		for(int i=0; i<minus; i+=2) ans+=(1LL*A[i]*A[i+1]);
	} else {
		for(int i=0; i<minus-1; i+=2) ans+=(1LL*A[i]*A[i+1]);
		if(zero==0) ans+=A[minus-1];
	}
	for(int i=A.size()-1; i>=minus; i-=2) {
		if(i==minus) ans+=A[i];
		else ans+=(1LL*A[i]*A[i-1]);
	}
	
	cout<<ans;
	
	return 0;
}
