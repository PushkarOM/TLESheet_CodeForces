#include<bits/stdc++.h>

using namespace std;

int main(){

        int n;
        cin >> n;

        string str;
        cin >> str;

        int posr = str.length()-1, posl;
        char smallest = str[str.length()-1];
        bool flag = false;

        for(int i = str.length()-1; i >=0; i--){
            if(str[i] < smallest){
                posr = i;
                smallest = str[i];
            }

            if(str[i] > smallest){
                posl = i;
                flag = true;
                break;
            }
        }

        if(flag){
            cout << "YES\n" << posl + 1<< " " << posr + 1 << "\n";
        }
        else{
            cout << "NO\n";
        }

}