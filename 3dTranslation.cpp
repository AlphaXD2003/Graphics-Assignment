#include <iostream>
#include <cmath>

class ThreeDtranslation
{
private:
    int x, y, z;
    int tx, ty, tz;

public:
    ThreeDtranslation(int x, int y, int z, int tx, int ty, int tz)
    {
        this->x = x;
        this->y = y;
        this->z = z;
        this->tx = tx;
        this->ty = ty;
        this->tz = tz;
    }
    void translate()
    {
        int firstMatrix[4][4];

        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (i == j)
                {
                    firstMatrix[i][j] = 1;
                }
                else
                {
                    firstMatrix[i][j] = 0;
                }
            }
        }
        firstMatrix[0][3] = tx;
        firstMatrix[1][3] = ty;
        firstMatrix[2][3] = tz;

        int secondMatrix[4][1];
        secondMatrix[0][0] = x;
        secondMatrix[1][0] = y;
        secondMatrix[2][0] = z;
        secondMatrix[3][0] = 1;

        int result[4][1] = {0};

        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                result[i][0] += firstMatrix[i][j] * secondMatrix[j][0];
            }
        }
        display(result);
        for(int i = 0; i < 4; i++){
           
                std::cout<<result[i][0]<<" ";
          
            std::cout<<std::endl;
        }
    }
    void display(int result[4][1])
    {
        std::cout << "New X Coordinates: " << result[0][0] << std::endl;
        std::cout << "New Y Coordinates: " << result[1][0] << std::endl;
        std::cout << "New Y Coordinates: " << result[2][0] << std::endl;
    }
};

int main()
{
    // int x, int y, int z, int tx, int ty, int tz
    ThreeDtranslation ob(5,6,7,3,3,2);
    ob.translate();
    return 0;
}