#include <iostream>
#include <vector>

using namespace std;

bool check[1000001];
vector<int> primes;

int main() {
	int n;
	cin>>n;
	
	for(int i=2; i<=1000000; i++) {
		if(check[i]==false) {
			primes.push_back(i);
			for(int j=i+i; j<=1000000; j+=i) check[j]=true;
		}
	}
	
	while(n--) {
		long long s;
		cin>>s;
		
		bool valid=true;
		for(auto &p : primes) {
			if(s%p==0) { 
				cout<<"NO\n";
				valid=false;
				break;
			}
		}
		if(valid) cout<<"YES\n";
	}

	return 0;
}

/*
INPUT:
