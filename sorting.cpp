
#include <iostream>
#include <conio.h>

using namespace std;



int main(){
	
	int size;
	cout<<"Enter size of array"<<endl;
	cin>>size;

	int *arr = new int[size];

	for(int i=0; i<size; i++){
		cin>>arr[i];
	}

	//bubble sort

	for(int i = 0; i<size; i++){
		for(int j=0; j<size-i-1; j++){
			if(arr[j]>arr[j+1]){
				swap(arr[j], arr[j+1]);
			}
		}
	}

	cout<<"Largest element is: "<<arr[size-1]<<endl;
	cout<<"Asscending order"<<endl;
	for(int i = 0; i<size; i++ ){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	cout<<"Descending order"<<endl;
	for(int i = size-1; i>=0; i--){
		cout<<arr[i]<<" ";
	}


getch();
return 0;
}
