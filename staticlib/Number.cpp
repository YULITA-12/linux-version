#include "Number.h"

Number::Number(double val) {
    value = val;
}

Number Number::plus(Number other) {
    double result = value + other.value;
    return Number(result);
}

Number Number::minus(Number other) {
    double result = value - other.value;
    return Number(result);
}

Number Number::multiply(Number other) {
    double result = value * other.value;
    return Number(result);
}

Number Number::divide(Number other) {
    double result = value / other.value;
    return Number(result);
}
