#include <iostream>
#include <queue>

using namespace std;

int a[100001];
bool check[100001];

int main() {
	int N;
	cin>>N;
	
	for(int i=1; i<=N; i++) cin>>a[i];
	
	int s;
	cin>>s;

	queue<int> q;
	q.push(s);
	check[s]=true;
	
	while(!q.empty()) {
		int current=q.front();
		q.pop();
		
		int move=a[current];
		
		int next=move+current;
		if(next<=N) {
			if(check[next]==false) {
				check[next]=true;
				q.push(next);
			}
		}
		
		int prev=current-move;
		if(prev>=1) {
			if(check[prev]==false) {
				check[prev]=true;
				q.push(prev);
			}
		}
	}

	int ans=0;
	for(int i=1; i<=N; i++) {
		if(check[i]) ans++;
	}
	cout<<ans;

	return 0;
}
