#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

bool check[101];
int cnt=0;
int ans=0;

int main() {
	int n,k;
	cin>>n>>k;
	
	vector<int> a(k);
	for(int i=0; i<k; i++) cin>>a[i];
	
	set<int> container;
	for(int i=0; i<k; i++) {
		// if already plugged in, we ignore
		if(check[a[i]]==true) continue;

		if(cnt==n) {
			// not using later on
			bool found=false;
			for(auto it : container) {
				if(find(a.begin()+i, a.end(), it)==a.end()) {
					container.erase(it);
					check[it]=false;
					found=true;
					break;
				}
			}
		
			// distance far
			if(found==false) {
				int current_value=-1, distance=-1;
				
				for(auto it : container) {
					int x=i;
					while(x<k) {
						if(a[x]==it) break;
						x++;
					}
					
					if(distance==-1 || distance<x) {
						current_value=it;
						distance=x;
					}
				}
				
				check[current_value]=false;
				container.erase(current_value);
			}
			
			container.insert(a[i]);
			check[a[i]]=true;
			ans++;
		} else {
			container.insert(a[i]);
			check[a[i]]=true;
			cnt+=1;
		}
	}
	cout<<ans;
	
	return 0;
}

/*
INPUT:
2 7
2 3 2 3 1 2 7

OUTPUT:
2
*/
