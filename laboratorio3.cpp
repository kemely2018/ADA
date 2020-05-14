#include<iostream>
#include<ctime> 
#include <algorithm>
#include <windows.h> 
#include <conio.h> 
#include <vector>
using namespace std;

void rellenar_arreglo(int *A,int tam){
	int i,dato;
	srand(time(NULL)); 
	for(i=0;i<tam;i++){
	    dato = 1 + rand()%(tam-1);
	    A[i]=dato;
	}
	
	sort(A, A+tam);//CRECIENTE 
	//sort(A, A+tam,greater<int>()); // DECRECIENTE	
}
double performancecounter_diff(LARGE_INTEGER *a, LARGE_INTEGER *b){
  LARGE_INTEGER freq;
  QueryPerformanceFrequency(&freq);
  return (double)(a->QuadPart - b->QuadPart) / (double)freq.QuadPart;
}
void gotoxy(int x,int y){  
    HANDLE hcon;  
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
    COORD dwPos;  
    dwPos.X = x;  
    dwPos.Y= y;  
    SetConsoleCursorPosition(hcon,dwPos);  
}  

void merge(int *arr, int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
    int L[n1], R[n2]; 
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
    i = 0; 
    j = 0;  
    k = l;  
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) { 
            arr[k] = L[i]; 
            i++; 
        } 
        else{ 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
    while (i < n1) { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 

void mergeSort(int *arr, int l, int r) { 
    if (l < r) 
    { 
        int m = l+(r-l)/2; 
        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
  
        merge(arr, l, m, r); 
    } 
} 

void insertionSort(int *arr, int n) { 

	int i, key, j; 
	for (i = 1; i < n; i++){
	    key = arr[i]; 
		j = i - 1; 
		while (j >= 0 && arr[j] > key) {
		    arr[j + 1] = arr[j]; 
			j = j - 1; 
		} 
		arr[j + 1] = key; 
	} 	
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
    int tamano,x=2,y=0;
	//double t1,t2,t3,t4,time1,time2;
	LARGE_INTEGER t_ini, t_fin,t_ini1, t_fin1;
    double secs,secs1,tinsertion,tmerge;   
    int* arr1= NULL; //Se inicializan los puntero
    int* arr2= NULL;
    vector<int> mayor ;
	for (int i=0 ;i<=1000;i=i+10){
		tamano=i;
		arr1= new int[tamano];arr2= new int[tamano]; 
	    rellenar_arreglo(arr1,tamano);
	    rellenar_arreglo(arr2,tamano);
	    //ORDENAMOS CON LOS ALGORITMOS DE MERGE SORT E INSERCION y TIEMPO
	    //cout<<"-----------------------MERGE SORT---------------------"<<endl;
        QueryPerformanceCounter(&t_ini);
        mergeSort(arr1, 0, tamano - 1); 
	    QueryPerformanceCounter(&t_fin);
        secs = performancecounter_diff(&t_fin, &t_ini);
        tmerge =secs*1000;
         //cout<<"-----------------------METODO INSERCION---------------------"<<endl;
        QueryPerformanceCounter(&t_ini1);
	    insertionSort(arr2, tamano); 
	    QueryPerformanceCounter(&t_fin1);
	    secs1 = performancecounter_diff(&t_fin1, &t_ini1);
	    tinsertion=secs1*1000;
	    gotoxy(2,0);
	    cout<<"N    "<<"  INSERCION "<<"   MERGE SORT"<<endl;
	    gotoxy(x,y);
	    cout<<tamano<<"     "<<tinsertion<<"     "<<tmerge<<endl;
	    x+=2;y+=2;x=2;
	    cout<<"                                      "<<endl;
	    delete [] arr1;delete [] arr2;		
	}
	return 0; 
} 


