//
// Created by ��߷� on 2020/4/11.
//
#include "obj.h"
#include <iostream>
#include <cmath>

using namespace std;

obj::obj(double a, double b, double c) {
    // ������һ��ֱ��
    setLine(a, b, c);
}

obj::~obj() {
}

void obj::setA(double n) {
    a = n;
}

void obj::setB(double n) {
    b = n;
}

void obj::setC(double n) {
    c = n;
}

void obj::setX(double n) {
    x = n;
}

void obj::setY(double n) {
    y = n;
}

void obj::setR(double n) {
    r = n;
}

void obj::setX1(double n) {
    x1 = n;
}

void obj::setX2(double n) {
    x2 = n;
}

void obj::setX3(double n) {
    x3 = n;
}

void obj::setX4(double n) {
    x4 = n;
}

void obj::setY1(double n) {
    y1 = n;
}

void obj::setY2(double n) {
    y2 = n;
}

void obj::setY3(double n) {
    y3 = n;
}

void obj::setY4(double n) {
    y4 = n;
}

void obj::setLine(double a, double b, double c) {
    if (a == 0 && b == 0) {
        cout << "��Ĳ���Ŷ" << endl;
        return;
    }
    setA(a);
    setB(b);
    setC(c);
}

void obj::setCircle(double x, double y, double r) {
    if (r < 0) {
        cout << "�뾶��Ҫ���� 0" << endl;
        return;
    }
    setX(x);
    setY(y);
    setR(r);
}

void obj::setRectangle(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4) {
    setX1(x1);
    setX2(x2);
    setX3(x3);
    setX4(x4);
    setY1(y1);
    setY2(y2);
    setY3(y3);
    setY4(y4);
    isRectangle();
}

bool obj::isRectangle() {
    // �ĸ���ͬ�ĵ�
    if (
            (x1 == x2 && y1 == y2) || (x1 == x3 && y1 == y3) || (x1 == x4 && y1 == y4) ||
            (x2 == x3 && y2 == y3) || (x2 == x4 && y2 == y4) ||
            (x3 == x4 && y3 == y4)
            ) {
        goto INIT;
    }
    // ��������ֱ��
    // �����ߣ�����֮��ļн����ֵ == 90�� ���� false
    if (!(
            util1(x1, y1, x2, y2, x3, y3, x4, y4) ||
            util1(x2, y2, x1, y1, x3, y3, x4, y4) ||
            util1(x3, y3, x1, y1, x2, y2, x4, y4)
    )) {
        // ������
        sortRec();
        return true;
    }
    INIT:
    setX1(0);
    setX2(0);
    setX3(0);
    setX4(0);
    setY1(0);
    setY2(0);
    setY3(0);
    setY4(0);
    cout << "����һ������" << endl;
    return false;
}

void obj::sortRec() {
    double v1x = x2 - x1;
    double v1y = y2 - y1;

    double v2x = x3 - x1;
    double v2y = y3 - y1;

    double v3x = x4 - x1;
    double v3y = y4 - y1;

    double v1 = (v1x * v2x + v1y * v2y) / (sqrt(pow(v1x, 2) + pow(v1y, 2)) * sqrt(pow(v2x, 2) + pow(v2y, 2)));
    double v2 = (v3x * v2x + v3y * v2y) / (sqrt(pow(v3x, 2) + pow(v3y, 2)) * sqrt(pow(v2x, 2) + pow(v2y, 2)));

    if (v1 == 0) {
        // ���� ���ĸ��͵�������
        double tmpx = x3, tmpy = y3;
        x3 = x4, y3 = y4;
        x4 = tmpx, y4 = tmpy;
    } else if (v2 == 0) {
        // ���� �ڶ����͵�������
        double tmpx = x3, tmpy = y3;
        x3 = x2, y3 = y2;
        x2 = tmpx, y2 = tmpy;
    }
}

bool obj::util1(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4) {
    double v1x = x2 - x1;
    double v1y = y2 - y1;

    double v2x = x3 - x1;
    double v2y = y3 - y1;

    double v3x = x4 - x1;
    double v3y = y4 - y1;

    double v1 = (v1x * v2x + v1y * v2y) / (sqrt(pow(v1x, 2) + pow(v1y, 2)) * sqrt(pow(v2x, 2) + pow(v2y, 2)));
    double v2 = (v1x * v3x + v1y * v3y) / (sqrt(pow(v1x, 2) + pow(v1y, 2)) * sqrt(pow(v3x, 2) + pow(v3y, 2)));
    double v3 = (v3x * v2x + v3y * v2y) / (sqrt(pow(v3x, 2) + pow(v3y, 2)) * sqrt(pow(v2x, 2) + pow(v2y, 2)));

    // ���ȱ�������ǣ������һ�� == 90��
    return !(v1 >= 0 && v2 >= 0 && v3 >= 0) || !(v1 == 0 || v2 == 0 || v3 == 0);
}

void obj::line2line(double a, double b, double c) {
    // ������ֱ�߱Ƚ�
    if ((a == 0 && b == 0) || (this->a == 0 && this->b == 0)) {
        cout << "ֱ�߲��ԣ�û����Ŷ" << endl;
        return;
    }
    if (this->a * b - this->b * a != 0) {
        // �ཻ��һ��
        double x = (this->b * c - b * this->c) / (this->a * b - a * this->b);
        double y = (a * this->c - this->a * c) / (this->a * b - a * this->b);
        cout << "���㣺 (" << x << ", "
             << y << ")" << endl;
    } else if (this->a * c - a * this->c == 0) {
        cout << "�غ�" << endl;
    } else {
        cout << "ƽ��" << endl;
    }
    cout<<endl;
}

void obj::line2circle() {
    // �ڲ���ֱ�ߺ�԰�Ƚ�
    if (a == 0 && b == 0) {
        cout << "ֱ�߲��ԣ�û����Ŷ" << endl;
        return;
    }
    if (r == 0) {
        // ���ܱȽ�
        cout << "Բ�İ뾶Ϊ 0��û����Ŷ" << endl;
        return;
    }
    double d = abs(a * x + b * y + c) / sqrt(pow(a, 2) + pow(b, 2));
    if (d > r) {
        // �޽���
        cout << "�޽���" << endl;
        cout<<endl;
        return;
    }
    // �н�����Ҫ�ж�ֱ�ߵ� b �ǲ��� 0����Ϊ�ҵĹ�ʽ�Ǵ�б�ʵģ�û�ҵ����õ�( $ _ $ )
    // ���⣬���ھ��ȵ�������ֻ��һ����������������㲻���� (nan.nan) ��������ʵ�����������£������Ż���С����ʱ�򲻿���
    if (b == 0) {
        if (d == r) {
            double x_ = -c / a;
            double y_ = sqrt(pow(r, 2) - pow(x_ - x, 2)) + y;
            cout << "���㣺��" << x_ << ", " << y_ << ")" << endl;
            cout<<endl;
            return;
        } else {
            double x_ = -c / a;
            double y1_ = sqrt(pow(r, 2) - pow(x_ - x, 2)) + y;
            double y2_ = -sqrt(pow(r, 2) - pow(x_ - x, 2)) + y;
            cout << "���㣺(" << x_ << ", " << y1_ << ") (" << x_ << ", " << y2_ << ")" << endl;
            cout<<endl;
            return;
        }
    }
    // ��������ʽ��
    if (d == r) {
        double x_ = -(sqrt(pow(r, 2) * (1 + pow(a / b, 2)) - pow(x, 2) * pow(a / b, 2) -
                           (2 * x * y + 2 * c * x / b) * a / b - pow(y, 2) - 2 * c * y / b - pow(c / b, 2)) +
                      (y + c / b) * (a / b) - x) / (1 + pow(a / b, 2));
        double y_ = -(-a / b * (sqrt(pow(a / b, 2) * pow(r, 2) + pow(r, 2)
                                     - pow(x, 2) * pow(a / b, 2) - x * x * y * a / b - x * x * a * c / pow(b, 2) -
                                     pow(y, 2)
                                     - 2 * c * y / b - pow(c / b, 2)) - x) - y * pow(a / b, 2) + c / b) /
                    (1 + pow(a / b, 2));

        cout << "���㣺��" << x_ << ", " << y_ << ")" << endl;
    } else {
        double x1_ = -(sqrt(pow(r, 2) * (1 + pow(a / b, 2)) - pow(x, 2) * pow(a / b, 2) -
                            (2 * x * y + 2 * c * x / b) * a / b - pow(y, 2) - 2 * c * y / b - pow(c / b, 2)) +
                       (y + c / b) * (a / b) - x) / (1 + pow(a / b, 2));
        double y1_ = -(-a / b * (sqrt(pow(a / b, 2) * pow(r, 2) + pow(r, 2)
                                      - pow(x, 2) * pow(a / b, 2) - x * x * y * a / b - x * x * a * c / pow(b, 2) -
                                      pow(y, 2)
                                      - 2 * c * y / b - pow(c / b, 2)) - x) - y * pow(a / b, 2) + c / b) /
                     (1 + pow(a / b, 2));
        double x2_ = (sqrt(pow(r, 2) * (1 + pow(a / b, 2)) - pow(x, 2) * pow(a / b, 2) -
                           (2 * x * y + 2 * c * x / b) * a / b - pow(y, 2) - 2 * c * y / b - pow(c / b, 2)) -
                      (y + c / b) * (a / b) + x) / (1 + pow(a / b, 2));
        double y2_ = -(-a / b * (-sqrt(pow(a / b, 2) * pow(r, 2) + pow(r, 2)
                                       - pow(x, 2) * pow(a / b, 2) - x * x * y * a / b - x * x * a * c / pow(b, 2) -
                                       pow(y, 2)
                                       - 2 * c * y / b - pow(c / b, 2)) - x) - y * pow(a / b, 2) + c / b) /
                     (1 + pow(a / b, 2));

        cout << "���㣺(" << x1_ << ", " << y1_ << ") (" << x2_ << ", " << y2_ << ")" << endl;
    }
    cout<<endl;
}

void obj::line2rectangle() {
    // �ڲ���ֱ�ߺ;��αȽ�
    if (a == 0 && b == 0) {
        cout << "ֱ�߲��ԣ�û����Ŷ" << endl;
        return;
    }
    if (!isRectangle()) {
        cout << "���β��ԣ�û����Ŷ" << endl;
        return;
    }
    // ֱ�ߺ������߶εĽ���
    bool flag = false;
    flag = util2(x1, y1, x2, y2) ? true : flag;
    flag = util2(x2, y2, x3, y3) ? true : flag;
    flag = util2(x3, y3, x4, y4) ? true : flag;
    flag = util2(x4, y4, x1, y1) ? true : flag;
    if (!flag)
        cout << "ֱ�ߺ;���û�н���" << endl;
    cout<<endl;
}

bool obj::util2(double x1, double y1, double x2, double y2) {
    // ����ֱ����
    // �����ظ���ֻ����ǰһ����
    if (a * x1 + b * y1 + c == 0) {
        cout << "����ν��㣺(" << x1 << ", " << y1 << ")" << endl;
        return true;
    }
    // �㲻��ֱ����
    // �ж��ڲ���ͬһ��

    // ֱ�߷�������
    double vx, vy;
    double tmpx, tmpy;
    if (a == 0) {
        tmpx = 0, tmpy = -c / b;
        vx = 1, vy = 0;
    } else if (b == 0) {
        tmpx = -c / a, tmpy = 0;
        vx = 0, vy = 1;
    } else {
        tmpx = 0, tmpy = -c / b;
        vx = 1, vy = (-a) / b;
    }
    // ���һ��һ��
    if ((vx * (y1 - tmpy) - vy * (x1 - tmpx)) * (vx * (y2 - tmpy) - vy * (x2 - tmpx)) >= 0) {
        // ��ֱ�ߵ�һ�࣬�޽���
        return false;
    } else {
        // ��һ������
        double para = (vx * (y1 - tmpy) - (x1 - tmpx) * vy) / ((x2 - tmpx) * vy - vx * (y2 - tmpy));
        cout << "����ν��㣺(" << (para * x2 + x1) / (para + 1) << ", " << (para * y2 + y1) / (para + 1) << ")" << endl;
        return true;
    }
}

void obj::getLine() {
    cout << "line: " << a << "*x + " << b << "*y + " << c << " = 0" << endl;
}

void obj::getCircle() {
    cout << "circle: Բ�ģ�(" << x << ", " << y << ") " << "r = " << r << endl;
}

void obj::getRectangle() {
    cout << "rectangle: x1 = " << x1 << ", y1 = " << y1 << ", x2 = " << x2 << ", y2 = " << y2 << ", x3 = " << x3
         << ", y3 = " << y3 << ", x4 = " << x4 << ", y4 = " << y4 << endl;
}