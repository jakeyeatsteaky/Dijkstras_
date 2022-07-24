#include "Test.hpp"

std::vector<int> dijkstrasAlgorithm(int start, vec3d edges);

void print3Dvec(vec3d edges);

int findMinNotVisited(std::vector<int> distances, std::vector<int> visited);

const int inf = INT_MAX;


int main()
{
	//start 0 - 0.7.13.27.10.-1   
	vec3d edgesTest1 = {
		{std::pair<int, int>(1, 7)},
		{std::pair<int, int>(2, 6), std::pair<int, int>(3, 20), std::pair<int, int>(4, 3)},
		{std::pair<int, int>(3, 14)},
		{std::pair<int, int>(4, 2)},
		{},
		{}
		};

	//start 1 - -1, 0, -1, -1
	vec3d edgesTest2 = {
		{},
		{},
		{},
		{}
	};

	//start 7 - {7, 8, 9, 8, 10, 11, 10, 0}
	vec3d edgesTest3 = {
		{std::pair<int, int>(1, 1), std::pair<int, int>(3, 1)},
		{std::pair<int, int>(2, 1)},
		{std::pair<int, int>(6, 1)},
		{std::pair<int, int>(1, 3), std::pair<int, int>(2, 4), std::pair<int, int>(4, 2), std::pair<int, int>(5, 3), std::pair<int, int>(6, 5)},
		{std::pair<int, int>(5, 1)},
		{std::pair<int, int>(1, 4)},
		{std::pair<int, int>(5, 2)},
		{std::pair<int, int>(0, 7)}
	};
	 
	//start 4 - 2, 5, 4, 1, 0
	vec3d edgesTest4 = {
		{std::pair<int, int>(1, 3), std::pair<int, int>(2, 2)},
		{std::pair<int, int>(3, 7)},
		{std::pair<int, int>(1, 2), std::pair<int, int>(3, 4), std::pair<int, int>(4, 1)},
		{},
		{std::pair<int, int>(0, 2), std::pair<int, int>(1, 8), std::pair<int, int>(3, 1)}
	};

	//start 1 - 1,0,-1,-1
	vec3d edgesTest5 = {
		{std::pair<int, int>(1, 2)},
		{std::pair<int, int>(0, 1)},
		{std::pair<int, int>(3, 1)},
		{std::pair<int, int>(2, 2)}
	};

	//start 0 - 0,1,2,3,4,5,6,7
	vec3d edgesTest6 = {
	{std::pair<int, int>(1, 1), std::pair<int, int>(7, 8)},
	{std::pair<int, int>(2, 1)},
	{std::pair<int, int>(3, 1)},
	{std::pair<int, int>(4, 1)},
	{std::pair<int, int>(5, 1)},
	{std::pair<int, int>(6, 1)},
	{std::pair<int, int>(7, 1)},
		{}
	};

	//start 3 - {3,4,-1,0,4,-1,7,8,7,-1,7}
	vec3d edgesTest7 = {
		{std::pair<int, int>(1, 2), std::pair<int, int>(3, 3), std::pair<int, int>(4, 2)},
		{std::pair<int, int>(0, 1), std::pair<int, int>(6, 3)},
		{std::pair<int, int>(3, 9)},
		{std::pair<int, int>(0, 3), std::pair<int, int>(1, 4), std::pair<int, int>(4, 4), std::pair<int, int>(8, 7)},
		{std::pair<int, int>(0, 1), std::pair<int, int>(10, 3)},
		{std::pair<int, int>(7, 1), std::pair<int, int>(8, 4)},
		{std::pair<int, int>(8, 1)},
		{},
		{std::pair<int, int>(7, 1)},
		{std::pair<int, int>(10, 2)},
		{}
	};

	//start 8 - {20,16,5,15,12,12,9,10,0,17}
	vec3d edgesTest8 = {
		{std::pair<int, int>(1, 4), std::pair<int, int>(7, 11)},
		{std::pair<int, int>(0, 4), std::pair<int, int>(2, 11), std::pair<int, int>(7, 14)},
		{std::pair<int, int>(1, 11), std::pair<int, int>(3, 10), std::pair<int, int>(5, 7), std::pair<int, int>(8, 5)},
		{std::pair<int, int>(2, 10), std::pair<int, int>(4, 12), std::pair<int, int>(5, 17)},
		{std::pair<int, int>(3, 12), std::pair<int, int>(5, 13), std::pair<int, int>(6, 3)},
		{std::pair<int, int>(2, 7), std::pair<int, int>(3, 17), std::pair<int, int>(4, 13), std::pair<int, int>(6, 5)},
		{std::pair<int, int>(4, 3), std::pair<int, int>(5, 6), std::pair<int, int>(7, 4), std::pair<int, int>(9, 8)},
		{std::pair<int, int>(0, 11), std::pair<int, int>(1, 14), std::pair<int, int>(6, 4), std::pair<int, int>(8, 10)},
		{std::pair<int, int>(2, 5), std::pair<int, int>(6, 9), std::pair<int, int>(7, 10)}
	};

	//start 3 - {3,8,7, 0}
	vec3d edgesTest9 = {
		{std::pair<int, int>(2, 4)},
		{std::pair<int, int>(0, 2)},
		{std::pair<int, int>(1, 1), std::pair<int, int>(3, 2)},
		{std::pair<int, int>(0, 3)}
	};

	//Test* Test1 = new Test(0, edgesTest1, { 0,7,13,27,10,-1 });
	//Test1->doesItPass(dijkstrasAlgorithm(0, edgesTest1));

	//Test* Test2 = new Test(1, edgesTest2, { -1, 0, -1, -1 });
	//Test2->doesItPass(dijkstrasAlgorithm(1, edgesTest2));

	//Test* Test4 = new Test(4, edgesTest4, { 2, 5, 4, 1, 0 });
	//Test4->doesItPass(dijkstrasAlgorithm(4, edgesTest4));

	//Test* Test5 = new Test(1, edgesTest5, { 1, 0, -1, -1 });
	//Test5->doesItPass(dijkstrasAlgorithm(1, edgesTest5));

	//Test* Test6 = new Test(3, edgesTest6, { 0,1, 2, 3, 4, 5, 6, 7 });
	//Test6->doesItPass(dijkstrasAlgorithm(0, edgesTest6));

	std::vector<int> test3Resutls = dijkstrasAlgorithm(7, edgesTest3);

	//something with the findMinNotVisited function.  The second time around, the check for whether or not a node is contained in distances is incorrect

	for (int nums : test3Resutls)
	{
		std::cout << nums << std::endl;
	}
}

void print3Dvec(vec3d edges)
{
	int counter = 0;
		for (std::vector<std::pair<int, int>> pairVecs : edges)
		{
			std::cout << "Node " << counter << ": ";

			if (pairVecs.size() == 0)
			{
				std::cout << "[ : ]\n";
				counter++;
				continue;
			}

			for (int i = 0; i < pairVecs.size(); i++)
			{
				std::cout << "[" << pairVecs[i].first << ": " << pairVecs[i].second << "] ";
			}
				std::cout << "\n";

				counter++;
		}
}

int findMinNotVisited(std::vector<int> distances, std::vector<int> visited)
{
	int idxOfShortestDistance = inf;

	for (int i = 0; i < distances.size(); i++)
	{
		if (distances[i] < idxOfShortestDistance)
		{
			std::vector<int>::iterator it = std::find(visited.begin(), visited.end(), distances[i]);
			if (it != visited.end() )
			{
				continue;
			}
			else
			{
				idxOfShortestDistance = i;
			}
				
		}

			
	}
	return idxOfShortestDistance;
}

std::vector<int> dijkstrasAlgorithm(int start, vec3d edges)
{
	std::vector<int> distances(edges.size(), inf); distances[start]=0;
	std::vector<int> visited{};

	while (visited.size() < edges.size())
	{
		// check to see what is the shortest number in distances that has not yet been visited
		int nextNode = findMinNotVisited(distances, visited);

		// look at all outgoing edges from that node (nextNode)
		for (std::pair<int, int> destsAndWeights : edges[nextNode])
		{
			// we need to add the weight from the start node to the current node

			if (destsAndWeights.second < distances[destsAndWeights.first])
			{
				distances[destsAndWeights.first] = destsAndWeights.second + distances[nextNode];
			}
			else
				continue;
		}

		// add nextNode to visited
		visited.push_back(nextNode);
	}

	for (int i = 0; i < distances.size(); i++)
	{
		if (distances[i] == inf)
			distances[i] = -1;
	}
	

	return distances;
}
	


// solution in AlgoExpert IDE
//#include <vector>
//#include <algorithm>
//const int inf = INT_MAX;
//using namespace std;
//int findMinNotVisited(std::vector<int> distances, std::vector<int> visited)
//{
//	int idxOfShortestDistance = inf;
//
//	for (int i = 0; i < distances.size(); i++)
//	{
//		if (distances[i] < idxOfShortestDistance)
//		{
//			std::vector<int>::iterator it = std::find(visited.begin(), visited.end(), distances[i]);
//			if (it != visited.end())
//			{
//				continue;
//			}
//			else
//			{
//				idxOfShortestDistance = i;
//			}
//
// 
//		}
//
//	}
//	return idxOfShortestDistance;
//}
//
//vector<int> dijkstrasAlgorithm(int start, vector<vector<vector<int>>> edges) {
//	std::vector<int> distances(edges.size(), inf); distances[start] = 0;
//	std::vector<int> visited{};
//
//	while (visited.size() < edges.size())
//	{
//		// check to see what is the shortest number in distances that has not yet been visited
//		int nextNode = findMinNotVisited(distances, visited);
//
//		// look at all outgoing edges from that node (nextNode)
//		for (int i = 0; i < edges[nextNode].size(); i++)
//		{
//			// we need to add the weight from the start node to the current node
//			if (edges[nextNode][i][1] < distances[edges[nextNode][i][0]])
//			{
//				distances[edges[nextNode][i][0]] = edges[nextNode][i][1] + distances[nextNode];
//			}
//			else
//				continue;
//		}
//
//		// add nextNode to visited
//		visited.push_back(nextNode);
//	}
//
//	for (int i = 0; i < distances.size(); i++)
//	{
//		if (distances[i] == inf)
//			distances[i] = -1;
//	}
//
//
//	return distances;
//}