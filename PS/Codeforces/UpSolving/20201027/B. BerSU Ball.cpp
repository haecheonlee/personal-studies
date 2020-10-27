#include <iostream>
#include <algorithm>

using namespace std;

const int MAX=1e2+5;

int a[MAX], b[MAX];

int main() {
	int N;
	cin>>N;
	
	for(int i=0; i<N; i++) cin>>a[i];
	sort(a, a+N);

	int M;
	cin>>M;

	for(int i=0; i<M; i++) cin>>b[i];
	sort(b, b+M);

	int ans=0, i=0, j=0;
	while(i<N && j<M) {
		if(abs(a[i]-b[j])<=1) ans++, i++, j++;
		else if(a[i]>b[j]) j++;
		else i++;
	}
	cout<<ans;

	return 0;
}
