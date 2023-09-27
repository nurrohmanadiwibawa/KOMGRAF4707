#include <iostream>
#include <iomanip>
 
using namespace std;

void tambahMatriks()
{
	int matriksA[2][2], matriksB[2][2], i, j;
 

  matriksA[0][0] = 1;
  matriksA[0][1] = 2;
  matriksA[1][0] = 3;
  matriksA[1][1] = 4;
 

  matriksB[0][0] = 1;
  matriksB[0][1] = 1;
  matriksB[1][0] = 2;
  matriksB[1][1] = 2;
 
  
  cout << "Matriks A: " << endl;
  for(i = 0; i < 2 ; i++){
    for(j = 0; j < 2; j++){
      cout << setw(3) << matriksA[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
 

  cout << "Matriks B: " << endl;
  for(i = 0; i < 2 ; i++){
    for(j = 0; j < 2; j++){
      cout << setw(3) << matriksB[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
 

  cout << "Matriks A + Matriks B: " << endl;
  for(i = 0; i < 2 ; i++){
    for(j = 0; j < 2; j++){
      cout << setw(3) << matriksA[i][j] + matriksB[i][j]<< " ";
    }
    cout << endl;
  }
 
 
}

void kurangMatriks()
{
	int matriksA[2][2], matriksB[2][2], i, j;
 

  matriksA[0][0] = 1;
  matriksA[0][1] = 2;
  matriksA[1][0] = 3;
  matriksA[1][1] = 4;
 

  matriksB[0][0] = 1;
  matriksB[0][1] = 1;
  matriksB[1][0] = 2;
  matriksB[1][1] = 2;
 

 
 
  cout << "Matriks A - Matriks B: " << endl;
  for(i = 0; i < 2 ; i++){
    for(j = 0; j < 2; j++){
      cout << setw(3) << matriksA[i][j] - matriksB[i][j]<< " ";
    }
    cout << endl;
  }
 
 
}

void kaliMatriks ()
{
	int matriksA[2][2], matriksB[2][2], matriksHasil[2][2],i, j, k;
 

  matriksA[0][0] = 1;
  matriksA[0][1] = 2;
  matriksA[1][0] = 3;
  matriksA[1][1] = 4;
 
 
  matriksB[0][0] = 1;
  matriksB[0][1] = 1;
  matriksB[1][0] = 2;
  matriksB[1][1] = 2;
 
  
 
  
  for(i = 0; i < 2 ; i++){
    for(j = 0; j < 2; j++){
      for(k = 0; k < 2; k++){
        matriksHasil[i][j] = matriksHasil[i][j] + (matriksA[i][k] * matriksB[k][j]);
      }
    }
  }
 

  cout << "Matriks A * Matriks B: " << endl;
  for(i = 0; i < 2 ; i++){
    for(j = 0; j < 2; j++){
      cout << setw(3) << matriksHasil[i][j] << " ";
    }
    cout << endl;
  }
 
  
}


		
 
int main()
{
	cout<<"Nama : Nurrohman Adi Wibawa"<<endl;
	cout<<"Nim  : A11.2020.12707"<<endl;
	cout<<"kelas : A11.4707"<<endl;
	
	cout<<endl;
	
	tambahMatriks();
	kurangMatriks();
	kaliMatriks();
	bagiMatriks();
	return 0;
 
  
}
