/* reference: https://degurii.tistory.com/27 */

#include <iostream>

using namespace std;
using ll=long long;

const int MAX=65;

ll d[65] {1};

int main() {
	int N;
	cin>>N;
	
	d[1]=1, d[2]=3;
	for(int i=3; i<=N; i++) {
		if(i%2==0) d[i]=d[i-1] * 2 + 1;
		else d[i]=d[i-1] * 2 - 1;
	}
	cout<<d[N];
	
	return 0;
}
