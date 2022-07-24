#pragma once
#include <vector>
#include <cassert>
#include <iostream>
#include <algorithm>

typedef std::vector<std::vector<std::pair<int, int>>> vec3d;


class Test
{
public:
	Test();
	Test(int start, vec3d edges, std::vector<int> expectedOutput);
	~Test();   

	void doesItPass(std::vector<int> dijkstras);


private:
	vec3d m_edges;
	std::vector<int> m_expectedOutput;
	int m_start;

};

