#pragma once
#include <valarray>
#include <vector>
#include <sstream>

template <typename Ty>
class CMatrix
{
public:

	CMatrix(size_t width, size_t height)
	{
		m_matrix.resize(width);
		for (size_t i = 0; i < width; i++)
		{
			m_matrix[i] = std::valarray<Ty>( height );
		}
	}

	size_t size()
	{
		return m_matrix.size();
	}

	const size_t size() const
	{
		return m_matrix.size();
	}

	CMatrix<Ty> & T()
	{
		if (nullptr == m_T)
		{
			m_T = std::make_shared<CMatrix>(m_matrix[0].size(), m_matrix.size());
			for (size_t i = 0; i < m_matrix[0].size(); i++)
			{
				CMatrix<Ty>& tempMatrix = *m_T;
				for (size_t j = 0; j < m_matrix.size(); j++)
				{
					tempMatrix[i][j] = m_matrix[j][i];
					//std::cout << tempMatrix[i][j] << "\t";
				}
				//std::cout << std::endl;
			}
		}

		return *m_T;
	}

	std::valarray<Ty> & operator[](const unsigned int idx)
	{
		return m_matrix[idx];
	}

	const std::valarray<Ty> & operator[](const unsigned int idx) const
	{
		return m_matrix[idx];
	}

	CMatrix<Ty> operator*(const CMatrix<Ty>& cMatrix){

		if (m_matrix[0].size() != cMatrix.size())
		{
			std::ostringstream errStringStream;
			errStringStream << m_matrix[0].size() << " X " << cMatrix.size() << " Matrix Length MissMatch";
			throw std::out_of_range(errStringStream.str());
		}

		CMatrix<Ty> cDotMatrix{ m_matrix.size(), cMatrix[0].size()};
		
		for (size_t i = 0; i < m_matrix.size(); i++)
		{
			for (size_t j = 0; j < cMatrix[0].size(); j++)
			{
				Ty value = 0;
				for (size_t k = 0; k < m_matrix[0].size(); k++)
				{
					value += m_matrix[i][k] * cMatrix[k][j];
				}
				cDotMatrix[i][j] = value;
				//std::cout << cDotMatrix[i][j] << "\t";
			}
			//std::cout << std::endl;
		}
		
		//std::cout << "+++++++++++++++++++++++++++++++++++++++++" << std::endl;

		return cDotMatrix;
	}
	CMatrix<Ty> & operator*=(const CMatrix<Ty> & cMatrix) {
		*this = std::move(*this * cMatrix);
		return *this;
	}

private:
	std::valarray<std::valarray<Ty>> m_matrix;
	std::shared_ptr<CMatrix<Ty>> m_T = nullptr;
};