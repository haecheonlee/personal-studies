/* reference: old code of boj.kr/1655 */
#include <iostream>
#include <queue>

using namespace std;

int main() {
	int T;
	cin>>T;
	
	while(T--) {
		int N;
		cin>>N;
		
		cout<<(N+1)/2<<'\n';
		
		priority_queue<int> LQ;
		priority_queue<int, vector<int>, greater<int>> RQ;
		
		for(int i=1; i<=N; i++) {
			int x;
			cin>>x;
			
			if(LQ.empty() || RQ.empty()) {
				LQ.push(x);
			} else {
				if(x<=LQ.top()) LQ.push(x);
				else if(x>=RQ.top()) RQ.push(x);
				else LQ.push(x);
			}
			
			while(!(LQ.size()==RQ.size() || LQ.size()==RQ.size()+1)) {
				if(LQ.size()>RQ.size()) {
					RQ.push(LQ.top());
					LQ.pop();
				} else {
					LQ.push(RQ.top());
					RQ.pop();
				}
			}
			
			if(i%2) cout<<LQ.top()<<' ';
			if(i%20==0) cout<<'\n';
		}
		
		cout<<'\n';
	}
	
	return 0;
}
