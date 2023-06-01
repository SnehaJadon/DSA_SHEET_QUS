#include<iostream>
#include<vector>
using namespace std;

void setMatrix(vector<vector<int>> &matrix, int n, int m){
    //TC -> n cube
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(matrix[i][j] == 0){
                //mark col with -1
                for(int k=0; k<n; k++){
                    matrix[k][j] = -1;
                }
                //mark row with -1
                for(int k=0; k<m; k++){
                    matrix[i][k] = -1;
                }
            }
        }
    }
    //replace -1 to 0
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(matrix[i][j] == -1){
                matrix[i][j] = 0;
            }
        }
    }
}
void setMatrix2(vector<vector<int>> &matrix, int n, int m){
    //by making dummy row and col
    // TC --> n square but SC --> (n+m) (because using extra space for row and col)
    int dummyRow[n] = {0};
    int dummyCol[m] = {0};
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(matrix[i][j] == 0){
                dummyRow[i] = 1;
                dummyCol[j] = 1;
            }
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(dummyRow[i] || dummyCol[j]){
                matrix[i][j] = 0;
            }
        }
    }
}
void setMatrix3(vector<vector<int>> &matrix, int n, int m){
    //without using any extra space 
    int col0 = 1;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(matrix[i][j] == 0){
                matrix[i][0] = 0;
                if(j != 0){
                    matrix[0][j] = 0;
                }else{
                    col0 = 0 ;
                }
            }
        }
    }
    for(int i=1; i<n; i++){
        for(int j=1; j<m; j++){
            if(matrix[0][j] == 0 || matrix[i][0] == 0){
                matrix[i][j] = 0;
            }
        }
    }
    if(matrix[0][0] == 0){
        for(int i=0; i<m; i++){
            matrix[0][i] = 0;
        }
    }
    if(col0 == 0){
        for(int j=0; j<n; j++){
            matrix[j][0] = 0;
        }
    }
}
int main(){
    vector<vector<int>> matrix = {
        {1,1,1,0},
        {1,1,0,1},
        {1,0,1,1},
        {1,1,1,1},
    };
    int n = matrix.size();
    int m = matrix[0].size();
    //setMatrix(matrix,n,m);
    //setMatrix2(matrix,n,m);
    setMatrix3(matrix,n,m);
    for(auto i: matrix){
        for(auto j : i){
            cout << j << " ";
        }cout << endl;
    }
    
    return 0;
}