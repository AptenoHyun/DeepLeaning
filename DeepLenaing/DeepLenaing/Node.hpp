#pragma once
#include "matrix.hpp"
#include <random>
#include <iostream>

template <typename T, int width, int height>
using matrix = std::array<std::array<T, width>, height>;

template <int width, int height>
class CNode
{
public:
	CNode()
	{
		// 1 / √개수 로 초기화 한다.
		std::normal_distribution<> d{ 0, std::pow(m_WeightList.size(), -0.5) };

		std::random_device rd{};
		std::mt19937 gen{ rd() };

		for (unsigned int i = 0; i < m_WeightList.size(); i++)
		{
			for (unsigned int j = 0; j < m_WeightList[0].size(); j++)
			{
				m_WeightList[i][j] = d(gen);
				std::cout << ("%d", m_WeightList[i][j]) << std::endl;

			}
		}
	}

	~CNode() {}

private:
	matrix<double, width, height> m_WeightList;
};