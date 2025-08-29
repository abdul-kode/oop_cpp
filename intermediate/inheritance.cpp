#include<iostream>
#include <queue>
using namespace std;

class Point {
    public:

    int x;
    int y;

    void print_point();
};
void Point::print_point() {
    cout<<"("<<x<<", "<<y<<")"<<endl;
}

class Shape {
    public:
    int no_of_points;
    Point *points;

    Shape();

    void set_points(Point *p);
    float get_area();
    void show_points();
};
Shape::Shape() {
    cout<<"In shape constructor ..."<<endl;
    points = NULL;
    no_of_points = 0;
}
void Shape::set_points(Point *p) {
    points = p;
}
float Shape::get_area() {
    return -1;
}
void Shape::show_points() {
    Point *temp = points;
    for (int i=0; i<no_of_points; i++) {
        temp->print_point();
        temp++;
    }
}


class Triangle: public Shape {
    public:

    Triangle();
    float get_area();
};
Triangle::Triangle(){
    cout<<"In Triangle constructor ..."<<endl;
    no_of_points = 3;
}
float Triangle::get_area () {
    int x0, x1, x2, y0, y1, y2;
    Point *t = points;

    x0 = t->x; y0 = t->y; t++;
    x1 = t->x; y1 = t->y; t++;
    x2 = t->x; y2 = t->y;

    return abs(x0 * (y1-y2) + x1 * (y2-y0) + x2 * (y0 -y1) / 2);
}

void create_shape() {
    Triangle *t = new Triangle;

    Point p1, p2, p3;
    p1.x = p1.y = 10;
    p2.x = p2.y = 20;
    p3.x = p3.y = 30;

    Point *points_of_triangle;
    points_of_triangle = new Point[3];

    points_of_triangle[0] = p1;
    points_of_triangle[1] = p2;
    points_of_triangle[2] = p3;

    t->set_points(points_of_triangle);
    t->show_points();

    cout<<"Area of t: "<<t->get_area()<<endl;
}

int main () {
    create_shape();
    return 0;
}
