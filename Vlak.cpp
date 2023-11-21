#include "Vlak.h"


Vlak::Vlak(TerrainMap& m, std::string name_in, Point start_in, Point finish_in) : Path(m, name_in, start_in, finish_in)
{
}

Vlak::~Vlak()
{
}

bool Vlak::find()
{
	std::priority_queue<Point, std::vector<Point>, std::greater<Point>> to_search;
	//std::set<Point> visited;
	to_search.push(start);
	Matrix<int> visited(map.nx, map.ny);
	Matrix<Point> ways(map.nx, map.ny);
	visited.zero();
	while (true)
	{
		Point tmp = to_search.top();
		//std::cout << tmp.x << " " << tmp.y << " " << to_search.size() << std::endl;
		if (tmp == finish)
		{
			ways(start.x, start.y) = Point(0, 0);
			//std::cout << tmp.r << std::endl;
			while (ways(tmp.x, tmp.y).x != 0 && ways(tmp.x, tmp.y).y != 0)
			{
				path.push_back(tmp);
				tmp = ways(tmp.x, tmp.y);
				//std::cout << tmp.x << " " << tmp.y << std::endl;
			}
			return true;
		}
		to_search.pop();
		for (int i = -1; i < 2; i++)
		{
			for (int j = -1; j < 2; j++)
			{
				Point dir(i, j);
				Point n = tmp + dir;
				if (map.validCoords(n))
				{
					if ((i == 0 && j == 0) || map.alt(n) < 0 || std::abs(map.alt(n) - map.alt(tmp)) / dir.length() / 1000 > 0.04) { continue; } //|| map.alt(n) < 0 || std::abs(map.alt(n)- map.alt(tmp))/dir.length()/1000>0.08
					if (visited(n.x, n.y) == 0)
					{
						visited(n.x, n.y) = 1;
						n.r = tmp.r + std::abs(map.alt(n) - map.alt(tmp)) - (tmp - finish).length() + (n - finish).length();
						ways(n.x, n.y) = tmp;
						to_search.push(n);
					}
				}
			}
		}
	}

	return false;

}
