#include<iostream>

class PointClipping{
    private:
        int x,y,xmax, xmin, ymax, ymin;
    public:
    PointClipping(int x, int y, int xmax, int xmin, int ymax, int ymin){
        this->x = x;
        this->y = y;
        this->xmax = xmax;
        this->xmin = xmin;
        this->ymax = ymax;
        this->ymin = ymin;
    }

    void clip(){
        if(x > xmax && x < xmin && y > ymax && y < ymin){
            std::cout << "Point is outside the rectangle" << std::endl;
        }
        else{
            std::cout << "Point is inside the rectangle" << std::endl;
        }

    }
};

int main(){
    PointClipping p(10,10,20,0,20,0);
    p.clip();

    return 0;
}