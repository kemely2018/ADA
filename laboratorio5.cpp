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

void intercala(int A[], int p, int q, int r) 
{ 
    int *B=new int[r+1];
    int i, j, k; 

    for(i=p;i<=q;i++){
    	B[i]=A[i];
	}
	
    for(j=q+1;j<=r;j++){
    	B[r+q+1-j]=A[j];
	} 
         
    i = p; 
    j = r;   

    for(k=p;k<=r;k++){ 
        if (B[i] <= B[j]) { 
            A[k] = B[i]; 
            i=i+1; 
        } 
        else{ 
            A[k] = B[j]; 
            j=j-1; 
        }  
    } 
    delete []B;
} 


void mergeSort(int *A, int p, int r) { 
    if (p < r) 
    { 
        int q = (p+r)/2; 
        mergeSort(A,p,q); 
        mergeSort(A,q+1,r); 
        intercala(A,p,q,r); 
    } 
} 


int compare(const void* a, const void* b)
{
	const int* x = (int*) a;
	const int* y = (int*) b;
	if (*x > *y)
		return 1;
	else if (*x < *y)
		return -1;
	return 0;
}

void quickSort(int *A, int n) { 
    qsort(A,n,sizeof(int),compare);	
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
	LARGE_INTEGER t_ini, t_fin,t_ini1, t_fin1;
    double secs,secs1,tquick,tmerge;   
    int* arr1= NULL; //Se inicializan los puntero
    int* arr2= NULL;
    vector<int> mayor ;
	for (int i=0 ;i<=100000;i=i+10000){
		tamano=i;
		arr1= new int[tamano];
		arr2= new int[tamano]; 
	        rellenar_arreglo(arr1,tamano);
	        rellenar_arreglo(arr2,tamano);
	    
	   //ORDENAMOS CON LOS ALGORITMOS DE MERGE SORT E INSERCION y TIEMPO
	    	    
	   //cout<<"-----------------------MERGE SORT---------------------"<<endl;
           QueryPerformanceCounter(&t_ini);
           mergeSort(arr1, 0, tamano - 1); 
	   QueryPerformanceCounter(&t_fin);
           secs = performancecounter_diff(&t_fin, &t_ini);
           tmerge =secs*1000;

	   //cout<<"-----------------------QUICK SORT---------------------"<<endl;
           QueryPerformanceCounter(&t_ini1);
	   quickSort(arr2, tamano); 
	   QueryPerformanceCounter(&t_fin1);
           secs1 = performancecounter_diff(&t_fin1, &t_ini1);
           tquick=secs1*1000;
	    
	   gotoxy(2,0);
	   cout<<"N      "<<"  QUICKSORT "<<"   MERGE SORT"<<endl;
	   gotoxy(x,y);
	   cout<<tamano<<"     "<<tquick<<"     "<<tmerge<<endl;
           x+=2;y+=2;x=2;
	   cout<<"                                      "<<endl;
	   delete [] arr1;
	   delete [] arr2;	
	}
	return 0; 
} 
