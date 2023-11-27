#pragma once
#ifndef LOD_H
#define LOD_H

#include "Path.h"
#include "TerrainMap.h"
#include <queue>
#include <vector>
#include <iostream>
#include <string>
#include <set>

class Lod : public Path
{
public:
	Lod(TerrainMap& m, std::string name_in, Point start_in, Point finish_in);
	~Lod();
	virtual bool find();
private:

};





#endif // !LETADLO.H
