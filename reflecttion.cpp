#include<iostream>
using namespace std;

int main(){
    int inputMatrix[3][3], rMatrix[3][3];
  
    rMatrix[0][0] = 1;
    rMatrix[0][1] = 0;
    rMatrix[0][2] = 0;

    rMatrix[1][0] = 0;
    rMatrix[1][1] = -1;
    rMatrix[1][2] = 0;

    rMatrix[2][0] = 0;
    rMatrix[2][1] = 0;
    rMatrix[2][2] = 1;


    inputMatrix[0][0] = 5;
    inputMatrix[0][1] = 5;
    inputMatrix[0][2] = 6;
    inputMatrix[1][0] = 2;
    inputMatrix[1][1] = 1;
    inputMatrix[1][2] = 1;
    inputMatrix[2][0] = 1;
    inputMatrix[2][1] = 1;
    inputMatrix[2][2] = 1;

    // matrix multiplication
    int mult[3][3];

    for(int i = 0; i <3; i++){
        for(int j = 0; j < 3; j++){
            mult[i][j]=0;
            for (int k = 0; k < 3; k++)
            {
               mult[i][j] += rMatrix[i][k] * inputMatrix[k][j];
            }
            
        }
    }

    cout<<"Coordinates are: " <<mult[0][0] <<", "<<mult[1][0];
    cout<<"Coordinates are: " <<mult[0][1] <<", "<<mult[1][1];
    cout<<"Coordinates are: " <<mult[0][2] <<", "<<mult[1][2];

    return 0;
}