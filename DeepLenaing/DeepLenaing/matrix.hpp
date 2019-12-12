#pragma once
#include <array>
#include <vector>

template <typename T, int width, int height>
class CMatrix : std::array<std::array<T, width>, height>
{
public:
	CMatrix CMatrix::operator*(const CMatrix& cMatrix) override{
		CMatrix<decltype(this[0][0]), this->size(), cMatrix[0].size()> cDotMatrix;
		
		for (int i = 0; i < this->size(); i++)
		{
			for (int j = 0; j < cMatrix[0].size(); j++)
			{
				decltype(this[0][0]) value = 0;
				for (int k = 0; k < this[0].size(); k++)
				{
					value += this[i][k] * cMatrix[k][j];
				}
				cDotMatrix[i][j] = value;
			}
		}
		
		return cDotMatrix;
	}

	CMatrix & CMatrix::operator*=(const CMatrix& cMatrix) override {
		return (*this = *this * cMatrix);
	}
};