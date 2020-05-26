#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	priority_queue<int> l;
	priority_queue<int, vector<int>, greater<int>> r;
	
	int n;
	cin>>n;
	
	while(n--) {
		int x;
		cin>>x;
		
		if(l.empty() || r.empty()) l.push(x);
		else {
			if(x<=l.top()) l.push(x);
			else if(x>=r.top()) r.push(x);
			else l.push(x);
		}
		
		while(!(l.size()==r.size() || l.size()==r.size()+1)) {
			if(l.size()>r.size()) {
				r.push(l.top());
				l.pop();
			} else {
				l.push(r.top());
				r.pop();
			}
		}
		
		cout<<l.top()<<'\n';
	}

	return 0;
}
