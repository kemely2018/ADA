#include<iostream>
using namespace std;

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


int main(){
	int n,num,l;
	int* train= NULL;
	cin>>n;
	for(int x=0;x<n;x++){
		cin>>num;
		train= new int[num];
		for(int y=0;y<num;y++){
			cin>>train[y];
		}
		l=quickSort(train,0,num-1);
		if(l==0){
			cout<<"La mejor cantidad de swaps de trenes es "<<l+1<<" swaps."<<endl;
		}
		else{
		   cout<<"La mejor cantidad de swaps de trenes es "<<l<<" swaps."<<endl;	
		}
		delete [] train;
    } 
	return 0;
}
