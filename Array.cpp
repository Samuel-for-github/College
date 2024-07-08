#include <iostream>
#include <conio.h>

using namespace std;


int main(){
	int size;
	cout<<"Enter size of array"<<endl;
	cin>>size;

	int *arr = new int[size];
	
	cout<<"Enter elements in array"<<endl;

	for(int i = 0; i<size; i++){
		cin>>arr[i];
	}

	int evenSum = 0, oddSum = 0;
	for(int i = 0; i<size; i++){
		if(arr[i] % 2 == 0){
			evenSum += arr[i]; 
		}
		else{
			oddSum += arr[i];
		}
	}
	cout<<"Even sum of array: "<<evenSum<<endl;
	cout<<"Odd sum of array: "<<oddSum<<endl;

getch();
return 0;
}