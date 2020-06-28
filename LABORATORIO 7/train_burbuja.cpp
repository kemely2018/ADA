#include<iostream>
using namespace std;

void swap(int *a, int *b){
	int temp; 
	temp = *a;
	*a = *b;
	*b = temp;
}

void burbuja(int *train,int num){
	int cont=0;
    for(int i=1;i<num;i++){
    	for(int j=0;j<num-1;j++){
    		if(train[j]>train[j+1]){
    		    cont++;
    			swap(&train[j],&train[j+1]);
			}
		}  
	}
	cout<<"La mejor cantidad de swaps de trenes es "<<cont<<" swaps."<<endl;
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
		burbuja(train,num);
		delete [] train;
    } 
	return 0;
}
