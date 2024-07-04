#include <iostream>

class MidPointCircle
{
private:
    int radius;

public:
    MidPointCircle(int r)
    {
        radius = r;
    }

    void calCulateOtherQuadrants(float firstQuadrant[][2])
    {
        float secondQuadrant[20][2] = {0};
        float thirdQuadrant[20][2] = {0};
        float fourthQuadrant[20][2] = {0};

        for (int i = 0; i < radius * 2; i++)
        {
            if (firstQuadrant[i][0] == 0 && firstQuadrant[i][1] == 0)
                break;
            secondQuadrant[i][0] = firstQuadrant[i][0] * (-1);
            secondQuadrant[i][1] = firstQuadrant[i][1];

            thirdQuadrant[i][0] = firstQuadrant[i][0] * (-1);
            thirdQuadrant[i][1] = firstQuadrant[i][1] * (-1);

            fourthQuadrant[i][0] = firstQuadrant[i][0];
            fourthQuadrant[i][1] = firstQuadrant[i][1] * (-1);
        }

        std::cout << "Second Quadrant :" << std::endl;
        for (int i = 0; i < 20; i++)
        {

            if (secondQuadrant[i][0] == 0 && secondQuadrant[i][1] == 0)
                break;
            std::cout << (secondQuadrant[i][0] == 0 ? 0 : secondQuadrant[i][0]) << " " << (secondQuadrant[i][1] == 0 ? 0 : secondQuadrant[i][1]) << std::endl;
        }

        std::cout << "Third Quadrant :" << std::endl;
        for (int i = 0; i < 20; i++)
        {

            if (thirdQuadrant[i][0] == 0 && thirdQuadrant[i][1] == 0)
                break;
            std::cout << (thirdQuadrant[i][0] == 0 ? 0 : thirdQuadrant[i][0]) << " " << (thirdQuadrant[i][1] == 0 ? 0 : thirdQuadrant[i][1]) << std::endl;
        }

        std::cout << "Fourth Quadrant :" << std::endl;
        for (int i = 0; i < 20; i++)
        {

            if (fourthQuadrant[i][0] == 0 && fourthQuadrant[i][1] == 0)
                break;
            std::cout <<(fourthQuadrant[i][0] == 0 ? 0 : fourthQuadrant[i][0])  << " " <<(fourthQuadrant[i][1] == 0 ? 0 : fourthQuadrant[i][1]) << std::endl;
        }
    }

    void calculateFirstQuadrant(float firstOctant[][2], float secondOctant[][2])
    {
        float firstQadrant[20][2] = {0};
        int i = 0;
        for (i = 0; i < radius * 2; i++)
        {
            if (firstOctant[i][0] == 0 && firstOctant[i][1] == 0)
                break;
            firstQadrant[i][0] = firstOctant[i][0];
            firstQadrant[i][1] = firstOctant[i][1];
        }

        for (int j = radius * 2 - 1; j >= 0; j--)
        {
            if (secondOctant[j][0] == 0 && secondOctant[j][1] == 0)
                continue;
            firstQadrant[i][0] = secondOctant[j][0];
            firstQadrant[i][1] = secondOctant[j][1];
            i++;
        }

        std::cout << "First Quadrant :" << std::endl;
        for (int i = 0; i < 20; i++)
        {
            if (firstQadrant[i][0] == firstQadrant[i][1])
                continue;
            if (firstQadrant[i][0] == 0 && firstQadrant[i][1] == 0)
                break;
            std::cout << firstQadrant[i][0] << " " << firstQadrant[i][1] << std::endl;
        }
        calCulateOtherQuadrants(firstQadrant);
    }

    void calCulateSecondOctant(float firstOctant[][2])
    {
        float secondOctant[radius * 2][2] = {0};
        for (int i = 0; i < radius * 2; i++)
        {
            if (firstOctant[i][0] == 0 && firstOctant[i][1] == 0)
                continue;
            secondOctant[i][0] = firstOctant[i][1];
            secondOctant[i][1] = firstOctant[i][0];
        }
        std::cout << "Second Octant :" << std::endl;
        for (int i = 0; i < 10; i++)
        {
            if (secondOctant[i][0] == 0 && secondOctant[i][1] == 0)
                break;
            std::cout << secondOctant[i][0] << " " << secondOctant[i][1] << std::endl;
        }

        calculateFirstQuadrant(firstOctant, secondOctant);
    }
    void calculateOneOctant()
    {
        float initialDecessionParameter = float(5 / 4) - radius;
        float points[radius * 2][2] = {0};
        int currX = 0;
        int currY = radius;
        int i = 0;
        float decessionParameter = initialDecessionParameter;
        std::cout << "First Octant :" << std::endl;
        std::cout << currX << " " << currY << std::endl;
        for (; currX <= currY; i++)
        {
            if (currX >= currY)
                break;
            points[i][0] = currX;
            points[i][1] = currY;
            if (decessionParameter < 0)
            {
                decessionParameter = decessionParameter + 2 * currX + 3;
                // currY = currY;
            }
            else
            {
                decessionParameter = decessionParameter + 2 * currX - 2 * currY + 5;
                currY -= 1;
            }
            currX += 1;
            std::cout << currX << " " << currY << std::endl;
        }
        calCulateSecondOctant(points);
    }
};

int main()
{
    MidPointCircle ob(10);
    ob.calculateOneOctant();
    return 0;
}