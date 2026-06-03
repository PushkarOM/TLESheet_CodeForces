#include<bits/stdc++.h>

using namespace std;

int main(){

    int t;
    cin >> t;

    while(t--){

        int n;
        cin >> n;


        int count = 0;
        int inc = 1;
        
        int digit = 0;
        int temp = n;
        while(temp){
            temp /= 10;
            digit++;
        }
        if(n < 10) count = n;
        else{
            count = 9*(digit-1);
            count += n/pow(10,digit-1);
        }

        cout << count << "\n";
    }

}