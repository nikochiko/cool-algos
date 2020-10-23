#include<iostream>

using namespace std;

void insertionSort(int arr[],int size){
 for(int i=1;i<size;i++){
  int j=i-1;
  int temp=arr[i];
  while (j >= 0 && arr[j] > temp)
  {         
    arr[j + 1] = arr[j];  
    j--;  
  }  
  arr[j + 1] = temp; 
 }
}
void display(int arr[],int size){
 for(int i=0;i<size;i++){
  cout<<arr[i]<<" ";
 }
cout<<endl;
}
int main(){
 int n;
 cout<<"enter the size of array"<<endl;
 cin>>n;
 int *a= new int(n);
 cout<<"enter array to be sorted"<<endl;
 for(int i=0;i<n;i++){
  cin>>a[i];
 }
 cout<<"before sorting"<<endl;
 display(a,n);
 insertionSort(a,n);
 cout<<"array after sorting\n";
 display(a,n);
 return 0;
}
