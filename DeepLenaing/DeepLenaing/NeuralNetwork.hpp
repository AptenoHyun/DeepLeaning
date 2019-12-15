#pragma once
#include "Node.hpp"
#include <vector>

class CNeuralNetwork
{
public:
	CNeuralNetwork( size_t inputSize, size_t outputSize, unsigned int nNumNode = 10, unsigned int nNumLayer = 3)
		: m_nNumNode(nNumNode), m_nNumLayer(nNumLayer)
	{
		if (nNumLayer < 3)
		{
			std::ostringstream errStringStream;
			errStringStream << nNumLayer << " < " << 3 << " Not Enough Layer ";
			throw std::out_of_range(errStringStream.str());
		}

		CNode cInNode{ inputSize, m_nNumNode };
		m_NodeVec.emplace_back(cInNode);

		for (unsigned int i = 0; i < m_nNumLayer; i++)
		{
			CNode cTempNode{ m_nNumNode, m_nNumNode };
			m_NodeVec.emplace_back(cTempNode);
		}

		CNode cOutNode{ m_nNumNode , outputSize };
		m_NodeVec.emplace_back(cOutNode);
	}

	std::valarray<double> GetOutPut(std::valarray<double> & input)
	{
		if (input.size() != m_NodeVec[0].size())
		{
			std::ostringstream errStringStream;
			errStringStream << input.size() << " != " << m_NodeVec[0].size() << " Input is Not Same ";
			throw std::out_of_range(errStringStream.str());
		}

		std::valarray<double> ret1;
		auto ret2 = input;

		for (auto it : m_NodeVec)
		{
			ret1 = it.GetOutPut(ret2);
			std::swap(ret1, ret2);
		}

		return ret1;
	}

	~CNeuralNetwork()
	{

	}
private:
	std::vector<CNode<double>> m_NodeVec;
	unsigned int m_nNumNode = 10;
	unsigned int m_nNumLayer = 3;
};