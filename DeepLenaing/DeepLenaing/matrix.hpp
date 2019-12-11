#pragma once
#include <array>
#include <vector>

template <typename T, int width, int height>
class CMatrix : std::array<std::array<T, width>, height>
{
public:
	std::error_code&& dot(std::vector<T> & vInput, std::vector<T>& vOutput)
	{
		std::error_code error_code = std::error_category::
	}
};