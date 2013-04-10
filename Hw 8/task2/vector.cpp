#include "vector.h"

Vector::Vector(int* coord, int len)
{
    coordinates = new int[len];
    length = len;
    for(int i = 0; i < len; i++)
        coordinates[i] = coord[i];
}

Vector::Vector(const Vector &vector)
{
    coordinates = new int[vector.length];
    length = vector.length;
    for(int i = 0; i < length; i++)
        coordinates[i] = vector.coordinates[i];
}

bool Vector::isNull()
{
    for(int i = 0; i < length; i++)
        if (coordinates[i] != 0)
            return false;
    return true;
}

int* Vector::addition(Vector* vector2)
{
    int* result = new int[length];
    for(int i = 0; i < length; i++)
        result[i] = coordinates[i] + vector2->coordinates[i];
    return result;
}

int* Vector::subtraction(Vector* vector2)
{
    int* result = new int[length];
    for(int i = 0; i < length; i++)
        result[i] = coordinates[i] - vector2->coordinates[i];
    return result;
}

int Vector::scalarMultiplication(Vector* vector2)
{
    int result = 0;
    for(int i = 0; i < length; i++)
        result = result + coordinates[i] * vector2->coordinates[i];
    return result;
}

Vector::~Vector()
{
    delete[] coordinates;
}
