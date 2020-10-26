#include <iostream>
#include <vector>

using namespace std;

int main() {    
    while(true) {
        int N;
        cin>>N;
        
        if(N==0) break;
        
        vector<string> ans;
        double mx=0.0;
        
        for(int i=0; i<N; i++) {
            string name;
            double h;
            cin>>name>>h;
            
            if(h>mx) ans.clear(), ans.push_back(name), mx=h;
            else if(h==mx) ans.push_back(name);
        }
        
        for(auto& name : ans) cout<<name<<' ';
        cout<<'\n';
    }
    
    return 0;
}
