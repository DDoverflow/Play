//
// Created by 陈智彬 on 2022/5/18.
//

#include "circle.h"
#ifndef FOURTH_CPP_CYLINDER_H
#define FOURTH_CPP_CYLINDER_H
class Cylinder: public Circle {
public:
    Cylinder(float x = 0, float y = 0, float r = 0, float h = 0);
    void SetHeight(float matter);
    float GetHeight() const;
    float area() const;
    float volume() const;
    friend ostream &operator<<(ostream &output, const Cylinder &matter);
protected:
    float height;
};
#endif //FOURTH_CPP_CYLINDER_H
