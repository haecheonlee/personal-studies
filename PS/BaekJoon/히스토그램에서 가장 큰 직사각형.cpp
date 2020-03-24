#include <iostream>
#include <stack>

using namespace std;

int main() {
	int n;
	while(1) {
		cin>>n;
		if(n==0) break;
		
		long long a[n];
		for(int i=0; i<n; i++) cin>>a[i];
		
		stack<long long> s;
		long long ans=0;
		for(int i=0; i<n; i++) {
			while(!s.empty() && a[s.top()]>a[i]) {
				auto height=a[s.top()];
				auto width=i;
				s.pop();
				if(!s.empty()) width=(i-s.top()-1);
				if(ans<height*width) ans=height*width;
			}
			s.push(i);
		}
		
		while(!s.empty()) {
			auto height=a[s.top()];
			auto width=n;
			s.pop();
			if(!s.empty()) width=(n-s.top()-1);
			if(ans<height*width) ans=height*width;
		}
		
		cout<<ans<<'\n';
	}
	
	return 0;
}

/*
INPUT:
7 2 1 4 5 1 3 3
4 1000 1000 1000 1000
0

OUTPUT:
8
4000
*/
