#include <iostream>
#include <deque>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin>>n;
	
	deque<int> q;
	while(n--) {
		string s;
		int x;
		
		cin>>s;
		if(s=="push") {
			cin>>x;
			q.push_back(x);
		} else if(s=="pop") {
			if(q.empty()==false) {
				cout<<q.front()<<'\n';
				q.pop_front();
			} else {
				cout<<-1<<'\n';
			}
		} else if(s=="size") {
			cout<<q.size()<<'\n';
		} else if(s=="empty") {
			if(q.empty()) cout<<1<<'\n';
			else cout<<0<<'\n';
		} else if(s=="front") {
			if(q.empty()) cout<<-1<<'\n';
			else cout<<q.front()<<'\n';
		} else if(s=="back") {
			if(q.empty()) cout<<-1<<'\n';
			else cout<<q.back()<<'\n';
		}
	}

	return 0;
}
