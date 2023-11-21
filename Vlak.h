#pragma once
#ifndef VLAK_H
#define VLAK_H

#include "Path.h"
#include "TerrainMap.h"
#include <queue>
#include <vector>
#include <iostream>
#include <string>
#include <set>

class Vlak : public Path
{
public:
	Vlak(TerrainMap& m, std::string name_in, Point start_in, Point finish_in);
	~Vlak();
	virtual bool find();
private:

};





#endif // !LETADLO.H