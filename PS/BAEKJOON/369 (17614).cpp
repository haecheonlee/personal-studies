#include <iostream>

using namespace std;

int main()
{
    int N;
    cin>>N;
    
    int total_claps = 0;
    for(int i=1; i<=N; i++) {
        string s = to_string(i);
        
        for(int x=0; x<s.size(); x++) {
            int index = (int)s[x] - 48;
            if(index%3 == 0 && index != 0) total_claps++;
        }
    }

    cout<<total_claps<<endl;
    
    return 0;
}
