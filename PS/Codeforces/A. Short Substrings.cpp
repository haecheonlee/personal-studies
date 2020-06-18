#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin>>t;
    
    while(t--) {
        string s;
        cin>>s;

        string x=s.substr(0,2);
        for(int i=3; i<s.size(); i+=2) x+=s[i];
        cout<<x<<endl;
    }
        
	return 0;
}
