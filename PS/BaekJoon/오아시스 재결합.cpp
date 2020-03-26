#include <iostream>
#include <stack>

using namespace std;

int main() {
	int n;
	cin>>n;

	int a[n];
	for(int i=0; i<n; i++) cin>>a[i];

	stack<pair<int,int>> s;	
	long long ans=0;
	for(int i=0; i<n; i++) {
		pair<int,int> p{a[i],1};
		while(!s.empty()) {
			if(s.top().first<=a[i]) {
				if(s.top().first==a[i]) p.second+=s.top().second;
				ans+=s.top().second;
				s.pop();
			} else {
				break;
			}
		}
		
		if(!s.empty()) ans+=1LL;
		s.push(p);
	}
	
	cout<<ans;

	return 0;
}

/*
INPUT:
7
2
4
1
2
2
5
1

OUTPUT:
10
*/
