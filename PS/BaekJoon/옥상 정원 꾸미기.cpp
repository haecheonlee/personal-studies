#include <iostream>
#include <stack>
using namespace std;

int main() {
	int n,a;
	cin>>n;
	
	long long cnt=0;
	stack<int> s;
	for(int i=0; i<n; i++) {
		cin>>a;
		
		while(!s.empty()) {
			if(s.top()<=a) s.pop();
			else break;
		}
		s.push(a);
		cnt+=s.size()-1;
	}
	cout<<cnt;
	
	return 0;
}
