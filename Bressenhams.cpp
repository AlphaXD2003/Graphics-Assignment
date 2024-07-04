#include <iostream>
#include <cmath>

class Bressenhams{

    private:
        int x1, x2, y1, y2;
    public:
        Bressenhams(int x1, int y1, int x2, int y2){
            this->x1 = x1;
            this->y1 = y1;
            this->x2 = x2;
            this->y2 = y2;
        }

        void applyBressenhams(){
            int dx = x2 - x1;
            int dy = y2 - y1;
            int initialDecessionParameter = 2 * dy - dx;
            float m = float(dy) / float (dx);
            int decessionParameter;
            decessionParameter = initialDecessionParameter;
            int steps = std::max(std::abs(dx) , std::abs(dy));
            std::cout<<steps<<std::endl;
            std::cout<<x1<<" "<<y1<<std::endl;
            int x,y;
            x = x1; y = y1;
            if(m < 1) {
                for(int i = 0; i < steps; i++){
                    if(decessionParameter < 0){
                        decessionParameter = decessionParameter + 2 * dy;
                        x = x + 1;
                        y = y ;
                    }else{
                        decessionParameter = decessionParameter + 2 * dy - 2 * dx;
                        x = x + 1;
                        y = y + 1;
                    }
                    std::cout<<x<<" "<<y<<std::endl;
                }
            }
            else {
                for(int i = 0; i < steps; i++){
                    if(decessionParameter < 0){
                        decessionParameter = decessionParameter + 2 * dx;
                        y = y + 1;
                        x = x ;
                    }else{
                        decessionParameter = decessionParameter + 2 * dx - dy;
                        y = y +1;
                        x = x +1;
                    }
                    std::cout<<x<<" "<<y<<std::endl;
                }
            }

        }
};

int main(){
    Bressenhams br(0,0,9,5);
    br.applyBressenhams();
    return 0;
}