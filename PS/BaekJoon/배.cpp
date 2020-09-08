#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N;
	cin>>N;
	
	vector<int> a(N);	// crane
	int a_mx=0;
	for(int i=0; i<N; i++) {
		cin>>a[i];
		a_mx=max(a_mx, a[i]);	
	}
	sort(a.begin(), a.end());
	
	int M;
	cin>>M;
	
	vector<int> b(M);	// box
	int b_mx=0;
	for(int i=0; i<M; i++) {
		cin>>b[i];
		b_mx=max(b_mx, b[i]);	
	}
	sort(b.begin(), b.end());

	if(a_mx<b_mx) {
		// the max weight of box is heavier than the max weight of crane
		cout<<-1;
	} else {
		int ans=0;
		while(b.size()) {
			ans++;
			
			for(int L=0; L<N; L++) {
        // find upper of a[L] (Crane's Weight) in the list of box
				auto it=upper_bound(b.begin(), b.end(), a[L]) - b.begin();
                
        // if heavier than any of the boxes, then decrease it by one
				if(it==b.size()) it--;
                   
        // match the max weight of box that can be handled by the current crane
				while(it >= 0 && b[it] > a[L]) it--;
				if(it>=0) b.erase(b.begin() + it);
			}
		}
		cout<<ans<<'\n';
	}

	return 0;
}
