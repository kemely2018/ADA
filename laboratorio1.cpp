
// CASTILLO CACCIRE KEMELY

/*1)Crear un generador de arreglos 10/1mil/100 mil/ 1 millon
  2)Medir tiempo (segun su lengiaje de programacion)*/
  
#include<iostream>
#include<ctime> // libreria para el tiempo en milisegundos y numeros random

using namespace std;


void rellenar_arreglo(int *A,int tam){
	int i,dato;
	srand(time(NULL)); 
	for(i=0;i<tam;i++){
	    dato = 1 + rand()%(tam-1);
	    A[i]=dato;
	}
}

int getMilisegundos(clock_t c)
{
    int tiempo=0;
    tiempo = (int)((c/(double)CLOCKS_PER_SEC)*1000) ;
    return tiempo;
}


void mostrar(int *A,int tam){//muestra todo el arreglo
	int i;
	cout<<"[";
	for(i=0;i<tam;i++){
		cout<<A[i]<<" , ";
	}
	cout<<"]";
}
int main(){
	
	int tamano,t1,t2,time;
	int* arreglo= NULL; //Se inicializa el puntero
	cout<< "Ingrese el tamaño del arreglo: ";cin>>tamano;
	arreglo= new int[tamano]; 
	t1 =clock();
	rellenar_arreglo(arreglo,tamano);
	t2=clock();
	time=getMilisegundos(t2-t1);
	cout<<"Tiempo de ejecucion: "<<time<<" Milisegundos";	
	//mostrar(arreglo,tamano);
	
	delete [] arreglo;
	/*cout<<arreglo[999999];
	delete [] arreglo;*/
	return 0;
}


/* 3) CODIGOS: https://www.geeksforgeeks.org/insertion-sort
               https://www.geeksforgeeks.org/bubble-sort*/
               
#include<iostream>
using namespace std; 

void insertionSort(int arr[], int n) 
{ 
    int comp=0,asig=0,memoria=0;
	int i, key, j; 
	for (i = 1; i < n; i++){
		comp=comp+1;
	    key = arr[i]; 
		j = i - 1; 
		while (j >= 0 && arr[j] > key) {
		    arr[j + 1] = arr[j]; 
			j = j - 1;
			asig++; 
		} 
		arr[j + 1] = key; 
	} 
	memoria=memoria*50+10*n;
	cout<<"Comparaciones: "<<comp<<endl;
	cout<<"Asignaciones: "<<asig<<endl;
	cout<<"SUMA ( comparaciones *2 + asignaciones*8 + memoria ) = "<<comp*2+asig*8+memoria<<endl;
	
} 

void bubbleSort(int arr[], int n) { 
    int comp=0,asig=0,memoria=0;
	int i, j,temp ; 
	for (i = 1; i < n; i++){
			for (j = 0; j < n-1; j++) {
				comp=comp+1;
				if (arr[j] > arr[j+1]) {
					temp=arr[j];
					arr[j]=arr[j+1];
					arr[j+1]=temp;
					asig++;
				}
			}
	}  
	memoria=memoria*50+10*n;
	cout<<"Comparaciones: "<<comp<<endl;
	cout<<"Asignaciones: "<<asig<<endl;
	cout<<"SUMA ( comparaciones *2 + asignaciones*8 + memoria ) = "<<comp*2+asig*8+memoria<<endl;
} 

void printArray(int arr[], int n) 
{ 
	int i; 
	for (i = 0; i < n; i++) 
		cout << arr[i] << " "; 
	cout << endl; 
} 


int main() 
{ 
	int arr1[] = {4,3,2,1}; //en el peor de los casos
	int arr2[] = {4,3,2,1};
	int n = sizeof(arr1) / sizeof(arr1[0]); 
	cout<<"-----------------------METODO BURBUJA-----------------------"<<endl;
    bubbleSort(arr1, n); 
    cout<<"-----------------------METODO INSERCION---------------------"<<endl;
	insertionSort(arr2, n); 
	cout<<"                                      "<<endl;
	cout<<"El vector ordenado ascendentemente es:"<<endl;
	printArray(arr1, n); 

	return 0; 
} 
              



