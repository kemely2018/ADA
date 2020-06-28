#include <iostream>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <ctime> 
#define MX 2000000000

using namespace std;
void generar(){
	ofstream archivo;
	archivo.open("datos.txt",ios::in);
    int n=8000;
    for(int i=0; i<n; i++) {
        for( int j=0; j<n; j++) {
        	archivo<<rand()%MX<< ' ';
        }
        archivo<<endl;
    }
    archivo.close();	
}
int main() {
	unsigned t0, t1;
	t0=clock();
	generar();
	t1=clock();
	double time = (double(t1-t0)/CLOCKS_PER_SEC);
	cout << "Execution Time: " << time << endl;
    return 0;
}
