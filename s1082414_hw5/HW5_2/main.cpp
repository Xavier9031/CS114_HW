#include <iostream>
#include <cmath>
#include<string>
#include<vector>
using namespace std;

class Shape{
  protected:
    string name;
  public:
    void get_name(){
      cout << name << endl;
    }
    virtual void get_Area(){};
    virtual void get_Volume(){};
    virtual void print_data(){};//print information of object 
};

class TwoDimensionalShape:public Shape{
  protected:
    double Area;
  public:
    void get_Area(){
      cout << "area : " << Area << endl;
    }
    void print_data(){
      get_name();
      get_Area();
      cout << endl;
    }
};
class Circle:public TwoDimensionalShape{
  private:
    double r;
  public:
    Circle(double _r){
      name = "Circle";
      r = _r;
      Area = r*r*M_PI;
    }
};
class Square:public TwoDimensionalShape{
  private:
    double a;
  public:
    Square(double _a){
      name = "Square";
      a = _a;
      Area = a*a;
    }
};
class Triangle:public TwoDimensionalShape{
  private:
    double h;
    double b;
  public:
    Triangle(double _h, double _b){
      name = "Triangle";
      h = _h;
      b = _b;
      Area = h*b/2;
    }
};

class ThreeDimensionalShape:public Shape{
  protected:
    double Area;
    double Volume;
  public:
    void get_Area(){
      cout << "area : " << Area << endl;
    }
    void get_Volume(){
      cout << "volume : " << Volume << endl;
    }
    void print_data(){
      get_name();
      get_Area();
      get_Volume();
      cout << endl;
    }
};
class Sphere:public ThreeDimensionalShape{
  private:
    double r;
  public:
    Sphere(double _r){
      name = "Sphere";
      r = _r;
      Area = 4*r*r*M_PI;
      Volume = r*r*r*M_PI*4/3;
    }
};
class Cube:public ThreeDimensionalShape{
  private:
    double a;
  public:
    Cube(double _a){
      name = "Cube";
      a = _a;
      Area = 6*a*a;
      Volume = a*a*a;
    }
};
class Tetrahedron:public ThreeDimensionalShape{
  private:
    double a;
  public:
    Tetrahedron(double _a){
      name = "Tetrahedron";
      a = _a;
      Area = sqrt(3)*a*a;
      Volume = a*a*a/(6*sqrt(2));
    }
};
int main() {
  double a,h;//temp input
  
  vector<Shape*> ptr;//vector of shape pointers
  //input
  
  
  ptr.push_back(new Circle(10));
  
  ptr.push_back(new Square(20));
  
  ptr.push_back(new Triangle(10,20));

  ptr.push_back(new Sphere(10));
  
  ptr.push_back(new Cube(10));
  
  ptr.push_back(new Tetrahedron(10));

  //output
  cout  << "========OUTPUT========" << endl;
  for(int i = 0; i < ptr.size(); ++i){
    ptr[i]->print_data();
  }
  return 0;
}