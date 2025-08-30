#include <cstdio>
#include <iostream>
using namespace std;

class Point {
    public:
    int x;
    int y;

    void print_points ();
};
void Point::print_points() {
    cout<<"("<<x<<", "<<y<<")"<<endl;
}

class Shape {
    public:
    Point *points;
    int no_of_points;

    Shape();
    void set_points(Point *p);
    float get_area();
    void show_points();
};
Shape::Shape() {
    cout<<"In shape constructor ..."<<endl;
    no_of_points = 0;
}
void Shape::set_points(Point *p) {
    points = p;
}
float Shape::get_area () {
    return -1;
}
void Shape::show_points() {
    Point *temp = points;
    for (int i=0; i<no_of_points; i++) {
        temp->print_points();
        temp++;
    }
}

class Rectangle : public Shape {
    public:

    Rectangle();
    float get_area();
};
Rectangle::Rectangle() {
    cout<<"In Rectangle's Constructor"<<endl;
    no_of_points = 4;
}
float Rectangle::get_area() {
    Point *t = points;
    int x0, x1, x2, x3, y0, y1, y2, y3;

    x0 = t->x; y0 = t->y; t++;
    x1 = t->x; y1 = t->y; t++;
    x2 = t->x; y2 = t->y; t++;
    x3 = t->x; y2 = t->y;

    float formula = 5.0;

    return formula;
}


void create_points () {
    Rectangle *r = new Rectangle;

    Point p1, p2, p3, p4;
    p1.x = p1.y = 10;
    p2.x = p2.y = 20;
    p3.x = p3.y = 30;
    p4.x = p4.y = 40;

    Point *points_of_rectangle = new Point[4];

    points_of_rectangle[0] = p1;
    points_of_rectangle[1] = p2;
    points_of_rectangle[2] = p3;
    points_of_rectangle[3] = p4;

    r->set_points(points_of_rectangle);
    r->show_points();

    cout<<"Area of rectangle is: "<<r->get_area()<<endl;
}

int main () {
    create_points();
    return 0;
}
