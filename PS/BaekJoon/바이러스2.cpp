#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int t,k;

vector<int> preprocessing(vector<int> &p) {
	int m=p.size();
	
	vector<int> fail(m);
	fail[0]=0;
	
	int j=0;
	for(int i=1; i<m; i++) {
		while(j>0 && p[i]!=p[j]) j=fail[j-1];
		
		if(p[i]==p[j]) {
			fail[i]=j+1;
			j++;
		} else {
			fail[i]=0;
		}
	}

	return fail;
}

int kmp(vector<int> &s, vector<int> &p) {
	vector<int> fail=preprocessing(p);
	
	int n=s.size();
	int m=p.size();
	int j=0;
	
	for(int i=0; i<n; i++) {
		while(j>0 && s[i]!=p[j]) j=fail[j-1];
		
		if(s[i]==p[j]) {
			if(j==k-1) return i;
			else j++;
		}
	}

	return -1;
}

inline void find_virus(vector<int> &first, vector<int> &sec, vector<int> &pos) {
	for (int i=0; i<=first.size()-k; i++) {
		vector<int> suffix=vector<int>(first.begin()+i, first.end());		//	i...a[0].size()
		int index=kmp(sec,suffix);

		if(index!=-1) pos.push_back(index);
	}
}

int main() {
	cin>>t>>k;
	
	vector<int> a[t];	
	for(int i=0; i<t; i++) {
		int n;
		cin>>n;
		
		while(n--) {
			int x;
			cin>>x;
			
			a[i].push_back(x);
		}
	}

	// find intersection in length of k between a[0] and a[1]
	vector<int> pos;
	find_virus(a[0], a[1], pos);
	
	// for reverse case
	reverse(a[0].begin(), a[0].end());
	find_virus(a[0], a[1], pos);

	if(pos.size()==0) cout<<"NO";
	else {
		bool check=false;
		for(int i=0; i<pos.size(); i++) {
			int start=pos[i]-(k-1);
			int end=pos[i]+1;
			
			vector<int> suffix1=vector<int>(a[1].begin()+start, a[1].begin()+end);
			vector<int> suffix2=vector<int>(a[1].begin()+start, a[1].begin()+end);
			reverse(suffix2.begin(), suffix2.end());
			
			check=true;
			for(int j=2; j<t; j++) {
				int index1=kmp(a[j], suffix1);
				int index2=kmp(a[j], suffix2);

				// not found
				if(index1==-1 && index2==-1) {
					check=false;
					break;
				}
			}
			
			if(check) break;
		}
		
		if(check) cout<<"YES";
		else cout<<"NO";
	}

	return 0;
}
