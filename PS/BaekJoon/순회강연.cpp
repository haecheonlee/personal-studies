#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Lecture {
	int p,d;	
};

bool cmp(const Lecture &u, const Lecture &v) {
	return u.d>v.d;
}

int main() {
	int n;
	cin>>n;
	
	vector<Lecture> a(n);
	for(int i=0; i<n; i++) cin>>a[i].p>>a[i].d;
	sort(a.begin(), a.end(), cmp);
	
	int ans=0;
	int index=0;
	priority_queue<int> q;
	
	for(int i=10000; i>=1; i--) {
		while(index<n && a[index].d==i) {
			q.push(a[index].p);
			index+=1;
		}
		
		if(!q.empty()) {
			ans+=q.top();
			q.pop();
		}
	}
	
	cout<<ans;
	
	return 0;
}

/*
INPUT:
7
20 1
2 1
10 3
100 2
8 2
5 20
50 10

OUTPUT:
185
*/
