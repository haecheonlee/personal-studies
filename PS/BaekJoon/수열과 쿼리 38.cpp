#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int m,n;
	cin>>m;

	long long x;
	long long sum1=0, sum2=0;	
	while(m--) {
		cin>>n;
		
		if(n==1) {
			cin>>x;
			
			sum1+=x;
			sum2=sum2^x;
		} else if(n==2) {
			cin>>x;
			
			sum1-=x;
			sum2=sum2^x;
		}
		else if(n==3) cout<<sum1<<'\n';
		else if(n==4) cout<<sum2<<'\n';
	}

	return 0;
}

/*
INPUT:
12
1 3
1 1
1 4
3
4
1 1
3
4
2 1
2 4
3
4

OUTPUT:
8
6
9
7
4
2
*/
