#include<iostream>
using namespace std;
int main(){
int n;
cout<<"enter the size of array:";
cin>>n;
int a[n];
cout<<"Enter element in array:\n";
for(int i=0;i<n;i++){

    cout<<"enter the element of array at "<<i<<endl;
    cin>>a[i];
}
int b;
bool found=false;
cout<<"Enter the element to be search in array:";
cin>>b;

for(int i=0;i<n;i++){
    if(a[i]==b){
       cout<<"Element is found at index "<<i<<endl;
       //found=true;
       break;
    }
    
}
if(!found){
    cout<<"element is not found in array"<<endl;
}

return 0;
}