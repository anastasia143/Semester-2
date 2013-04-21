#pragma once

/**
@class Vector
@brief This class represents one vector and operations with it.
  */
class Vector
{
public:
    Vector(int* coord, int len);
    Vector(const Vector &vector);
    ~Vector();

    int* getCoordinates() { return coordinates; }
    bool isNull();
/**
  Functions for addition and substraction return new vectors that are results of operations
  */
    void operator+=(const Vector* vector2);
    void operator-=(const Vector* vector2);
    int scalarMultiplication(Vector *vector2);
/**
  Coordinates of vector in space and dimension of this space
  */
private:
    int* coordinates;
    int length;
};
