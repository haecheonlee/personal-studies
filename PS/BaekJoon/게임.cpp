#include <iostream>

using namespace std;
using ll=long long;

const ll MAX=1e9;

int getRate(ll games, ll win) {
	return (win*100)/games;
}

int main() {
	ll X,Y;
	cin>>X>>Y;
	
	int start_rate=getRate(X,Y);
	if(start_rate==getRate(X+MAX, Y+MAX)) {
		cout<<-1;
	}
	else {
		ll L=0, R=1e9;
		while(L+1<R) {
			ll M=(L+R)/2;
			if(start_rate==getRate(X+M,Y+M)) L=M;
			else R=M;
		}
		cout<<R;
	}

	return 0;
}
