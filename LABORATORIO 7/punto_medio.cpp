#include <iostream>
#include <fstream>
#include <ctime> 
#define MAX_SIZE 8000
using namespace std;


void swap(int *a, int *b){
	int temp; 
	temp = *a;
	*a = *b;
	*b = temp;
}

int particion(int* A,int p,int r){
	int x,i,j,tmp;
	x=A[r];
	i=p-1;
	for(j=p;j<=r-1;j++){
		if(A[j]<=x){
			i++;
			swap(&A[i],&A[j]);
		}
	}
	swap(&A[i+1],&A[r]);
	return i+1;
}

void quickSort(int *A, int p, int r) { 
    int q;
    if (p<r){
    	q = particion(A,p,r);
    	quickSort(A,p,q-1);
    	quickSort(A,q+1,r);	
	}
}


void sortByRow(int **mat, int n) { 
    for (int i = 0; i < n; i++)  
        //sort(mat[i], mat[i] + n); 
        quickSort(mat[i],0,n-1);
} 

void printMat(int **mat, int n) {
    ofstream archivo;
	archivo.open("resultado.txt",ios::in); 
    int medio=(n/2)-1;
    for (int i = 0; i < n; i++) { 
            archivo<<mat[i][medio]<<endl;
            //cout << mat[i][medio] << " ";  
    } 
    archivo.close();
} 

void leer(){
	string s;
	ifstream salida;
	salida.open("resultado.txt");
	while(!salida.eof()){
		getline( salida, s );
		cout << s <<endl;
	}
    salida.close();
}


int main(){

	unsigned t0, t1;
    int  **numbers=new int*[MAX_SIZE];
    ifstream inputFile;
    
    for( int i=0; i<MAX_SIZE; i++ ){
    	numbers[i] = new int[MAX_SIZE];
	}
	
	t0=clock();
	
    inputFile.open("datos.txt");
    for(int countRows = 0; countRows < MAX_SIZE; countRows++)
    {
        for(int countColumns = 0; countColumns < MAX_SIZE; countColumns++)
        {
            inputFile >> numbers[countRows][countColumns];
        }
    }
    
  
    inputFile.close();
	
    sortByRow(numbers,MAX_SIZE);
    printMat(numbers,MAX_SIZE);
    
 	t1=clock();
	    
	double time = (double(t1-t0)/CLOCKS_PER_SEC);
	cout << "Execution Time: " << time << endl;    
	
	leer();
	
    for( int i=0; i<MAX_SIZE; i++ ){
    	delete[] numbers[i];
	}
	delete[] numbers;
    return 0;   
}


