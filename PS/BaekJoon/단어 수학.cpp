#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
char alpha[256];

int main() {
	int n;
	cin>>n;
	
	vector<string> vec(n);
	vector<char> letters;
	int value=9;
	
	for(int i=0; i<n; i++) {
		cin>>vec[i];
		for(auto l : vec[i]) letters.push_back(l);
	}

	sort(letters.begin(), letters.end());
	letters.erase(unique(letters.begin(), letters.end()), letters.end());

	int m=letters.size();
	vector<int> values;
	for(int i=9; i>9-m; i--) values.push_back(i);
	sort(values.begin(), values.end());
	
	int result=0;
	do {
		int sum=0;
		for(int i=0; i<m; i++) alpha[letters[i]]=values[i];
		
		for(string &s : vec) {
			long long current=0;
			for(char &c : s) {
				current=current*10+alpha[c];
			}
			sum+=current;
		}
		result=max(result,sum);
	} while(next_permutation(values.begin(), values.end()));

	cout<<result;

	return 0;
}

/*
boj.kr/1339

INPUT:
2
GCF
ACDEB

OUTPUT:
99437
*/
