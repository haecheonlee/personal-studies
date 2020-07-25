#include <iostream>

using namespace std;

int N;
int A[11];
int P[11];

bool check() {
	for(int i=1; i<N; i++) {
		if(A[i-1]!=A[i]) return false;
	}
	
	return true;
}

int main() {
	int T;
	cin>>T;
	
	while(T--) {
		cin>>N;
		
		for(int i=0; i<N; i++) {
			cin>>A[i];
			if(A[i]%2) A[i]++;	
		}
		
		int count=0;
		while(1) {
			if(check()) break;
			
			for(int i=0; i<N; i++) {
				if(i==N-1) P[0]=A[i]/2;
				else P[i+1]=A[i]/2;
			}
			
			for(int i=0; i<N; i++) {
				A[i]=A[i]-(A[i]/2)+P[i];
				if(A[i]%2) A[i]++;
			}
			
			count++;
		}
		cout<<count<<'\n';
	}

	return 0;
}
