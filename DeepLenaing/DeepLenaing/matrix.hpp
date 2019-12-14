#pragma once
#include <valarray>
#include <vector>

template <typename T>
class CMatrix
{
public:
	CMatrix(size_t width, size_t height)
	{
		m_matrix.resize(width);
		for (size_t i = 0; i < width; i++)
		{
			m_matrix[i] = std::valarray<T>( height );
		}
	}

	size_t size()
	{
		return m_matrix.size();
	}

	std::valarray<T> & operator[](const unsigned int idx)
	{
		return m_matrix[idx];
	}

	const std::valarray<T> & operator[](const unsigned int idx) const
	{
		return m_matrix[idx];
	}

	CMatrix<T> operator*(const CMatrix<T>& cMatrix){
		CMatrix<T> cDotMatrix{ m_matrix.size(), cMatrix[0].size()};
		
		for (size_t i = 0; i < m_matrix.size(); i++)
		{
			for (size_t j = 0; j < cMatrix[0].size(); j++)
			{
				T value = 0;
				for (size_t k = 0; k < m_matrix[0].size(); k++)
				{
					value += m_matrix[i][k] * cMatrix[k][j];
				}
				cDotMatrix[i][j] = value;
				//std::cout << value << "\t";
			}
			//std::cout << std::endl;
		}
		
		return cDotMatrix;
	}
	CMatrix<T> & operator*=(const CMatrix<T> & cMatrix) {
		*this = std::move(*this * cMatrix);
		return *this;
	}

private:
	std::valarray<std::valarray<T>> m_matrix;
};