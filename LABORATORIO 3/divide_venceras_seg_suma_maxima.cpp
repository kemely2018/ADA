//Kemely Castillo Caccire
#include<cmath>
#include <iostream>

using namespace std;
int max_subarray_suma(int arr[],int n){

	if(n==1){
		return arr[0];
	}
	int m=n/2;
	int izq_MSS = max_subarray_suma(arr,m);
	int der_MSS = max_subarray_suma(arr+m,n-m);
	int izqsum=INT_MIN ,dersum=INT_MIN , sum=0;
	for(int i= m;i<n;i++){
		sum+= arr[i];
		dersum=max(dersum,sum);
	
	}
	sum=0;
	for(int i= (m-1);i>=0;i--){
		sum+= arr[i];
		izqsum=max(izqsum,sum);

	}
	int ans = max(izq_MSS,der_MSS);
	return max(ans,izqsum+dersum);

	
}


int main()
{
	int *arr=NULL;
	int *lon=NULL;
	int *resul=NULL;
	int r;
	int a,b,dato;
	cin>>a;
	lon= new int[a];
	resul= new int[a];
	for(int i=0;i<a;i++){
		cin>>b;
		lon[i]=b;
		arr=new int[b];
		for(int j=0;j<b-1;j++){
			cin>>dato;
			arr[j]=dato;
		}
		r=max_subarray_suma(arr,b-1);
		resul[i]=r;
		
	}
	
	for(int i=0;i<a;i++){
    	if(resul[i] <=0){
    		 cout<<"La mejor parte de la ruta "<<i+1<<" no tiene calles interesantes"<<endl;
		}
		else{
			cout<<"La mejor parte de la ruta "<<i+1<<" su suma es "<<resul[i]<<endl;
		}
	}
	delete [] arr;
	delete [] lon;
	return 0;
}
