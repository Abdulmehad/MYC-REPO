#include<iostream>
using namespace std;
int main(){
    cout<<"ENTER NO OF ROWS AND COLUMNS RESPECTIVELY";
    int n,m;
    cin>>n>>m;

    int arr[n][m];

   

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
             cout<<"Enter the a"<<i<<j<<"th index of array";
            cin>>arr[i][j];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
             
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
   
    for(int i=0;i<n;i++){
        cout << "[";
        for(int j=0;j<m;j++){
            cout << arr[i][j];
            if(j != m-1) {
                cout << ", ";
            }
        }
        cout << "]";
        if(i != n-1) {
            cout << ", ";
        }
    }
  

    return 0;
}