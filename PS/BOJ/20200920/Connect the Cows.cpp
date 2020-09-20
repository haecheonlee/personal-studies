#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using pi=pair<int,int>;

const int MAX=15;
const int NORTH=1, EAST=2, SOUTH=3, WEST=4;

vector<pi> a;
bool adj[MAX][MAX];

inline int get_direction(int first, int second) {
	pi u=a[first];
	pi v=a[second];
	
	if(u.first==v.first && u.second<v.second) return EAST;
	else if(u.first==v.first && u.second>v.second) return WEST;
	else if(u.first<v.first && u.second==v.second) return SOUTH;
	else return NORTH;
}

int main() {
	int N;
	cin>>N;
	
	// start from origin
	a.push_back({0,0});
	
	for(int i=0; i<N; i++) {
		int x,y;
		cin>>x>>y;
		a.push_back({x,y});
	}
	
	// return to origin
	a.push_back({0,0});

	for(int i=0; i<a.size(); i++) {
		for(int j=i+1; j<a.size(); j++) {
			if(i==j) continue;
			if(a[i].first==a[j].first || a[i].second==a[j].second) {
				adj[i][j]=adj[j][i]=true;
			}
		}
	}
	
	// list of indexes
	vector<int> list;
	for(int i=0; i<a.size(); i++) list.push_back(i);

	int ans=0;
	do {
		bool is_possible=true;

		for(int i=0; i<list.size()-1; i++) {
			if(i<=list.size()-3) {
				int current_dir=get_direction(list[i], list[i+1]);
				int next_dir=get_direction(list[i+1], list[i+2]);
			
				if(current_dir==next_dir) {
					is_possible=false;
					break;
				}	
			}
			
			if(adj[list[i]][list[i+1]]==false) {
				is_possible=false;
				break;
			}
		}
		if(is_possible) ans++;
	} while(next_permutation(list.begin()+1, list.end()-1));
	cout<<ans;
	
	return 0;
}
