//
// Created by 陈智彬 on 2022/5/18.
//

#ifndef FOURTH_CPP_POINT_H
#define FOURTH_CPP_POINT_H
class Point {
public:
    Point(float x = 0, float y = 0);
    void SetPoint(float matter1, float matter2);
    float GetX() const {return x;}
    float GetY() const {return y;}
    friend ostream &operator<<(ostream &out, const Point &matter);

protected:
    float x, y;
};
#endif //FOURTH_CPP_POINT_H
