//
// Created by 陈智彬 on 2022/5/18.
//

#include "point.h"
#ifndef FOURTH_CPP_CIRCLE_H
#define FOURTH_CPP_CIRCLE_H
class Circle: public Point {
public:
    Circle(float x = 0, float y = 0, float r = 0);
    void SetRadius(float matter);
    float GetRadius() const;
    float area() const;
    friend ostream &operator<<(ostream &output, const Circle &matter);

private:
    float radius;
};
#endif //FOURTH_CPP_CIRCLE_H
