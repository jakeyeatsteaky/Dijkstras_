#include "Test.hpp"


Test::Test() : 
	m_start(0),
	m_edges(vec3d({{std::pair<int,int>(0,0)}})),
	m_expectedOutput({0})
{
	
}

Test::Test(int start, vec3d edges, std::vector<int> expectedOutput) :
	m_start(start),
	m_edges(edges),
	m_expectedOutput(expectedOutput)
{

}

Test::~Test()
{

}

void Test::doesItPass(std::vector<int> dijkstras)
{
	for (int i = 0; i < dijkstras.size(); i++)
	{
		assert(dijkstras[i] == this->m_expectedOutput[i]);
	}

	std::cout << "Pass\n";
}

