#include <iostream>
#include <cmath>


class Daa
{
private:
    int x1, x2, y1, y2;

public:
    Daa(int x1, int x2, int y1, int y2)
    {
        this->x1 = x1;
        this->x2 = x2;
        this->y1 = y1;
        this->y2 = y2;
    }

    void applyDaa()
    {
        int dx = x2 - x1;
        int dy = y2 - y1;
        int steps = std::max(dx, dy);
        float xIncreament = float(dx) / float(steps);
        float yIncreament = float(dy) / float(steps);

        for (int i = 0; i < steps; i++)
        {
            std::cout << std::ceil(x1) << " " << std::ceil(y1) << std::endl;
            // Draw the point
            x1 += xIncreament;
            y1 += yIncreament;
        }
        std::cout << std::ceil(x1) << " " << std::ceil(y1) << std::endl;
    }
};

int main()
{

    Daa d(0, 10, 0, 10);

    d.applyDaa();

    return 0;
}