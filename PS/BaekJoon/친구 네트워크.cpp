#include <iostream>
#include <vector>
#include <map>

using namespace std;

int p[200001];
int count[200001];
map<string,int> list;	// list of indexex for string

int Find(int x) {
	if(x==p[x]) return x;
	else return p[x]=Find(p[x]);
}

void Union(int x, int y) {
	x=Find(p[x]);
	y=Find(p[y]);
	
	if(x!=y) {
		count[y]+=count[x];
		p[x]=y;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int T;
	cin>>T;
	
	while(T--) {
		int N;
		cin>>N;
		
		// reset
		for(int i=0; i<=200000; i++) {
			p[i]=i;
			count[i]=0;	
		}
		list.clear();
		
		int index=1;
		while(N--) {
			string p1,p2;
			cin>>p1>>p2;
			
			int &idx1=list[p1]; 
			int &idx2=list[p2];
			
			if(idx1==0) {
				idx1=index;
				count[index]++;
				index++;
			}
			
			if(idx2==0) {
				idx2=index;
				count[index]++;
				index++;
			}
			
			idx1=Find(idx1);
			idx2=Find(idx2);
			
			Union(idx1,idx2);

			cout<<count[idx2]<<'\n';
		}
	}
	
	return 0;
}
