//Kemely Castillo Caccire

#include<cmath>
#include <iostream>

using namespace std;


class Resultado{
	public:
		int start,end,c;
		
};

Resultado max_subarray_suma(int arr[],int n){
	Resultado s;
	int sumamax=0,suma=0;
	int e=0,d=0,x=0;
    for(int i=0;i<n;i++)
    {
  	    suma=suma+arr[i];						
	    if(suma<0){	
		    suma=0;
		    x=i+1;
		}
	    if(suma>sumamax){							
		    sumamax=suma;
		    e=x;
		    d=i;
		}
    }
    s.start=e+1;
    s.end=d+2;
    s.c=sumamax;
    return s;
	
}


int main()
{
	
	int *arr=NULL;
	int *lon=NULL;
	int **arreglo;
	int a,b,dato,colum=3,m=0;
	cin>>a;
	lon= new int[a];
	arreglo=new int*[a];
	for(int k=0;k<a;k++){
		arreglo[k]=new int[colum];
	}
	for(int i=0;i<a;i++){
		cin>>b;
		lon[i]=b;
		arr=new int[b];
		for(int j=0;j<b-1;j++){
			cin>>dato;
			arr[j]=dato;
		}
		Resultado result;
		result=max_subarray_suma(arr,b-1);
		arreglo[m][0]=result.start;
		arreglo[m][1]=result.end;
		arreglo[m][2]=result.c;
		m++;
		
	}
	
    for (int i = 0; i < a; i++) {
    	if(arreglo[i][2] <=0){
    		 cout<<"La mejor parte de la ruta "<<i+1<<" no tiene calles interesantes"<<endl;
		}
		else{
			cout<<"La mejor parte de la ruta "<<i+1<<" es entre las calles "<<arreglo[i][0]<<" y "<<arreglo[i][1]<<endl;
		}
    }	

	delete [] arr;
	delete [] lon;
	delete [] arreglo;

	return 0;
}
