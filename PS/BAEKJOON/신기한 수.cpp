#include <iostream>

using namespace std;

int main()
{
    int N;
    cin>>N;
    
    int total = 0;
    for(int i=1; i<=N; i++) {
        string s = to_string(i);
        
        int sum = 0;
        for(int i=0; i<s.size(); i++) {
            sum += (int)s[i] - 48;
        }
        
        if((i % sum) == 0) total++;
    }
    
    cout<<total<<endl;

    return 0;
}
