#include<bits/stdc++.h>
using namespace std;
int fact(int num){
    int ans = 1;
    for(int i=2; i<=num; i++){
        ans*=i;
    }
    return ans;
}

int main(){

    int n = 5;
    for(int i=0; i<n; i++){
        for(int space=0; space<(n-i-1); space++){
            cout << " ";
        }
        for(int j=0; j<=i; j++){
            cout << fact(i)/(fact(j) * fact(i-j)) << " ";
        }cout <<endl;
    }
    // vector<vector<int>> pascal (n);
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<=i; j++){
    //         if(j==0 || j==i){
    //             pascal[i].push_back(1);
    //         }else{
    //             pascal[i].push_back(pascal[i-1][j-1] + pascal[i-1][j]);
    //         }
    //     }
    // }

    // for(auto i: pascal){
    //     for(auto j: i){
    //         cout << j << " ";
    //     }cout << "\n";
    // }
    return 0;
}