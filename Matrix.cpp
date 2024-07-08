/*
#include <iostream>
#include <conio.h>

using namespace std;


void addMat(int **matA, int **matB,int row,int col){
		for(int i=0; i<row; i++){
		for(int j=0; j<col; j++){
			cout<<matA[i][j]+matB[i][j]<<" ";
		}
		cout<<endl;
	}

}

void subMat(int **matA, int **matB,int row,int col){
		for(int i=0; i<row; i++){
		for(int j=0; j<col; j++){
			cout<<matA[i][j]-matB[i][j]<<" ";
		}
		cout<<endl;
	}

}

void mulMat(int **matA, int **matB,int row,int col){

	for(int i=0; i<row; i++){
		for(int j=0; j<col; j++){
			int sum = 0;
			for(int k=0; k<(row+col)/2; k++){
			sum += matA[i][k]*matB[k][j];
			}
			cout<<sum<<" ";
		}
		cout<<endl;
		
	}	

}



int main(){
	int row, col;
	cout<<"Enter row"<<endl;
	cin>>row;
	cout<<"Enter coloumn"<<endl;
	cin>>col;

	int **matA = new int*[row];
    for (int i = 0; i < row; i++) {
        matA[i] = new int[col];
    }

	int **matB = new int*[row];
    for (int i = 0; i < row; i++) {
        matB[i] = new int[col];
    }

	
	cout<<"Enter Elements in array Matrix A\n";
	for(int i=0; i<row; i++){
		for(int j=0; j<col; j++){
			cin>>matA[i][j];
		}
	}
	cout<<"Enter Elements in array Matrix B\n";
	for(int i=0; i<row; i++){
		for(int j=0; j<col; j++){
			cin>>matB[i][j];
		}
	}

	
	cout<<"Sum of Mat A and B is "<<endl;
	addMat(matA, matB, row, col);
	cout<<"Subtraction of Mat A and B is "<<endl;
	subMat(matA, matB, row, col);
	cout<<"Multiplication of Mat A and B is "<<endl;
	mulMat(matA, matB, row, col);

getch();
return 0;
}
*/