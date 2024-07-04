// rotation with referrence point
#include <iostream>
#include <cmath>
using namespace std;
#define PI 22/7
int main(){
    cout<<abs(cos( 90 * PI/ 180))<<endl;
    int newX, newY, oldX, oldY, rX, rY, angle;
    std::cout<<"Enter the x coordinate: ";
    std::cin>>oldX;
    std::cout<<"Enter the y coordinate: ";
    std::cin>>oldY;

    std::cout<<"Enter the the value of rX: ";
    std::cin>>rX;
    std::cout<<"Enter the the value of rY: ";
    std::cin>>rY;

    std::cout<<"Enter the the value of angle: ";
    std::cin>>angle;

    int firstMatrix[3][3] , secondMatrix[3][3], thirdMatrix[3][3] , fourthMatrix[3][3], fifthMatrix[3][3];

    // first matrix
    firstMatrix[0][0] = 1;
    firstMatrix[0][1] = 0;
    firstMatrix[0][2] = rX;
    firstMatrix[1][0] = 0;
    firstMatrix[1][1] = 1;
    firstMatrix[1][2] = rY;
    firstMatrix[2][0] = 0;
    firstMatrix[2][1] = 0;
    firstMatrix[2][2] = 1;

    double angleInRadians = angle * PI / 180;
    // second matrix
    secondMatrix[0][0] = cos(angleInRadians);
    secondMatrix[0][1] = -sin(angleInRadians);
    secondMatrix[0][2] = 0;
    secondMatrix[1][0] = sin(angleInRadians);
    secondMatrix[1][1] = cos(angleInRadians);
    secondMatrix[1][2] = 0;
    secondMatrix[2][0] = 0;
    secondMatrix[2][1] = 0;
    secondMatrix[2][2] = 1;

    // third matrix
    thirdMatrix[0][0] = 1;
    thirdMatrix[0][1] = 0;
    thirdMatrix[0][2] = -rX;
    thirdMatrix[1][0] = 0;
    thirdMatrix[1][1] = 1;
    thirdMatrix[1][2] = -rY;
    thirdMatrix[2][0] = 0;
    thirdMatrix[2][1] = 0;
    thirdMatrix[2][2] = 1;


    // multiply secondMatrix and thirdMatrix to get fourthMatrix
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            fourthMatrix[i][j] = 0;
            for(int k = 0; k < 3; k++){
                fourthMatrix[i][j] += secondMatrix[i][k] * thirdMatrix[k][j];
            }
        }
    }

    // multiply firstMatrix and fourthMatrix to get fifthMatrix
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            fifthMatrix[i][j] = 0;
            for(int k = 0; k < 3; k++){
                fifthMatrix[i][j] += firstMatrix[i][k] * fourthMatrix[k][j];
            }
        }
    }

    newX = fifthMatrix[0][0] * oldX + fifthMatrix[0][1] * oldY + fifthMatrix[0][2];
    newY = fifthMatrix[1][0] * oldX + fifthMatrix[1][1] * oldY + fifthMatrix[1][2];

    std::cout<<"The new x coordinate is: "<<newX<<std::endl;
    std::cout<<"The new y coordinate is: "<<newY<<std::endl;


    return 0;

}