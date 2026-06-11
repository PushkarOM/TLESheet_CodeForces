#include<bits/stdc++.h>

// revisit

using namespace std;

int main(){
    
    int t;
    cin >> t;
    
    while(t--){
        
        long long a, b, c;
        cin >> a >> b >> c;
        
        // changing a
        if(2*b - c > 0 && (2*b - c)%a == 0){
            cout << "YES\n";
            continue;
        }
        
        if((a+c)%(2*b) == 0){
            cout << "YES\n";
            continue;
        }
        
        if(2*b - a > 0 && (2*b - a)%c == 0){
            cout << "YES\n";
            continue;
        }
        
        cout << "NO\n";
        
    }
    
}