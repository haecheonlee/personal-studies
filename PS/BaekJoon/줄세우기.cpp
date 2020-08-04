#include <iostream>

using namespace std;

int d[201];

int main() {
	int N;
	cin>>N;
	
	int a[N];
	for(int i=0; i<N; i++) cin>>a[i];
	
	int longest=0;
	for(int i=0; i<N; i++) {
		d[i]=1;
		for(int j=0; j<i; j++) {
			if(a[i]>a[j]) d[i]=max(d[i], d[j]+1);
		}
		
		longest=max(longest, d[i]);
	}
	
	cout<<N-longest;
	return 0;
}
