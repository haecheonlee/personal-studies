#include <iostream>
#include <vector>

using namespace std;

const int MAX=9e3+1;
const int SIZE=10;

int N,M;
int a[SIZE];
bool is_not_prime[MAX];
bool possible_sum[MAX];

void go(int idx, int cnt, int sum) {
	if(cnt==M) {
		possible_sum[sum]=true;
		return;
	}
	if(idx>=N) return;
	
	go(idx+1, cnt+1, sum+a[idx]);
	go(idx+1, cnt, sum);
}

int main() {
	is_not_prime[0]=is_not_prime[1]=true;
	for(int i=2; i<=MAX; i++) {
		if(is_not_prime[i]==false) {
			for(int j=2; j*i<=MAX; j++) is_not_prime[j*i]=true;
		}
	}
	
	cin>>N>>M;
	
	for(int i=0; i<N; i++) cin>>a[i];
	
	go(0,0,0);

	vector<int> ans;
	for(int i=2; i<=MAX; i++) {
		if(is_not_prime[i]==false && possible_sum[i]==true) ans.push_back(i);
	}
	
	if(ans.size()) for(auto& x : ans) cout<<x<<' ';
	else cout<<-1;

	return 0;
}
