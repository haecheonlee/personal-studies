#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
const int MAX=1e6;

int d[MAX];
bool check[MAX];

int main() {
	int n,k;
	cin>>n>>k;
	
	queue<int> q;
	queue<int> next;
	q.push(n);
	check[n]=true;
	d[n]=0;

	while(!q.empty()) {
		int now=q.front();
		q.pop();
		
		int jump=now*2;
		if(jump<MAX) {
			if(check[jump]==false) {
				check[jump]=true;
				d[jump]=d[now];
				q.push(jump);
			}
		}
		
		int prev=now-1;
		if(prev>=0) {
			if(check[prev]==false) {
				check[prev]=true;
				d[prev]=d[now]+1;
				next.push(prev);
			}
		}
		
		int forward=now+1;
		if(forward<MAX) {
			if(check[forward]==false) {
				check[forward]=true;
				d[forward]=d[now]+1;
				next.push(forward);
			}
		}
		
		if(q.empty()) {
			q=next;
			next=queue<int>();
		}
	}
	
	cout<<d[k];
	
	return 0;
}
