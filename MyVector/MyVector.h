#pragma once
template <typename T>
class MyVector
{
	T* value_{};
	size_t quantityElements_{};

	bool isCorectPosition(size_t const pos);
public:
	//////Member functions//////
	MyVector();
	MyVector(size_t const size);
	MyVector(const MyVector<T>& temp);
	MyVector(MyVector<T>&& temp);
	~MyVector();

	MyVector<T>& operator= (const MyVector& temp);
	MyVector<T>& operator= (MyVector&& temp);

	void assign(size_t const newSize, const T& value);

	//////Element access//////
	T& at(size_t const pos);
};

template<typename T>
inline bool MyVector<T>::isCorectPosition(size_t const pos)
{
	if(pos>=quantityElements_)
		return false;
	return true;
}

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

template<typename T>
inline MyVector<T>::MyVector(const MyVector<T>& temp)
{
	quantityElements_ = temp.quantityElements_;
	value_ = new T[quantityElements_];
	for (size_t i{}; i < quantityElements_; ++i)
		value_[i] = temp.value_[i];
}

template<typename T>
inline MyVector<T>::MyVector(MyVector<T>&& temp)
{
	quantityElements_ = temp.quantityElements_;
	value_ = temp.value_;
	temp.quantityElements_ = 0;
}

template<typename T>
inline MyVector<T>::~MyVector()
{
	quantityElements_ = 0;
	delete[] value_;
	value_ = nullptr;
}

template<typename T>
inline MyVector<T>& MyVector<T>::operator=(const MyVector& temp)
{
	quantityElements_ = temp.quantityElements_;
	value_ = new T[quantityElements_];
	for (size_t i{}; i < quantityElements_; ++i)
		value_[i] = temp.value_[i];
	return *this;
}

template<typename T>
inline MyVector<T>& MyVector<T>::operator=(MyVector&& temp)
{
	quantityElements_ = temp.quantityElements_;
	temp.quantityElements_ = 0;
	value_ = temp.value_;
	return *this;
}

template<typename T>
inline void MyVector<T>::assign(size_t const newSize, const T& value)
{
	delete[] value_;
	value_ = nullptr;
	quantityElements_ = newSize;
	value_ = new T[newSize]{ value };
}

template<typename T>
inline T& MyVector<T>::at(size_t const pos)
{
	if (isCorectPosition(pos))
		return value_[pos];
	else
		throw "Out of range";
	// TODO: insert return statement here
}
