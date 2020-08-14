/* reference: http://blog.naver.com/occidere/220854811310 */
#include <iostream>

using namespace std;

int d[41];

int main() {
	int N,M;
	cin>>N>>M;

	d[0]=d[1]=1;
	for(int i=2; i<=N; i++) d[i]=d[i-1]+d[i-2];
	
	int ans=1;
	int current=0;
	for(int i=0; i<M; i++) {
		int x;
		cin>>x;
		
		ans*=d[x-current-1];
		current=x;
	}
	
	ans*=d[N-current];
	cout<<ans;

	return 0;
}
