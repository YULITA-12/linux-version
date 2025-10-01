#pragma once
#include "../staticlib/Number.h"

class Vector {
public:
    Number x;
    Number y;

    Vector(Number x_val, Number y_val);
    Vector();

    Number getLength();
    Number getAngle();
    Vector add(Vector other);
};
