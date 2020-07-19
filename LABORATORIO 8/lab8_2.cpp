#include <iostream>
#include <iomanip> 
using namespace std;
#define M 4
#define N 4

int SumaSubMatriz(int A[M][N]){
	int C[M][N];
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

	for (int i = f1; i <=f2; i++) {
		for(int j =c1;j<=c2;  j++){
			cout <<  A[i][j] << " ";
		}
		cout << '\n';
	}
	return max_suma;
}

int main(){

	int A[M][N] ={-2,0,8,-1,
	             1,-4,1,-4,
				 2,-6,2,9,
				 0,-2,-7,0};
	cout << "Sumando es :" << SumaSubMatriz(A);

	return 0;
}


