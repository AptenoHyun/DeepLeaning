#pragma once
#include "matrix.hpp"
#include <random>
#include <iostream>

template<size_t width, size_t height, typename T = double>
class CNode
{
public:
	CNode()
	{
		std::random_device rd{};
		std::mt19937 gen{ rd() };

		// 1 / √개수 로 초기화 한다.
		std::normal_distribution<double> d{ 0, std::pow(m_WeightList.size(), -0.5) };

		for (unsigned int i = 0; i < m_WeightList.size(); i++)
		{
			for (unsigned int j = 0; j < m_WeightList[0].size(); j++)
			{
				m_WeightList[i][j] = d(gen);
				//std::cout << ("%d", m_WeightList[i][j]) << "\t";
			}
			std::cout << std::endl;
		}
		//std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
	}

	~CNode() {}

	CMatrix<T> && GetOutPut(CMatrix<T>& CMatrix)
	{
		return m_WeightList * CMatrix;
	}
private:
	CMatrix<T> m_WeightList{ width, height };
};