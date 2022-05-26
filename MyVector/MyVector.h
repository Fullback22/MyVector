#pragma once
template <typename T>
class MyVector
{
	T* value_{};
	size_t quantityElements_{};
public:
	MyVector();
	MyVector(size_t const size);
};

template<typename T>
inline MyVector<T>::MyVector()
{
}

template<typename T>
inline MyVector<T>::MyVector(size_t const size)
{
	value_ = new T[size]{};
	quantityElements_ = size;
}
