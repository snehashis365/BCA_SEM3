#include <iostream>
using namespace std;

class Room
{
   
public: 
    int height, width, breadth;
    Room(int h, int w, int b);
    int volume(){
        int vol = height*width*breadth;
        return vol;
    }
};

Room::Room(int h, int w, int b)
{
    this->height = h;
    this->width = w;
    this->breadth = b;
}
int main()
{
    int h,w,b;
    cout<<"Enter Height: ";
    cin>>h;
    cout<<"Enter Width: ";
    cin>>w;
    cout<<"Enter Breadth: ";
    cin>>b;
    Room room = Room(h, w, b);
    int volume = room.volume();
    cout<<"Volume of room is : "<<volume<<endl;
    return 0;
}
