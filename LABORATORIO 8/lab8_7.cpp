#include <iostream>
#include <iomanip> 
#include <fstream>
using namespace std;
#define M 127
#define N 127

int SumaSubMatriz(int **A){
	int **C=new int*[M];
	for(int i = 0; i < M; i++) {
        C[i] = new int[N];
	}
	C[0][0]=A[0][0];
    for (int i = 1; i < N; i++){
    	C[i][0]=A[i][0]+C[i-1][0];
        for (int j = 1; j <M; j++){
        	C[0][j]=A[0][j]+C[0][j-1];
            C[i][j]=A[i][j]+C[i-1][j]+C[i][j-1]-C[i-1][j-1];
        }
    }
    
	
	// sub_suma= C[f2][c2] - C[f2][c1-1] - C[f1-1][c2] + C[f1-1][c1-1]
	
	int max_suma =0;
	int f1, f2, c1, c2;
	for (int i = 0; i < M; i++){
		for (int j = i; j < M; j++){
			for (int m = 0; m < N; m++){
				for (int n = m; n < N; n++){
					int sub_suma=C[m][n];
					if(i-1>=0) sub_suma=sub_suma- C[i-1][n];
					if(j-1>=0) sub_suma=sub_suma- C[m][j-1];
					if(i-1>=0 && j-1>=0) sub_suma=sub_suma+C[i-1][j-1];
					if (sub_suma > max_suma){
						max_suma = sub_suma;
						f1 = i;
						f2 = m;
						c1 = j;
						c2 = n;
					}
				}
			}
		}
	}	
    cout << "Submatriz cuya suma es maxima es  fila " << f1 << " a " << f2
		 << " y columna de " << c1 << " a " <<  c2 << '\n';

   //OMPRIMIR LA SUB MATRIZ
	/*for (int i = f1; i <=f2; i++) {
		for(int j =c1;j<=c2;  j++){
			cout <<  A[i][j] << " ";
		}
		cout << '\n';
	}*/
	
	for(int i=0;i<M;i++){
		delete[] C[i];
	}
	delete[] C;

 
	return max_suma;

}

int main(){
	
	int n;
	ifstream archivo;
	int **A=new int*[M];
	for(int i = 0; i < M; i++) {
        A[i] = new int[N];
	}
	
	archivo.open("prueba.txt");
	archivo >> n;
	for(int i=0; i < n; i++){
		for (int j=0 ; j<n ;j++){
			archivo >> A[i][j];
		}
	}
	cout << "Sumando es :" << SumaSubMatriz(A);

    archivo.close();
	for(int i=0;i<M;i++){
		delete[] A[i];
	}
	delete[] A;
	return 0;
}

