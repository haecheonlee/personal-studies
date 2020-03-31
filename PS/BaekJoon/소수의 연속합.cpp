#include <iostream>
#include <vector>

using namespace std;

bool check[4000001];

int main() {
	int n;
	cin>>n;
	
	vector<int> primes;
	for(int i=2; i<=4000000; i++) {
		if(check[i]==false) {
			primes.push_back(i);
			for(int j=i+i; j<=4000000; j+=i) check[j]=true;
		}
	}
	
	int i=0,j=0,sum=0,count=0;
	while(i<primes.size() || j<primes.size()) {
		if(sum<=n && i<primes.size()) sum+=primes[i++];
		else sum-=primes[j++];
		
		if(sum==n) count++;
	}
	
	cout<<count;
	
	return 0;
}

/*
INPUT:
53

OUTPUT:
2
*/
