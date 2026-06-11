#include<bits/stdc++.h>

using namespace std;

int findVal(string str,char ch, int len){
    int index_ = -1;
    for(int i = len-1; i>=0; i--){
        if(str[i] == ch){
            index_ = i;
            break;
        }
    }
    return index_;
}

int main(){

    int t;
    cin >> t;

    while(t--){
        string str;
        cin >> str;
        
        int len = str.length();
        int first0, first5;
        int second0, second5, second2, second7;

        // finding the first occurence either a 0 & 5 from the last
        first0 = findVal(str, '0', str.length());
        first5 = findVal(str, '5', str.length());

        // need to find 0 & 5 incase of first0
        if(first0 != -1){
            second0 = findVal(str, '0', first0);
            second5 = findVal(str, '5', first0);
        }
        else{
            second0 = -1;
            second5 = -1;
        }

        // similalry 2, 7
        if(first5 != -1){
            second2 = findVal(str, '2', first5);
            second7 = findVal(str, '7', first5);
        }
        else{
            second2 = -1;
            second7 = -1;
        }    

        int dist1 = INT_MAX, dist2 = INT_MAX, dist3 = INT_MAX, dist4 = INT_MAX;

        if(second0 != -1){
            dist1 = first0 - second0 - 1 + (len - 1 - first0);
        }

        if(second5 != -1){
            dist2 = first0 - second5 - 1 + (len - 1 - first0);    
        }
        
        if(second2 != -1){
            dist3 = first5 - second2 - 1 + (len - 1 - first5);
        }

        if(second7 != -1){
            dist4 = first5 - second7 - 1 + (len - 1 - first5);    
        }

        cout << min(dist1, min(dist2, min(dist3, dist4))) << "\n";
    }
}
