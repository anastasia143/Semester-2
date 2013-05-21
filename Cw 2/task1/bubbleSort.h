#pragma once

/**
  @class Comparatative
  Heritors of this class implement virtual function for comparison different types.
  */
template <class C>
class Comparative
{
// bool compare() return TRUE if elementOne > elementTwo
public:
    virtual bool compare(C elementOne, C elementTwo) = 0;
};

/**
  @class BubbleSort
  This class allows to sort arrays of different types by using object-comparative.
  */
template <class T>
class BubbleSort
{
public:
    template <class C>
    void sort(T* array, int size, Comparative<C>* comparative)
    {
        for (int i = 0; i < size - 1; i++)
        {
            for (int k = 0; k < size - i - 1; k++)
                if (comparative->compare(array[k], array[k + 1]))
                    swap(array, k, k + 1);
        }
    }

private:
    void swap(T* array, int elementOne, int elementTwo)
    {
        T temp = array[elementOne];
        array[elementOne] = array[elementTwo];
        array[elementTwo] = temp;
    }
};
