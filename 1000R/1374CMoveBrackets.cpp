#include<bits/stdc++.h>

using namespace std;


int main(){
    int t;
    cin >> t;

    while(t--){

        int n;
        cin >> n;
        string str;
        cin >> str;

        stack<char> st;
        
        int count = 0;
        
        for(char it : str){
            if(it == '('){
                st.push(it);
            }
            else if(!st.empty() && st.top() == '('){
                st.pop();
                count++;
            }
        }

        cout << n/2 - count << "\n";

    }
}