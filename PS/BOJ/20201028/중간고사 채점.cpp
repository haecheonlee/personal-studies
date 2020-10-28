#include <iostream>

using namespace std;
using pii=pair<int,int>;

int main() {
	int N,M;
	cin>>N>>M;

	int a[N];
	for(int i=0; i<N; i++) cin>>a[i];

	int n, sum;
	for(int i=0; i<M; i++) {
		int num;
		cin>>num;

		int total=0;
		for(int j=0; j<N; j++) {
			char c;
			cin>>c;

			if(c=='O') total += a[j];
		}
		
		if(total>sum) n=num, sum=total;
		else if(total==sum && n>num) n=num;
	}

	cout<<n<<' '<<sum;

	return 0;
}
