#include <iostream>
#include <math.h>
#define PI 22.0/7.0
#define cos_theta 0
#define sin_theta 1
using namespace std;

int main()
{

    int firstMatrix[3][1], secondMatrix[3][3], thirdMatrix[3][1];
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 1; j++)
            firstMatrix[i][j] = 0;

    int oldX, oldY;
    cout << "Enter the value of x coordinate: ";
    cin >> oldX;
    cout << "Enter the value of y coordinate: ";
    cin >> oldY;
    thirdMatrix[0][0] = oldX;
    thirdMatrix[1][0] = oldY;
    thirdMatrix[2][0] = 1;

    secondMatrix[0][2]=0;
    secondMatrix[2][0]=0;
    secondMatrix[2][1]=0;
    secondMatrix[1][2]=0;
    secondMatrix[2][2]=1;

    double angle;
    cout <<"Enter the angle: ";
    cin >> angle;

    double angle_radians = angle * PI / 180.0;
    double cos_theta1 = cos(angle_radians);
    double sin_theta1 = sin(angle_radians);
    cout<<cos_theta<<endl;
    cout<<sin_theta<<endl;
    secondMatrix[0][0] = cos_theta;
    // secondMatrix[0][0] = 0;

    secondMatrix[1][1] = cos_theta;
    // secondMatrix[1][1] = 0;

    secondMatrix[1][0] = sin_theta;
    // secondMatrix[1][0] = 1;

    secondMatrix[0][1] = sin_theta * (-1);
    // secondMatrix[0][1] = -1;


     // Perform matrix multiplication: firstMatrix = secondMatrix * thirdMatrix
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 1; j++) {
            for (int k = 0; k < 3; k++) {
                firstMatrix[i][j] += secondMatrix[i][k] * thirdMatrix[k][j];
            }
        }
    }
     cout << "Resultant coordinates: (" << firstMatrix[0][0] << ", " << firstMatrix[1][0] << ")" << endl;
    return 0;
}