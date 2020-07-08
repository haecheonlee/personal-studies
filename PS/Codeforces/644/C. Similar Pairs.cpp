#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int main() {
	int T;
	cin>>T;
	
	while(T--) {
		int N;
		cin>>N;
		
		int a[N];
		int even, odd, cnt;
		even=odd=cnt=0;
		for(int i=0; i<N; i++) {
			cin>>a[i];
			
			if(a[i]%2==0) even++;
			else odd++;
		}
		
		sort(a,a+N);
		
		stack<int> stk;
		for(int i=0; i<N; i++) {
			if(stk.empty()) {
				stk.push(a[i]);
			}
			else {
				if(a[i]-stk.top()==1) {
					cnt++;
					stk.pop();
				} else {
					stk.push(a[i]);
				}
			}
		}

		if(even%2==0 && odd%2==0) cout<<"YES\n";
		else if(cnt && even%2!=0 && odd%2!=0) cout<<"YES\n";
		else cout<<"NO\n";
	}
	
	return 0;
}
