#include <iostream>
#include <vector>

using namespace std;

const int MAX=1e5;

vector<int> preprocessing(const vector<int>& a) {
	int M=a.size();
	vector<int> pi(M, 0);
	
	int j=0;
	for(int i=1; i<M; i++) {
		while(j>0 && a[i]!=a[j]) j=pi[j-1];
		
		if(a[i]==a[j]) {
			pi[i]=j+1;
			j++;
		} else {
			pi[i]=0;
		}
	}
	
	return pi;
}

int kmp(const vector<int>& a, vector<int>& p) {
	vector<int> pi=preprocessing(p);

	int L=a.size();
	int M=p.size();
	int j=0;
	
	int ans=0;
	for(int i=0; i<L; i++) {
		while(j>0 && a[i]!=p[j]) j=pi[j-1];
		
		if(a[i]==p[j]) {
			if(j==M-1) {
				j=pi[j];
				ans++;
			} else {
				j++;
			}
		}
	}
	
	return ans-1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N;
	cin>>N;
	
	vector<int> a(N), b(N);
	for(int i=0; i<N; i++) {
		cin>>a[i];
		b[N-i-1]=a[i];	
	}

	vector<int> pa=preprocessing(a);
	vector<int> pb=preprocessing(b);
	
	// find longest one
	vector<int> La(a.end() - pa[N-1], a.end());
	
	vector<int> Lb;
	
	pair<int,int> longest=make_pair(-1,0);
	for(int i=0; i<N; i++) {
		if(pb[i]>longest.first) {
			longest.first=pb[i];
			longest.second=i;
		}
	}
	
	for(int i=longest.second; i>=longest.second-longest.first+1; i--) {
		Lb.push_back(b[i]);
	} 
		
	vector<int> p=((La.size()>Lb.size()) ? La : Lb);
	if(p.size()==0) cout<<-1;
	else cout<<p.size()<<' '<<kmp(a, p);
	
	return 0;
}
