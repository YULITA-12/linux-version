#pragma once

class Number {
public:
    double value;

    Number(double val = 0.0);

    Number plus(Number other);
    Number minus(Number other);
    Number multiply(Number other);
    Number divide(Number other);
};


