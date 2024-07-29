#include<iostream>
#include <vector>
using namespace std;

int celebrity(vector<vector<int> > &matrix, int n){
    int top = 0;
    int down = n-1;
    while(top<down){
        if(matrix[top][down]==1){
            top++;
        }
        else{
            down--;
        }
    }
    for(int i =0;i<n;i++){
        if(i!=top && (matrix[top][i]==1 || matrix[i][top]==0)){
            return -1;
        }
    }
    return top;
}

// int celebrity(vector<vector<int> > &matrix , int n){
//     vector<int> knowme(n);
//     vector<int> iknow(n);

//     for(int i =0;i<n;i++){
//         for(int j = 0; j<n;j++){
//             if(matrix[i][j]==1){
//                 knowme[j]++;
//                 iknow[i]++;
//             }
//         }
//     }
//     for(int i=0;i<n;i++){
//         if(knowme[i]==n-1 && iknow[i]==0){
//             return i;
//         }
//     }
//     return -1;
// }

int main()
{
    int n;
    cin>>n;
    vector<vector<int> >matrix(n, vector<int>(n));
    for(int i =0;i<n;i++){
        for(int j =0;j<n;j++){
            cin>>matrix[i][j];
        }
    }
    cout<<celebrity(matrix, n);
    return 0;
}