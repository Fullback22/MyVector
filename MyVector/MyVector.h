#pragma once
template <typename T>
class MyVector
{
	T* value_{};
	size_t quantityElements_{};

	bool isCorectPosition(size_t const pos) const;
public:
	//////Member functions//////
	MyVector();
	MyVector(size_t const size);
	MyVector(size_t const size, const T& value);
	MyVector(const MyVector<T>& temp);
	MyVector(MyVector<T>&& temp);
	~MyVector();

	MyVector<T>& operator= (const MyVector& temp);
	MyVector<T>& operator= (MyVector&& temp);

	void assign(size_t const newSize, const T& value);

	//////Element access//////
	T& at(size_t const pos);
	T& operator[](size_t const pos);
	const T& operator[](size_t const pos) const;
	T& front();
	const T& front() const;
	T& back();
	const T& back() const;
	T* data();

	//////Capacity//////
	bool empty() const;
	size_t size() const;

	//////Modifiers//////
	void clear();
	void insert(size_t const pos, const T& value);
	void insert(size_t const pos, size_t const numberRepetitions, const T& value);
	void erase(size_t const pos);
	void pushBack(const T& value);
	void popBack();
	void resize(size_t const newSize);
	void resize(size_t const newSize, const T& value);
};

template<typename T>
inline bool MyVector<T>::isCorectPosition(size_t const pos) const
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
inline MyVector<T>::MyVector(size_t const size, const T& value)
{
	quantityElements_ = size;
	value_ = new T[quantityElements_];
	for (size_t i{}; i < quantityElements_; ++i)
		value_[i] = value;
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
	clear();
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
	value_ = new T[newSize];
	for (size_t i{}; i < quantityElements_; ++i)
		value_[i] = value;
}

template<typename T>
inline T& MyVector<T>::at(size_t const pos)
{
	if (isCorectPosition(pos))
		return value_[pos];
	throw "Out of range";
}

template<typename T>
inline T& MyVector<T>::operator[](size_t const pos)
{
	if (isCorectPosition(pos))
		return value_[pos];
	throw "Out of range";
}

template<typename T>
inline const T& MyVector<T>::operator[](size_t const pos) const
{
	if (isCorectPosition(pos))
		return value_[pos];
	throw "Out of range";
}

template<typename T>
inline T& MyVector<T>::front()
{
	if (empty())
		throw "out of range";
	return value_[0];
}

template<typename T>
inline const T& MyVector<T>::front() const
{
	if (empty())
		throw "out of range";
	return value_[0];
}

template<typename T>
inline T& MyVector<T>::back()
{
	if (empty())
		throw "out of range";
	return value_[quantityElements_ - 1];
}

template<typename T>
inline const T& MyVector<T>::back() const
{
	if (empty())
		throw "out of range";
	return value_[quantityElements_ - 1];
}

template<typename T>
inline T* MyVector<T>::data()
{
	return value_;
}

template<typename T>
inline bool MyVector<T>::empty() const
{
	if(quantityElements_>0)
		return false;
	return true;
}

template<typename T>
inline size_t MyVector<T>::size() const
{
	return quantityElements_;
}

template<typename T>
inline void MyVector<T>::clear()
{
	if (quantityElements_ > 0)
	{
		delete[] value_;
		value_ = nullptr;
		quantityElements_ = 0;
	}
}

template<typename T>
inline void MyVector<T>::insert(size_t const pos, const T& value)
{
	if (isCorectPosition(pos))
	{
		T* buferValue{ new T[quantityElements_] };
		for (size_t i{}; i < quantityElements_; ++i)
		{
			buferValue[i] = value_[i];
		}
		delete[] value_;
		++quantityElements_;
		value_ = new T[quantityElements_];
		for (size_t i{}; i < pos; ++i)
		{
			value_[i] = buferValue[i];
		}
		value_[pos] = value;
		for (size_t i{ pos + 1 }; i < quantityElements_; ++i)
		{
			value_[i] = buferValue[i - 1];
		}
		delete[] buferValue;
		buferValue = nullptr;
	}
	else
		throw "out of range";
}

template<typename T>
inline void MyVector<T>::insert(size_t const pos, size_t const numberRepetitions, const T& value)
{
	if (isCorectPosition(pos))
	{
		T* buferValue{ new T[quantityElements_] };
		for (size_t i{}; i < quantityElements_; ++i)
		{
			buferValue[i] = value_[i];
		}
		delete[] value_;
		quantityElements_+= numberRepetitions;
		value_ = new T[quantityElements_];
		for (size_t i{}; i < pos; ++i)
		{
			value_[i] = buferValue[i];
		}
		for (size_t i{}; i < numberRepetitions; ++i)
		{
			value_[pos + i] = value;
		}
		
		for (size_t i{ pos + numberRepetitions }; i < quantityElements_; ++i)
		{
			value_[i] = buferValue[i - numberRepetitions];
		}
		delete[] buferValue;
		buferValue = nullptr;
	}
	else
		throw "out of range";
}

template<typename T>
inline void MyVector<T>::erase(size_t const pos)
{
	if (isCorectPosition(pos))
	{
		size_t sizeBufer{ quantityElements_ - 1 };
		T* buferValue{ new T[sizeBufer] };
		for (size_t i{}; i < pos; ++i)
		{
			buferValue[i] = value_[i];
		}
		for (size_t i{ pos }; i < quantityElements_; ++i)
		{
			buferValue[i] = value_[i + 1];
		}
		delete[] value_;
		quantityElements_ = sizeBufer;
		value_ = new T[quantityElements_];
		for (size_t i{}; i < quantityElements_; ++i)
		{
			value_[i] = buferValue[i];
		}
		delete[] buferValue;
		buferValue = nullptr;
	}
	else
		throw "out of range";
}

template<typename T>
inline void MyVector<T>::pushBack(const T& value)
{
	T* buferValue{ new T[quantityElements_] };
	for (size_t i{}; i < quantityElements_; ++i)
	{
		buferValue[i] = value_[i];
	}
	delete[] value_;
	value_ = new T[quantityElements_ + 1];
	for (size_t i{}; i < quantityElements_; ++i)
	{
		value_[i] = buferValue[i];
	}
	value_[quantityElements_] = value;
	++quantityElements_;
	delete[] buferValue;
	buferValue = nullptr;
}

template<typename T>
inline void MyVector<T>::popBack()
{
	if (quantityElements_ > 0)
	{
		--quantityElements_;
		T* buferValue{ new T[quantityElements_] };
		for (size_t i{}; i < quantityElements_; ++i)
		{
			buferValue[i] = value_[i];
		}
		delete[] value_;
		value_ = new T[quantityElements_];
		for (size_t i{}; i < quantityElements_; ++i)
		{
			value_[i] = buferValue[i];
		}
		delete[] buferValue;
		buferValue = nullptr;
	}
}

template<typename T>
inline void MyVector<T>::resize(size_t const newSize)
{
	if (quantityElements_ > newSize)
	{
		quantityElements_ = newSize;
		T* buferValue{ new T[quantityElements_] };
		for (size_t i{}; i < quantityElements_; ++i)
		{
			buferValue[i] = value_[i];
		}
		delete[] value_;
		value_ = new T[quantityElements_];
		for (size_t i{}; i < quantityElements_; ++i)
		{
			value_[i] = buferValue[i];
		}
		delete[] buferValue;
		buferValue = nullptr;
	}
	else if (quantityElements_ < newSize)
	{
		T* buferValue{ new T[quantityElements_] };
		for (size_t i{}; i < quantityElements_; ++i)
		{
			buferValue[i] = value_[i];
		}
		delete[] value_;
		value_ = new T[newSize]{};
		for (size_t i{}; i < quantityElements_; ++i)
		{
			value_[i] = buferValue[i];
		}
		delete[] buferValue;
		buferValue = nullptr;
		quantityElements_ = newSize;
	}
}

template<typename T>
inline void MyVector<T>::resize(size_t const newSize, const T& value)
{
	if (quantityElements_ > newSize)
	{
		quantityElements_ = newSize;
		T* buferValue{ new T[quantityElements_] };
		for (size_t i{}; i < quantityElements_; ++i)
		{
			buferValue[i] = value_[i];
		}
		delete[] value_;
		value_ = new T[quantityElements_];
		for (size_t i{}; i < quantityElements_; ++i)
		{
			value_[i] = buferValue[i];
		}
		delete[] buferValue;
		buferValue = nullptr;
	}
	else if (quantityElements_ < newSize)
	{
		T* buferValue{ new T[quantityElements_] };
		for (size_t i{}; i < quantityElements_; ++i)
		{
			buferValue[i] = value_[i];
		}
		delete[] value_;
		value_ = new T[newSize];
		for (size_t i{}; i < quantityElements_; ++i)
		{
			value_[i] = buferValue[i];
		}
		for (size_t i{ quantityElements_ }; i < newSize; ++i)
		{
			value_[i] = value;
		}
		delete[] buferValue;
		buferValue = nullptr;
		quantityElements_ = newSize;
	}
}


