#pragma once

#include <iostream>

#include <figure.h>
#include <type_traits>

template<typename T>
class DynamicArray{
public:
    
    DynamicArray();
    DynamicArray(const size_t& arraySize, const T& defaultValue = T());
    DynamicArray(const std::initializer_list<T>& initialValues);
    
    DynamicArray(const DynamicArray& other);
    DynamicArray& operator=(const DynamicArray& other);
    DynamicArray(DynamicArray&& other) noexcept;
    DynamicArray& operator=(DynamicArray&& other) noexcept;

    
    void add(T element);
    DynamicArray remove(const DynamicArray& other);
    bool equals(const DynamicArray& other) const;
    void insertAt(size_t index, const T& toInsert);
    // T& getAt(size_t index);
    const T& operator[] (size_t index) const;
    T& operator[] (size_t index);
    
    std::ostream& print(std::ostream& outputStream);

    size_t getSize() const;
    T* getData() const;

    void setSize(size_t newSize);
    void setData(T* newData);

    virtual ~DynamicArray() noexcept;
    
    template<typename U = T>
    typename std::enable_if<std::is_pointer<U>::value && 
                        std::is_base_of<Figure, typename std::remove_pointer<U>::type>::value, void>::type
    DeleteFigure(size_t idx) {
        if (idx >= size) {
            throw std::out_of_range("Error index out range");
        }
        delete data[idx]; 
        for (size_t i = idx; i < size - 1; ++i) {
            data[i] = data[i + 1];
        }
        --size;
    }
    
    template<typename U = T>
    typename std::enable_if<std::is_pointer<U>::value && 
                        std::is_base_of<Figure, typename std::remove_pointer<U>::type>::value, void>::type
    PrintFigures() {
        for (size_t i = 0; i < size; ++i) {
            if (data[i] != nullptr) {
                std::cout << *data[i] << std::endl;
                std::cout << "Center: (" << data[i]->geometric_center().get_x() << ", "
                            << data[i]->geometric_center().get_y() << ")" << std::endl;
                std::cout << "Area: " << double(*data[i]) << std::endl;
            }
        }
    }

    template<typename U = T>
    typename std::enable_if<std::is_pointer<U>::value && 
                            std::is_base_of<Figure, typename std::remove_pointer<U>::type>::value, double>::type
    TotalArea() {
        double res = 0.0;
        for (size_t i = 0; i < size; ++i) {
            if (data[i] != nullptr) {
                res += double(*data[i]);
            }
        }
        return res;
    }

private:   
    size_t size;           
    T* data;   
};