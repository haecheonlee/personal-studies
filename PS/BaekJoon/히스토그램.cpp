#include <iostream>
#include <stack>
#define ll long long

using namespace std;

int main() {
	int n;
	cin>>n;
	
	ll a[n];
	for(int i=0; i<n; i++) cin>>a[i];
	
	ll ans=0;
	stack<int> s;
	for(int i=0; i<n; i++) {
		while(!s.empty() && a[s.top()]>a[i]) {
			auto height=a[s.top()];
			auto width=i;
			s.pop();
			
			if(!s.empty()) width=(i-s.top()-1);
			ans=max(ans, height*width);
		}
		s.push(i);
	}
	
	while(!s.empty()) {
		auto height=a[s.top()];
		auto width=n;
		s.pop();
		
		if(!s.empty()) width=(n-s.top()-1);
		ans=max(ans, height*width);
	}
	cout<<ans;
	
	return 0;
}
