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

    bool isNull();
/**
  Functions for addition and substraction return new vectors that are results of operations
  */
    int* addition(Vector* vector2);
    int* subtraction(Vector* vector2);
    int scalarMultiplication(Vector *vector2);
private:
/**
  Coordinates of vector in space and dimension of this space
  */
    int* coordinates;
    int length;
};
