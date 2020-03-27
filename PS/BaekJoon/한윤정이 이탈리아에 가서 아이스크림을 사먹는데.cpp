#include <iostream>
#include <vector>

using namespace std;

int n,m,n1,n2;
bool check[201][201];
int ans=0;

void go(vector<int> list, int index) {
	if(list.size()==3) {
		for(int i=0; i<list.size(); i++) {
			for(int j=i+1; j<list.size(); j++) {
				if(check[list[i]][list[j]]) return;
			}
		}
		
		ans++;
		return;
	}
	
	if(index>n) return;
	list.push_back(index);
	go(list,index+1);
	list.pop_back();
	go(list,index+1);
}

int main() {
	cin>>n>>m;
	for(int i=0; i<m; i++) {
		cin>>n1>>n2;
		
		check[n1][n2]=true;
		check[n2][n1]=true;
	}

	go(vector<int>(), 1);
	cout<<ans;
	
	return 0;
}

/*
INPUT:
5 3
1 2
3 4
1 3

OUTPUT:
3
*/
