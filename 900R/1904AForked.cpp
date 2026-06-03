#include<bits/stdc++.h>

using namespace std;



int main(){

    int t;
    cin >> t;

    while(t--){

        // co-ords for king and queen
        int a,b, xk, yk, xq, yq;
        cin >> a >> b >> xk >> yk >> xq >> yq;
        

        // generate all possible condition for king and queen
        set<pair<int,int>> posK, posQ;

        posK.insert({xk + a,yk + b});
        posK.insert({xk + a,yk - b});
        posK.insert({xk - a,yk + b});
        posK.insert({xk - a,yk - b});
        posK.insert({xk + b,yk + a});
        posK.insert({xk + b,yk - a});
        posK.insert({xk - b,yk + a});
        posK.insert({xk - b,yk - a});

        posQ.insert({xq + a,yq + b});
        posQ.insert({xq + a,yq - b});
        posQ.insert({xq - a,yq + b});
        posQ.insert({xq - a,yq - b});
        posQ.insert({xq + b,yq + a});
        posQ.insert({xq + b,yq - a});
        posQ.insert({xq - b,yq + a});
        posQ.insert({xq - b,yq - a});

        // Finding intersection Count
        int count_ = 0;

        for (auto p : posK) {
            if (posQ.find(p) != posQ.end()) {
                count_++;
            }
        }

        cout << count_ << "\n";
    }

}