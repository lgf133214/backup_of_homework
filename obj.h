//
// Created by ¿Ó∏ﬂ∑Â on 2020/4/11.
//
#ifndef ROBOT_OBJ_H
#define ROBOT_OBJ_H


class obj {
    // ax + by + c = 0
    // (x, y)   r
    // (x1, y1) (x2, y2) (x3, y3) (x4, y4)
private:
    double a{};
    double b{};
    double c{};

    double x{};
    double y{};
    double r{};

    double x1{};
    double x2{};
    double x3{};
    double x4{};
    double y1{};
    double y2{};
    double y3{};
    double y4{};

    void setA(double n);

    void setB(double n);

    void setC(double n);

    void setX(double n);

    void setY(double n);

    void setR(double n);

    void setX1(double n);

    void setX2(double n);

    void setX3(double n);

    void setX4(double n);

    void setY1(double n);

    void setY2(double n);

    void setY3(double n);

    void setY4(double n);

    bool isRectangle();

    void sortRec();

    bool util1(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4);

    bool util2(double x1, double y1, double x2, double y2);

public:
    obj(double a, double b, double c);

    ~obj();

    void setLine(double a, double b, double c);

    void setCircle(double x, double y, double r);

    void setRectangle(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4);

    void getLine();

    void getCircle();

    void getRectangle();

    void line2line(double a, double b, double c);

    void line2circle();

    void line2rectangle();
};


#endif //ROBOT_OBJ_H
