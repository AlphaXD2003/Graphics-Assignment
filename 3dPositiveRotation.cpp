#include <iostream>
#include <cmath>

class threeDpositiveRotaion
{
private:
    int x, y, z;

    float radian;

public:
    threeDpositiveRotaion(int x, int y, int z, float angle)
    {
        this->x = x;
        this->y = y;
        this->z = z;

        this->radian = angle * (M_PI / 180);
    }

    void printData(int result[4][1])
    {
        for (int i = 0; i < 4; i++)
        {
            std::cout << result[i][0] << std::endl;
        }
    }

    void rotate()
    {
        int input[4][1];
        input[0][0] = x;
        input[1][0] = y;
        input[2][0] = z;
        input[3][0] = 1;

        int main[4][4];
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (i == j)
                    main[i][j] = 1;
                else
                    main[i][j] = 0;
            }
        }
        int result[4][1] = {0};

        // X Axis

        main[1][1] = std::cos(radian);
        main[1][2] = std::sin(radian) * (-1);
        main[2][1] = std::sin(radian);
        main[2][2] = std::cos(radian);

        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                result[i][0] += main[i][j] * input[j][0];
            }
        }
        std::cout << "X Axis rotation" << std::endl;
        printData(result);

        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (i == j)
                    main[i][j] = 1;
                else
                    main[i][j] = 0;
            }
        }
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                result[i][j] = 0;
            }
        }

        main[0][0] = std::cos(radian);
        main[0][2] = std::sin(radian);
        main[2][0] = std::sin(radian) * (-1);
        main[2][2] = std::cos(radian);

        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                result[i][0] += main[i][j] * input[j][0];
            }
        }
        std::cout << "Y Axis rotation" << std::endl;
        printData(result);

        // Z Axis
        // bhai r bhalo lgache na kore ne net dekhe. just value change
    }
};

int main()
{
    threeDpositiveRotaion ob(1, 2, 3, 90);
    ob.rotate();
    return 0;
}