#include "dynamicArray.h"
#include <algorithm>

template<typename T>
DynamicArray<T>::DynamicArray() : size(0), data(nullptr) {}

template<typename T>
DynamicArray<T>::DynamicArray(const size_t& arraySize, const T& defaultValue) {
    size = arraySize;
    data = new T[size];
    
    for (size_t i = 0; i < size; ++i) {
        data[i] = defaultValue;
    }
}

template<typename T>
DynamicArray<T>::DynamicArray(const std::initializer_list<T>& initialValues) {
    size = initialValues.size();
    data = new T[size];
    
    size_t index = 0;
    for (const auto& value : initialValues) {
        data[index++] = value;
    }
}

template<typename T>
DynamicArray<T>::DynamicArray(const DynamicArray<T>& other) {
    size = other.size;
    data = new T[size];
    
    for (size_t i = 0; i < size; ++i) {
        data[i] = other.data[i];
    }
}

template<typename T>
DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray& other){
    if (this != &other) {
        delete[] data;
        size = other.size;
        data = new T[size];
        std::copy(other.data, other.data + size, data);
    }
    return *this;
}

template<typename T>
DynamicArray<T>::DynamicArray(DynamicArray<T>&& other) noexcept {
    size = other.size;
    data = other.data;

    other.size = 0;
    other.data = nullptr;
}

template<typename T>
DynamicArray<T>& DynamicArray<T>::operator=(DynamicArray&& other) noexcept {
    if (this != &other) {
        delete[] data;
        size = other.size;
        data = other.data;
        other.size = 0;
        other.data = nullptr;
    }
    return *this;
}

template<typename T>
size_t DynamicArray<T>::getSize() const{
    return size;
}

template<typename T>
T* DynamicArray<T>::getData() const{
    return data;
}

template<typename T>
void DynamicArray<T>::setSize(size_t newSize){
    size = newSize;
}

template<typename T>
void DynamicArray<T>::setData(T* newData){
    data = newData;
}

template<typename T>
void DynamicArray<T>::add(T element) {
    T* newData = new T[size + 1];
    
    for (size_t i = 0; i < size; ++i) {
        newData[i] = data[i];
    }
    newData[size] = element;
   
    delete[] data;
    data = newData;
    ++size;
}

template<typename T>
DynamicArray<T> DynamicArray<T>::remove(const DynamicArray<T>& other) {
    if (size < other.size) {
        throw std::logic_error("Размер массива не может быть отрицательным");
    }
    
    size -= other.size;
    return *this;
}

template<typename T>
bool DynamicArray<T>::equals(const DynamicArray<T>& other) const {
    return size == other.size;
}

template<typename T>
void DynamicArray<T>::insertAt(size_t index, const T& toInsert){
    if (index < size) {
        data[index] = toInsert;
    }
}

template<typename T>
T& DynamicArray<T>::operator[](size_t index){
   return data[index]; 
}

template<typename T>
const T& DynamicArray<T>::operator[](size_t index) const {
   return data[index]; 
}

template<typename T>
std::ostream& DynamicArray<T>::print(std::ostream& outputStream) {
    for (size_t i = 0; i < size; ++i) {
        outputStream << data[i];
    }
    return outputStream;
}

template<typename T>
DynamicArray<T>::~DynamicArray() noexcept {
    delete[] data;
    size = 0;
}

// Explicit template instantiations
template class DynamicArray<Point>;
template class DynamicArray<Figure*>;