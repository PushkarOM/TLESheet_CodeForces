#include<bits/stdc++.h>

using namespace std;

int main(){
    
    int t;
    cin >> t;

    while(t--){
        int n, k , x, rem, nCpy;
        cin >> n >> k >> x;
        nCpy = n;

        vector<int> arr;

        if(x != 1){
            cout << "YES\n";
            cout << n << "\n";
            for(int i = 0 ; i < n; i++){
                cout << 1 << " ";
            }
        }
        else{
            if(n%2 == 0){
                if(k >= 2){
                    cout << "YES\n";
                    int temp = n / 2;
                    cout << temp << "\n";
                    for(int i = 0; i < temp; i++){
                        cout << 2 << " ";
                    }
                }
                else{
                    cout << "NO";
                }
            }
            else{
                if(k >= 3){
                    
                    cout << "YES\n";
                    int temp = (n - 3) / 2;
                    cout << temp+1 << "\n";
                    cout << 3 << ' ';
                    for(int i = 0; i < temp; i++){
                        cout << 2 << " ";
                    }

                }
                else{
                    cout << "NO";
                }
            }
        }
        cout << "\n";
    }

}