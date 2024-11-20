#include <iostream>
using namespace std;
class Rectangle{
private:
    double length, width;
public:
    void setLength(double len){
        length = len;
    }
    double getLength(){
        return length;
    }
    void setWidth(double w){
        width = w;
    }
    double getWidth(){
        return width;
    }
    double calculateArea() {
        return length * width;
    }
};
int main(){
    Rectangle rect;
    rect.setLength(5.0);
    rect.setWidth(3.0);
    cout << "The area of the rectangle is: " << rect.calculateArea() << endl;
    return 0;
}


