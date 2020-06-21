#include<iostream>
#include<ctime> 
#include <iomanip>
using namespace std;

void rellenar_arreglo(int* A,int tam){
	int i,dato;
	for(i=0;i<tam;i++){
	    dato = 1 + rand()%(tam-1);
	    A[i]=dato;   
	}
}

void swap(int *a, int *b){
	int temp; 
	temp = *a;
	*a = *b;
	*b = temp;
}

int particion(int* A,int p,int r,int& count){
	int x,i,j,tmp;
	x=A[r];
	i=p-1;
	for(j=p;j<=r-1;j++){
		if(A[j]<=x){
			count++;
			i++;
			swap(&A[i],&A[j]);
		}
	}
	swap(&A[i+1],&A[r]);
	return i+1;
}

int quickSort(int *A, int p, int r) { 
    int count=0,q;
    if (r<p)return 0; 
    q = particion(A,p,r,count);
	return count+quickSort(A,p,q-1)+quickSort(A,q+1,r); 
}

void mostrar(int* A,int tam){
	int i;
	cout<<"[";
	for(i=0;i<tam;i++){
		cout<<A[i]<<" , ";
	}
	cout<<"]"<<endl;
}

int main(){
	int tamano,veces=200,l;
	double suma=0,promedio;
	int* arr= NULL;
	srand(time(NULL)); 
	cout<<"N          "<<"Promedio"<<endl;
	for(int i=256;i<=1048576;i=i+tamano){
		for(int j=1;j<=veces;j++){
			tamano=i;
			arr= new int[tamano];
			rellenar_arreglo(arr,tamano);
			l=quickSort(arr,0,tamano-1);
			suma=suma+l;
			delete [] arr;
		}
		promedio=suma/veces;
		cout<<tamano<<"          "<<fixed<<setprecision(2)<<promedio<<endl;
		suma=0;
	}	
	return 0;
}

