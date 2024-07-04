#include <iostream>


int main(){
    int newX, newY, oldX, oldY, dx, dy;
    // std::cout<<"Enter the x coordinate: ";
    // std::cin>>oldX;
    // std::cout<<"Enter the y coordinate: ";
    // std::cin>>oldY;
   
    std::cout<<"Enter the the value of dx: ";
    std::cin>>dx;
    std::cout<<"Enter the the value of dy: ";
    std::cin>>dy;



    int firstMatrix[3][3] , secondMatrix[3][3], thirdMatrix[3][3];
    for(int i = 0; i< 3 ; i++){
        for(int j = 0; j < 3; j++){
            firstMatrix[i][j] = 0;
        }
    }

    // second matrix 
    secondMatrix[0][0]= 1;
    secondMatrix[1][1]= 1;
    secondMatrix[2][2]= 1;

    secondMatrix[0][1]= 0;
    secondMatrix[1][0]= 0;
    secondMatrix[2][0]= 0;
    secondMatrix[2][1]= 0;

    secondMatrix[0][2] = dx;
    secondMatrix[1][2] = dy;


    // third matrix 
    thirdMatrix[0][0] = 0;
    thirdMatrix[0][1] = 2;
    thirdMatrix[0][2] = 0;

    thirdMatrix[1][0] = 0;
    thirdMatrix[1][1] = 0;
    thirdMatrix[1][2] = 2;
    
    thirdMatrix[2][0] = 1;
    thirdMatrix[2][1] = 1;
    thirdMatrix[2][2] = 1;


    //  secondMatrix * thirdMatrix = firstMatrix
    

    for(int i = 0; i <3; i++){
        for(int j = 0; j < 3; j++){
            firstMatrix[i][j] = 0;
            for (int k = 0; k < 3; k++)
            {
               firstMatrix[i][j] += secondMatrix[i][k] * thirdMatrix[k][j];
            }
            
        }
    }

   std::cout<<"New Point1: " << firstMatrix[0][0]<<", "<<firstMatrix[1][0]<<std::endl;
   std::cout<<"New Point2: " << firstMatrix[0][1]<<", "<<firstMatrix[1][1]<<std::endl;
   std::cout<<"New Point3: " << firstMatrix[0][2]<<", "<<firstMatrix[1][2]<<std::endl;

    return 0;
}