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

int maximo(int *A,int n){
	int i,maxi,cont=0;
	maxi=A[0];
	for(i=1;i<n;i++){
		if(A[i]>maxi){
			cont++;
			maxi=A[i];
		}
	}
	return cont;
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
	int tamano,veces=200,m;
	double suma=0,promedio;
	int* arr= NULL;
	srand(time(NULL)); 
	cout<<"N          "<<"Promedio"<<endl;
	for(int i=256;i<=1048576;i=i+tamano){
		for(int j=1;j<=veces;j++){
			tamano=i;
			arr= new int[tamano];
			rellenar_arreglo(arr,tamano);
			m=maximo(arr,tamano);
			suma=suma+m;
			delete [] arr;
		}
		promedio=suma/veces;
		cout<<tamano<<"          "<<fixed<<setprecision(4)<<promedio<<endl;
		suma=0;
	}
	return 0;
}
