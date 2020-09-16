/* reference: 유클리드 기하학과 택시 기하학의 차이 */

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
using pi=pair<double, double>;

const int MAX=1e3+5e1;

vector<int> a[MAX];
vector<pi> p;
int d[MAX];

int main() {
	double V,M;
	cin>>V>>M;
	
	double sx,sy,ex,ey,x,y;
	cin>>sx>>sy>>ex>>ey;
	
	p.push_back(make_pair(sx, sy));
	while(cin>>x>>y) p.push_back(make_pair(x, y));
	p.push_back(make_pair(ex, ey));
	
	double L=(V*M*60);
	L*=L;
	for(int i=0; i<p.size(); i++) {
		for(int j=i+1; j<p.size(); j++) {
			double px=p[i].first-p[j].first;
			double py=p[i].second-p[j].second;
			
			double dist=(px*px)+(py*py);
			if(dist<L) {
				a[i].push_back(j);
				a[j].push_back(i);
			}
		}
	}
	
	memset(d, -1, sizeof(d));
	queue<int> q;
	q.push(0);
	d[0]=0;
	
	while(!q.empty()) {
		int x=q.front();
		q.pop();
		
		for(auto& y :a[x]) {
			if(d[y]==-1 || d[y]>d[x]+1) {
				d[y]=d[x]+1;
				q.push(y);
			}
		}
	}
	
	int ans=d[p.size()-1];
	if(ans==-1) cout<<"No.";
	else cout<<"Yes, visiting "<<ans-1<<" other holes.";

	return 0;
}
