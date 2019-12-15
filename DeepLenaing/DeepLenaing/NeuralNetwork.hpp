#pragma once
#include "Node.hpp"
#include <vector>

class CNeuralNetwork
{
public:
	CNeuralNetwork( size_t input, size_t output, unsigned int nNumNode = 10, unsigned int nNumLayer = 3)
		: m_nNumNode(nNumNode), m_nNumLayer(nNumLayer)
	{
		if (nNumLayer < 3)
		{
			throw std::out_of_range("Not Enough Layer");
		}

		CNode cInNode{ input, m_nNumNode };
		m_NodeVec.emplace_back(cInNode);

		for (unsigned int i = 0; i < m_nNumLayer; i++)
		{
			CNode cTempNode{ m_nNumNode, m_nNumNode };
			m_NodeVec.emplace_back(cTempNode);
		}

		CNode cOutNode{ m_nNumNode , output };
		m_NodeVec.emplace_back(cOutNode);
	}
	~CNeuralNetwork()
	{

	}
private:
	std::vector<CNode<double>> m_NodeVec;
	unsigned int m_nNumNode = 10;
	unsigned int m_nNumLayer = 3;
};