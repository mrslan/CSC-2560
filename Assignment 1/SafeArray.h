#pragma once
#include <string>
#include "SafeArrayException.h"
using namespace std;
template < typename T >

class SafeArray
{
public:

    int index = 0;
    T* allVals = new T[10];
    int totalSize = 10;
    ~SafeArray();
    void resize(int newSize);
    void erase(int pos);
    void push_back(T newVal);
    void pop_back();
    int size();
    T& at(int pos);
    T& operator[](int pos);
    void doubleAr();
    void halveAr();

};
//--
template < typename T >SafeArray<T>::~SafeArray(){
    delete[] allVals;
    allVals = NULL;
}
//--
template < typename T >void SafeArray<T>::resize(int newSize){
    delete[] allVals;
    T* newAr = new T[newSize * 2];
    index = newSize;
    allVals = newAr;
}
//--
template < typename T >void SafeArray<T>::erase(int pos){
    T* newAr = new T[totalSize];
    for (int i = 0; i < (totalSize/2); i++){
        if (i != pos) newAr[i] = allVals[i];
    }
    delete[] allVals;
    allVals = newAr;
    pop_back();
}
//--
template < typename T >void SafeArray<T>::push_back(T newVal){
    if (index == totalSize - 1) doubleAr();
    allVals[index] = newVal;
    index++;
}
//--
template < typename T >void SafeArray<T>::pop_back(){
    if(index == 0) {
    SafeArrayException ex("Nothing to pop back!");
    throw ex;
    }
    if (index == totalSize / 4) halveAr();
    index--;
}
//--
template < typename T >int SafeArray<T>::size(){
     return index;
}
//--
template < typename T >T& SafeArray<T>::at(int pos){
    if (pos > index - 1 or pos < 0){
        SafeArrayException ex("Out of Bounds!");
        printf("%s\n", ex.getStr());
        throw ex;
    }
    return allVals[pos];
}
//--
template < typename T >T& SafeArray<T>::operator[](int pos){
    return at(pos);
}
//--
template < typename T >void SafeArray<T>::doubleAr(){
    totalSize *= 2;
    T* newAr = new T[totalSize];
    for (int i = 0; i < (totalSize/2); i++) newAr[i] = allVals[i];
    delete[] allVals;
    allVals = newAr; 
}
//--
template < typename T >void SafeArray<T>::halveAr(){
    totalSize /= 2;
    T* newAr = new T[totalSize];
    for (int i = 0; i < index; i++) newAr[i] = allVals[i];
    delete[] allVals;
    allVals = newAr;
}