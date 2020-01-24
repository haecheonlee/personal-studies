#include <iostream>
#include <unordered_map>

using namespace std;

string compare(string max_key, string num) {
	if(max_key.find('-') != string::npos && num.find('-') == string::npos) {
		return max_key;
	}
	else if(max_key.find('-') == string::npos && num.find('-') != string::npos) {
		return num;
	}
	else {
		if(max_key.find('-') != string::npos && num.find('-') != string::npos) {
			if(max_key.size()<num.size()) return num;
			else if(max_key.size()>num.size()) return max_key;
			else {
				for(int i=0; i<max_key.size(); i++) {
					if(max_key[i]>num[i]) return max_key;
					else if(max_key[i]<num[i]) return num;
				}
			}
		} else if(max_key.find('-') == string::npos && num.find('-') == string::npos) {
			if(max_key.size()<num.size()) return num;
			else if(max_key.size()>num.size()) return max_key;
			else {
				for(int i=0; i<max_key.size(); i++) {
					if(max_key[i]<num[i]) return max_key;
					else if(max_key[i]>num[i]) return num;
				}
			}
		}
	}
}

int main() {
	int n;
	cin>>n;
	
	unordered_map<string, int> m;
	long long max_value=0;
	string max_key="";
	while(n--) {
		string num;
		cin>>num;
		
		m[num]++;
		if(max_value<m[num]) {
			max_value=m[num];
			max_key=num;
		}
		else if(max_value==m[num]) { 
			max_key=compare(max_key, num);
		}
	}

	cout<<max_key;

	return 0;
}

/*
boj.kr/11652

INPUT:
6
1
2
1
2
1
2

OUTPUT:
1
*/
