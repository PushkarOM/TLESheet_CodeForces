#include<bits/stdc++.h>

using namespace std;


// Treat "ab" as +1 and "ba" as -1.
// All opposite transitions cancel each other out, so AB-BA
// depends only on the first and last characters.
// If endpoints differ, change one of them to make them equal.

int main(){
    int t;
    cin >> t;

    while(t--){

        string str;
        cin >> str;

        if(str[0] == str[str.length()-1]) cout << str << "\n";
        else{
            str[str.length()-1] = str[0];
            cout << str << "\n";
        }

    }
}