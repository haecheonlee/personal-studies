/* reference: snowflake */

#include <iostream>
#include <algorithm>

using namespace std;
using pii=pair<int,int>;

const int MAX=1e6+1;

pii a[MAX];
int ans[MAX];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N;
	cin>>N;
	
	for(int i=0; i<N; i++) { cin>>a[i].first; a[i].second=i; }
	sort(a, a+N);
	
	int pos=0;
	for(int i=1; i<N; i++) {
		if(a[i].first != a[i-1].first) pos++;
		ans[a[i].second]=pos;
	}
	
	for(int i=0; i<N; i++) cout<<ans[i]<<' ';
}
