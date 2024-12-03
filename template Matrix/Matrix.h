#pragma once
#include "Vector.h"

//template <class T>
//class Matrix : public Vector<Vector<T>> {
//public:
//	Matrix(size_t size) : Vector<Vector <T>>(size) {
//		for (int i = 0; i != size; i++) this->elem[i] = Vector<T>(size - i, i);
//	}
//	Matrix(const Vector<Vector<T>>& mt) : Vector<Vector<T>>(mt){}
//	Matrix(const Matrix<T>& mt) : Vector<Vector <T>>(mt) {}
//	bool operator == (const Matrix<T>& mt) const {
//		return Vector<Vector<T>>::operator==(mt);
//	}
//	friend istream& operator >>(istream& in, Matrix& mt) {
//		for (int i = 0; i < mt._size; i++) in >> mt.elem[i];
//		return in;
//	}
//	friend ostream& operator <<(ostream& out, const Matrix& mt) {
//		for (int i = 0; i < mt._size; i++) 
//			out << mt.elem[i] << endl;
//		return out;
//	}
//	Matrix<T>& operator=(const Matrix<T>& mt)
//	{
//		return Vector<Vector<T>>::operator=(mt);
//	}
//	Matrix<T> operator + (const Matrix<T>& mt) {
//		return Vector<Vector<T>>::operator +(mt);
//	}
//	Matrix<T> operator - (const Matrix<T>& mt) {
//		return Vector<Vector<T>>::operator -(mt);
//	}
//	Matrix<T> operator *(const Matrix<T>& mt) {
//		if (this->_size != mt._size) throw "Not equal sizes";
//		if (this->StartIndex != mt.StartIndex) throw "Not equal index";
//		Matrix<T> res(this->_size);
//		return res;
//	}
//};
// ����������������� �������
template <class ValType>
class TMatrix : public TVector<TVector<ValType>>
{
public:
    TMatrix(size_t s = 10);
    TMatrix(const TMatrix& mt);                    // �����������
    TMatrix(const TVector<TVector<ValType> >& mt); // �������������� ����
    bool operator==(const TMatrix& mt) const;      // ���������
    bool operator!=(const TMatrix& mt) const;      // ���������
    const TMatrix& operator= (const TMatrix& mt);        // ������������
    TMatrix  operator+ (const TMatrix& mt);        // ��������
    TMatrix  operator- (const TMatrix& mt);        // ���������
    TMatrix  operator* (const TMatrix& mt);        // ���������
    // ���� / �����
    friend istream& operator>>(istream& in, TMatrix& mt)
    {
        for (int i = 0; i < mt.Size; i++)
            in >> mt.pVector[i];
        return in;
    }
    friend ostream& operator<<(ostream& out, const TMatrix& mt)
    {
        for (int i = 0; i < mt.Size; i++)
            out << mt.pVector[i] << endl;
        return out;
    }
};

template <class ValType>
TMatrix<ValType>::TMatrix(size_t s) : TVector<TVector<ValType> >(s)
{
    for (int i = 0; i < s; i++) {
        this->pVector[i] = TVector<ValType>(s - i, i);
    }
} /*-------------------------------------------------------------------------*/

template <class ValType> // ����������� �����������
TMatrix<ValType>::TMatrix(const TMatrix<ValType>& mt) :
    TVector<TVector<ValType> >(mt) {}

template <class ValType> // ����������� �������������� ����
TMatrix<ValType>::TMatrix(const TVector<TVector<ValType> >& mt) :
    TVector<TVector<ValType> >(mt) {}

template <class ValType> // ���������
bool TMatrix<ValType>::operator==(const TMatrix<ValType>& mt) const
{
    return TVector<TVector<ValType>>::operator==(mt);
} /*-------------------------------------------------------------------------*/

template <class ValType> // ���������
bool TMatrix<ValType>::operator!=(const TMatrix<ValType>& mt) const
{
    return !(*this == mt);
} /*-------------------------------------------------------------------------*/

template <class ValType> // ������������
const TMatrix<ValType>& TMatrix<ValType>::operator=(const TMatrix<ValType>& mt)
{
    return TVector <TVector<ValType>>::operator=(mt);
} /*-------------------------------------------------------------------------*/

template <class ValType> // ��������
TMatrix<ValType> TMatrix<ValType>::operator+(const TMatrix<ValType>& mt)
{
    if (this->Size != mt.Size) throw "Sizes isnt equal";
    return TVector<TVector<ValType>>::operator+(mt);
} /*-------------------------------------------------------------------------*/

template <class ValType> // ���������
TMatrix<ValType> TMatrix<ValType>::operator-(const TMatrix<ValType>& mt)
{
    if (this->Size != mt.Size) throw "Sizes isnt equal";
    return TVector<TVector<ValType>>::operator-(mt);
} /*-------------------------------------------------------------------------*/
template <class ValType> // ���������
TMatrix<ValType> TMatrix<ValType>::operator*(const TMatrix& mt)
{

    if (this->Size != mt.Size) throw "Not equal sizes";
    if (this->StartIndex != mt.StartIndex) throw "Not equal index";
    TMatrix<ValType> tmp(mt), res(this->Size);
    for (int i = 0; i < this->Size; i++)
    {
        for (int j = i; j < this->Size; j++)
        {
            for (int k = i; k <= j; k++)
            {
                res[i][j] += (*this)[i][k] * tmp[k][j];
            }
        }

    }
    return res;
}


