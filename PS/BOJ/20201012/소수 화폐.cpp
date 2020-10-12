#include <iostream>
#include <vector>

using namespace std;

const int MAX=4e4+1;
const int MOD=123456789;

vector<int> a;
bool check[MAX];
int d[MAX];

int main() {
	for(int i=2; i<MAX; i++) {
		
		if(check[i]==false) {
			a.push_back(i);
			for(int j=2; j*i<MAX; j++) check[j*i]=true;
		}
	}	

	int N;
	cin>>N;

	d[0]=1;
	for(int i=0; i<a.size(); i++) {
		for(int j=0; j<=N; j++) {
			if(j-a[i]>=0) d[j]+=d[j-a[i]];
			d[j]%=MOD;
		}
	}
	
	cout<<d[N];

	return 0;
}
