#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter Value :";
    cin>>n;
    int a[n];
    cout<<"Enter Array Elements :";
    for(int i=0;i<n;i++)
    cin>>a[i];
    int b[n];
    for (int  i = 0; i < n; i++)
    cin>>b[i];  
    int i=0,j=0;
    for(int j=0;j<n;j++){
        for(int k=j;k<n;k++){
            if(a[j]==a[k]){
                
            }
        }
    }


    return 0;
}