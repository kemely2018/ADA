
#include<iostream>
#include<ctime> // libreria para el tiempo en milisegundos y numeros random
#include <algorithm> 
using namespace std;


/* Cuando genero los numeros aleatorios tomo
como parametros del  al tamaño del 
arreglo se puede modificar los parametros */

void rellenar_arreglo(int *A,int tam){
	int i,dato;
	srand(time(NULL)); 
	for(i=0;i<tam;i++){
	    dato = 1 + rand()%(tam-1);
	    A[i]=dato;
	}
	
	/*Utilize la libreria STL para ordenarlo creciente 
	o decreciente*/
	
	sort(A, A+tam);//CRECIENTE 
	//sort(A, A+tam,greater<int>()); // DECRECIENTE
	
}




int getMilisegundos(clock_t c)
{
    int tiempo=0;
    tiempo = (int)((c/(double)CLOCKS_PER_SEC)*1000) ;
    return tiempo;
}



void insertionSort(int *arr, int n) 
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
	memoria+=50+10*n;
	cout<<"Comparaciones: "<<comp<<endl;
	cout<<"Asignaciones: "<<asig<<endl;
	cout<<"SUMA ( comparaciones *2 + asignaciones*8 + memoria ) = "<<comp*2+asig*8+memoria<<endl;
	
} 

void bubbleSort(int *arr, int n) { 
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
	memoria+=50+10*n;
	cout<<"Comparaciones: "<<comp<<endl;
	cout<<"Asignaciones: "<<asig<<endl;
	cout<<"SUMA ( comparaciones *2 + asignaciones*8 + memoria ) = "<<comp*2+asig*8+memoria<<endl;
} 

void mostrar(int *A,int tam){//muestra todo el arreglo
	int i;
	cout<<"[";
	for(i=0;i<tam;i++){
		cout<<A[i]<<" , ";
	}
	cout<<"]"<<endl;
}


int main() 
{ 
    // ARREGLO ORIGINAL CRECIENTE Y DECRECIENTE
    
    int tamano;
	double t1,t2,t3,t4,time1,time2;
    
    int* arr1= NULL; //Se inicializan los puntero
    int* arr2= NULL;
	cout<< "Ingrese el tamaño del arreglo: ";cin>>tamano;
	arr1= new int[tamano]; 
	arr2= new int[tamano]; 
	rellenar_arreglo(arr1,tamano);
	rellenar_arreglo(arr2,tamano);
	/*cout<<"----------ARREGLOs ORIGINALES------------"<<endl;
	mostrar(arr1,tamano);
	mostrar(arr2,tamano);*/
	
	//ORDENAMOS CON LOS ALGORITMOS DE BURBUJA E INSERCION y TIEMPO
	
	cout<<"-----------------------METODO BURBUJA-----------------------"<<endl;
	t1 =clock();
    bubbleSort(arr1, tamano); 
    t2=clock();
    time1=getMilisegundos(t2-t1);
    cout<<"Tiempo de ejecucion burbuja : "<<time1<<" Milisegundos"<<endl;
    
    cout<<"-----------------------METODO INSERCION---------------------"<<endl;
    t3 =clock();
	insertionSort(arr2, tamano); 
	t4=clock();
	time2=getMilisegundos(t4-t3);
	cout<<"Tiempo de ejecucion insercion: "<<time2<<" Milisegundos"<<endl;
	cout<<"                                      "<<endl;
	
	
	//MOSTRAR EL ARREGLO ORDENADO (OPCIONAL)
	cout<<"El vector ordenado ascendentemente es:"<<endl;
	//mostrar(arr1, tamano); 	
	//mostrar(arr2, tamano); 
	
	

	
	delete [] arr1;
	delete [] arr2;

	return 0; 
} 



