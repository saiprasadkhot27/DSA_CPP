#include<iostream>
using namespace std;
int main(){

int n;

int data;
cout<<"Enter size of array:";
cin>>n;
int a[n];
cout<<"Enter array element:";
for(int i=0;i<n;i++){
    cout<<"entr element at index"<<i<<endl;
    cin>>a[i];
}
cout<<"Enter element to find :";
cin>>data;


int low=0;
    int upp=n-1;
while(low<=upp){
    
  int   mid=(low+upp)/2;
    if(a[mid]==data){
     cout<<"element is present at index:"<<mid;
  return 0;
    }
    else if(a[mid]<data) {
     low=mid-1;
    }
    else{
        upp=mid+1;
        
    }
}
cout<<"element is not found:"<<endl;
return 0;

    }