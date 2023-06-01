#include<iostream>
#include<climits>
using namespace std;

void printSubarr(int a[], int n){
    int cnt = 0;
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            cnt++;
            for(int k=i; k<=j; k++){
                cout << a[k] << " ";
            }cout << endl;
        }
    }
    cout << cnt;
}
void maxsubArr(int a[], int n){
    //BRUTEFORCE approch 
    //TC--> n cube
    int sum ;
    int max_ = INT_MIN;
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            sum = 0;
            for(int k=i; k<=j; k++){
                sum+=a[k];
            }
            max_ = max(max_, sum);
        }
    }
    cout << max_ << endl;
}
void maxsubArr2(int a[], int n){
    //better approach 
    //TC ->> 0(n square)
    int sum ;
    int max_ = INT_MIN;
    for(int i=0; i<n; i++){
        sum = 0;
        for(int j=i; j<n; j++){
                sum+=a[j];
            max_ = max(max_, sum);
        }
    }
    cout << max_ << endl;

}
void kadane(int a[], int n){
    int bestSum = INT_MIN;
    int currSum = a[0];
    for(int i=0; i<n; i++){
        currSum = max(a[i], currSum+a[i]);
        bestSum = max(bestSum, currSum);
    }
    cout << bestSum << endl;
}
int main(){

    int a[] = {-2,1,-3,4,-1,2,1,-5,4};
    int n=9;//45 subarr
    //printSubarr(a, n);
    maxsubArr(a, n);
    maxsubArr2(a, n);
    kadane(a, n);
    return 0;
}