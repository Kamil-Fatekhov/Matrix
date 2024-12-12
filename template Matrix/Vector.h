#pragma once
#include <iostream>

using namespace std;


//template <class T>
//class Vector {
//protected:
//	T* elem;
//	size_t _size;
//	size_t StartIndex;
//public:
//	 Vector(size_t size = 5, size_t Ind = 0) : _size(size), elem(new T[size]),StartIndex(Ind) {
//		 for (int i = 0; i != _size; i++) elem[i] = T();
//	}
//	~Vector() {
//		delete[] elem;
//	}
//	Vector(Vector& const tmp) : Vector{ tmp._size, tmp.StartIndex } {
//		for (int i = 0; i != tmp.GetSize(); i++) elem[i] = tmp.elem[i];
//	}
//	size_t GetSize() const {
//		return _size;
//	}
//	size_t GetStartIndex() const {
//		return StartIndex;
//	}
//	Vector(Vector&& moved) {
//		_size = moved._size;
//		elem = new T[_size];
//		for (int i = 0; i != moved.GetSize(); i++) elem[i] = moved.elem[i];
//		moved.elem = nullptr;
//		moved._size = 0;
//		moved.StartIndex = 0;
//	}
//	size_t Size() const {
//		return StartIndex;
//	}
//	T& operator [](size_t index) {
//		if (index > _size + StartIndex || index < StartIndex) throw "incorrect index";
//		return elem[index - StartIndex];
//	}
//	T GetElem(size_t index) {
//		if (index > _size) throw "Out of range";
//		return elem[index];
//	}
//	Vector& operator = (const Vector& tmp)  {
//		if (*this == tmp) return *this;
//		delete[] elem;
//		_size = tmp._size;
//		elem = new T[_size];
//		for (int i = 0; i != _size; i++) elem[i] = tmp.elem[i];
//		StartIndex = tmp.StartIndex;
//		return *this;
//	}
//	bool operator ==(const Vector& tmp) const {
//		if (_size != tmp._size && StartIndex != tmp.StartIndex) return false;
//		for (int i = 0; i != _size; i++) {
//			if (elem[i] != tmp.elem[i]) return false;
//		}
//		return true;
//	}
//	bool operator!=(const Vector& tmp) const {
//		return !(*this == tmp);
//	}
//	Vector<T> operator +(const Vector& tmp) {
//		if (_size != tmp._size) throw "vectors of different sizes";
//		if (StartIndex != tmp.StartIndex) throw "vectors of different start indexes";
//		Vector res(_size, StartIndex);
//		for (int i = 0; i != _size; i++) res.elem[i] = elem[i] + tmp.elem[i];
//		return res;
//	}
//	Vector<T> operator -(const Vector& tmp) {
//		if (_size != tmp._size) throw "vectors of different sizes";
//		if (StartIndex != tmp.StartIndex) throw "vectors of different start indexes";
//		Vector res(_size, StartIndex);
//		for (int i = 0; i != _size; i++) res.elem[i] = elem[i] - tmp.elem[i];
//		return res;
//	}
//	Vector<T> operator +(const T& tmp) {
//		Vector res(*this);
//		for (int i = 0; i != res._size; i++) res.elem[i] += tmp;
//		return res;
//	}
//	Vector<T> operator -(const T& tmp) {
//		Vector res(*this);
//		for (int i = 0; i != res._size; i++) res.elem[i] -= tmp;
//		return res;
//	}
//	Vector<T> operator *(const T& tmp) {
//		Vector res(*this);
//		for (int i = 0; i != res._size; i++) res.elem[i] *= tmp;
//		return res;
//	}
//	T operator *(const Vector& tmp) {
//		if (_size != tmp._size) throw "vectors of different sizes";
//		if (StartIndex != tmp.StartIndex) throw "vectors of different start indexes";
//		T res = T();
//		for (int i = 0; i != _size; i++) res += elem[i] * tmp.elem[i];
//		return res;
//	}
//	friend istream& operator >>(istream& in, Vector& v) {
//		for (int i = 0; i != v._size; i++) in >> v.elem[i];
//		return in;
//	}
//	friend ostream& operator <<(ostream& os, const Vector& v) {
//		for (int i = 0; i != v._size; i++) os << v.elem[i] << ' ';
//		return os;
//	}
//};

// Шаблон вектора
template <class ValType>
class TVector
{
protected:
    ValType* pVector;
    size_t Size;       // размер вектора
    size_t StartIndex; // индекс первого элемента вектора
public:
    TVector(size_t s = 10, size_t si = 0);
    TVector(const TVector& v);                // конструктор копирования
    TVector(TVector&& moved);
    ~TVector();
    const size_t GetSize() { return Size; } // размер вектора
    size_t GetStartIndex() { return StartIndex; } // индекс первого элемента
    ValType& operator[](const size_t index);
    //ValType& operator[](int pos) const;  // доступ
    bool operator==(const TVector& v) const;  // сравнение
    bool operator!=(const TVector& v) const;  // сравнение
    TVector& operator=(const TVector& v);     // присваивание

    // скалярные операции
    TVector  operator+(const ValType& val);   // прибавить скаляр
    TVector  operator-(const ValType& val);   // вычесть скаляр
    TVector  operator*(const ValType& val);   // умножить на скаляр

    // векторные операции
    TVector  operator+(const TVector& v);     // сложение
    TVector  operator-(const TVector& v);     // вычитание
    ValType  operator*(const TVector& v);     // скалярное произведение

    // ввод-вывод
    friend istream& operator>>(istream& in, TVector& v)
    {
        for (int i = 0; i < v.Size; i++)
            in >> v.pVector[i];
        return in;
    }
    friend ostream& operator<<(ostream& out, const TVector& v)
    {
        for (int i = 0; i < v.Size; i++)
            out << v.pVector[i] << ' ';
        return out;
    }
};

template <class ValType>
TVector<ValType>::TVector(size_t s , size_t si) : Size(s), StartIndex(si), pVector(new ValType[s])
{
    for (int i = 0; i != Size; i++) pVector[i] = ValType();
} /*-------------------------------------------------------------------------*/

template <class ValType> //конструктор копирования
TVector<ValType>::TVector(const TVector& v): TVector { v.Size, v.StartIndex } {
   for (int i = 0; i != v.Size; i++) pVector[i] = v.pVector[i];
} /*-------------------------------------------------------------------------*/
template <class ValType>
TVector<ValType>::TVector(TVector&& moved) {
    Size = moved.Size;
    pVector = new ValType[Size];
    for (int i = 0; i != moved.GetSize(); i++) pVector[i] = moved.pVector[i];
    StartIndex = moved.StartIndex;
    moved.pVector = nullptr;
    moved.Size = 0;
    moved.StartIndex = 0;
}
template <class ValType>
TVector<ValType>::~TVector()
{
    delete[] pVector;
} /*-------------------------------------------------------------------------*/

template <class ValType> // доступ
ValType& TVector<ValType>::operator[](const size_t index)
{
    if (index > Size + StartIndex || index < StartIndex) throw "incorrect index";
    return pVector[index - StartIndex];
} /*-------------------------------------------------------------------------*/

//template <class ValType> // доступ
//ValType& TVector<ValType>::operator[](int pos) const
//{
//    return pVector[pos];
//}/*-------------------------------------------------------------------------*/
template <class ValType> // сравнение
bool TVector<ValType>::operator==(const TVector<ValType>& v) const
{
    if (Size != v.Size && StartIndex != v.StartIndex) return false;
    for (int i = 0; i != Size; i++) 
    if (pVector[i] != v.pVector[i]) return false;                                   
    return true;
} /*-------------------------------------------------------------------------*/

template <class ValType> // сравнение
bool TVector<ValType>::operator!=(const TVector& v) const
{
    return !(*this == v);
} /*-------------------------------------------------------------------------*/

template <class ValType> // присваивание
TVector<ValType>& TVector<ValType>::operator=(const TVector& v)
{
    if (*this == v) return *this;
    delete[] pVector;
    Size = v.Size;
    pVector = new ValType[Size];
    StartIndex = v.StartIndex;
    for (int i = 0; i < Size; i++) {
        pVector[i] = v.pVector[i];
    }
    return *this;
} /*-------------------------------------------------------------------------*/

template <class ValType> // прибавить скаляр
TVector<ValType> TVector<ValType>::operator+(const ValType& val)
{
    TVector<ValType> res(*this);
    for (int i = 0; i < Size; i++) res.pVector[i] += val;
    return res;
} /*-------------------------------------------------------------------------*/

template <class ValType> // вычесть скаляр
TVector<ValType> TVector<ValType>::operator-(const ValType& val)
{
    TVector<ValType> res(*this);
    for (int i = 0; i < Size; i++) res.pVector[i] -= val;
    return res;
} /*-------------------------------------------------------------------------*/

template <class ValType> // умножить на скаляр
TVector<ValType> TVector<ValType>::operator*(const ValType& val)
{
    TVector<ValType> res(*this);
    for (int i = 0; i < Size; i++) res.pVector[i] *= val;
    return res;
} /*-------------------------------------------------------------------------*/

template <class ValType> // сложение
TVector<ValType> TVector<ValType>::operator+(const TVector<ValType>& v)
{
    if (Size != v.Size) throw "vectors of different sizes";
    if (StartIndex != v.StartIndex) throw "vectors of different start indexes";
    TVector res(Size, StartIndex);
    for (int i = 0; i != Size; i++) res.pVector[i] = pVector[i] + v.pVector[i];
    return res;
} /*-------------------------------------------------------------------------*/

template <class ValType> // вычитание
TVector<ValType> TVector<ValType>::operator-(const TVector<ValType>& v)
{
    if (Size != v.Size) throw "Vector sizes have to be equal";
    if (StartIndex != v.StartIndex) throw "Vector start indexes have to be equal";
    TVector<ValType> tmp(Size, StartIndex);
    for (int i = 0; i < Size; i++) tmp.pVector[i] = pVector[i] - v.pVector[i];
    return tmp;
} /*-------------------------------------------------------------------------*/

template <class ValType> // скалярное произведение
ValType TVector<ValType>::operator*(const TVector<ValType>& v)
{
    if (Size != v.Size) throw "Vector sizes have to be equal";
    if (StartIndex != v.StartIndex) throw "Vector start indexes have to be equal";
    ValType tmp = ValType();
    for (int i = 0; i < Size; i++) {
        tmp += pVector[i] * v.pVector[i];
    }
    return tmp;
} /*-------------------------------------------------------------------------*/