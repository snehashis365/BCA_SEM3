#include <iostream>
using namespace std;

class Shape
{
private:
    /* data */
public:
    int calcArea(int side){
        cout<<"Square ";
        return side*side;
    }
    int calcArea(int l, int b){
        cout<<"Rectangle ";
        return l*b;
    }
    float calcArea(float h, float b){
        cout<<"Triangle ";
        return (h*b)/2;
    }
};

int main(int argc, char const *argv[])
{
    Shape shape;
    if (argc == 3)
    {
        float a = atof(argv[1]);
        float b = atof(argv[2]);
        cout<<"Area : "<<shape.calcArea(a,b)<<endl;
    }
    else if(argc == 2)
    {
        int side = atoi(argv[1]);
        cout<<"Area : "<<shape.calcArea(side)<<endl;
    }
    else
    {
        cout<<"Wrong number of arguments"<<endl;
    }  
    return 0;
}

