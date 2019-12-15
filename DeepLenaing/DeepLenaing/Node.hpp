#pragma once
#include "matrix.hpp"
#include <random>
#include <iostream>
#include <cmath>

template<typename Ty = double>
class CNode
{
public:
	CNode(size_t width, size_t height)
	{
		std::random_device rd{};
		std::mt19937 gen{ rd() };

		m_WeightList = std::make_shared<CMatrix<Ty>>( width , height );

		// 1 / √개수 로 초기화 한다.
		std::normal_distribution<double> d{ 0, std::pow(m_WeightList->size(), -0.5) };

		for (unsigned int i = 0; i < m_WeightList->size(); i++)
		{
			for (unsigned int j = 0; j < (*m_WeightList)[0].size(); j++)
			{
				(*m_WeightList)[i][j] = d(gen);
				//std::cout << ("%d", m_WeightList[i][j]) << "\t";
			}
			//std::cout << std::endl;
		}
		//std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
	}

	~CNode() {}

	CMatrix<Ty> && GetOutPut(CMatrix<Ty>& CMatrix)
	{
		return (*m_WeightList) * CMatrix;
	}
private:
	std::shared_ptr<CMatrix<Ty>> m_WeightList = nullptr;
	double Activate(const double & dOutPut){
		double dRet = 1 / (1 + exp(-dOutPut));
		return dRet;
	};
};