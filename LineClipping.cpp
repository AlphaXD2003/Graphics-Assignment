// Cohen Sutherland algorithm

#include<iostream>

class LineClipping{
    private:
        int x1,y1,x2,y2,xmax, xmin, ymax, ymin;
        float slope;
    public:
    LineClipping(int x1, int y1, int x2, int y2, int xmax, int xmin, int ymax, int ymin){
        this->x1 = x1;
        this->y1 = y1;
        this->x2 = x2;
        this->y2 = y2;
        this->xmax = xmax;
        this->xmin = xmin;
        this->ymax = ymax;
        this->ymin = ymin;
        slope = (float)(y2 - y1) / (float)(x2 - x1);
    }

    int* returnTBRL(int x, int y){
        int* tbrl = new int[4];
        tbrl[0] = (y - ymax > 0) ? 1: 0;
        tbrl[1] = (ymin - y > 0) ? 1: 0;
        tbrl[2] = (x - xmax > 0) ? 1: 0;
        tbrl[3] = (xmin - x > 0) ? 1: 0;
        return tbrl;
    }

    int computeOutcode(int x, int y){
        int outcode = 0;
        if(y > ymax) outcode = 8; // Top
        else if(y < ymin) outcode = 4; // Bottom
        if(x > xmax) outcode = 2; // Right
        else if(x < xmin) outcode = 1; // Left
        std::cout<<"Outcode = "<<outcode<<std::endl;
        return outcode;
    }

    int* returnClippedPoint(int x, int y){
        int* clippedPoint = new int[2];
        
        int tbrl = computeOutcode(x, y);
       std::cout<<"TBRL = "<<tbrl<<std::endl;
        if(tbrl == 8){
            std::cout<<"Top"<<std::endl;
            x = x + (ymax - y) / slope;
            clippedPoint[0] = x;
            clippedPoint[1] = ymax;
        }else if(tbrl == 4){
            std::cout<<"Bottom"<<std::endl;
            x = x + (ymin - y) / slope;
            clippedPoint[0] = x;
            clippedPoint[1] = ymin;
        }else if(tbrl == 2){
            std::cout<<"Right"<<std::endl;
            y = y + (xmax - x) * slope;
            clippedPoint[0] = xmax;
            clippedPoint[1] = y;
        }else if(tbrl == 1){
            std::cout<<"Left"<<std::endl;
            y = y + (xmin - x) * slope;
            clippedPoint[0] = xmin;
            clippedPoint[1] = y;
        }
        return clippedPoint;


    }

    void clip(){
        int* tbrl1 = returnTBRL(x1,y1);
        int* tbrl2 = returnTBRL(x2,y2);
    std::cout<<"TBRL 1 ( "<<tbrl1[0]<<", "<<tbrl1[1]<<", "<<tbrl1[2]<<", "<<tbrl1[3]<<")" << std::endl;
    std::cout<<"TBRL 2 ( "<<tbrl2[0]<<", "<<tbrl2[1]<<", "<<tbrl2[2]<<", "<<tbrl2[3]<<")" << std::endl;
        if(tbrl1[0] == 0 && tbrl1[1] == 0 && tbrl1[2] == 0 && tbrl1[3] == 0){
            std::cout<<"( "<<x1<<", "<<y1<<")" << "The Point is inside the rectangle" << std::endl; 
        }
        if (tbrl1[0] == 0 && tbrl1[1] == 0 && tbrl1[2] == 0 && tbrl1[3] == 0){
            std::cout<<"( "<<x2<<", "<<y2<<")" << "The Point is inside the rectangle" << std::endl; 
        }

        if(tbrl1[0] == 0 && tbrl1[1] == 0 && tbrl1[2] == 0 && tbrl1[3] == 0 && tbrl2[0] == 0 && tbrl2[1] == 0 && tbrl2[2] == 0 && tbrl2[3] == 0){
        
             std::cout<<"Line is inside the rectangle" << std::endl;
             return;
        }
        int temp[4] = {0};
        for(int i = 0; i < 4; i++){
            temp[i] = tbrl1[i] | tbrl2[i];
        }

        bool clippedCase = false;
        bool visibleCase = true;
        bool invisibleCase = false;
        for(int i = 0; i < 4; i++){
            if(temp[i] != 0){
                clippedCase = true;
                visibleCase = false;
                invisibleCase = false;
            }
        }
        if(visibleCase){
            std::cout<<"Line is visible" << std::endl;
            return;
        }

        temp[4] = {0};
        for(int i = 0; i < 4; i++){
            temp[i] = tbrl1[i] & tbrl2[i];
        }

        clippedCase = true  ;
        invisibleCase = false;

        for(int i = 0; i < 4; i++){
            if(temp[i] != 0){
                invisibleCase = true;
                clippedCase = false;
            }
        }
        if(invisibleCase){
            std::cout<<"Line is invisible" << std::endl;
            return;
        }

       
            std::cout<<"Line needs to be clipped" << std::endl;
            std::cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<std::endl;
            int* clippedPoint1 = returnClippedPoint(x1,y1);
            int* clippedPoint2 = returnClippedPoint(x2,y2);
            std::cout<<"Clipped Point 1 ( "<<clippedPoint1[0]<<", "<<clippedPoint1[1]<<")" << std::endl;
            std::cout<<"Clipped Point 2 ( "<<clippedPoint2[0]<<", "<<clippedPoint2[1]<<")" << std::endl;
        
    }

};

int main(){
    // int x1, int y1, int x2, int y2, int xmax, int xmin, int ymax, int ymin
    LineClipping l(35,10,65,40,80,50,40,10);
    l.clip();

    return 0;
}