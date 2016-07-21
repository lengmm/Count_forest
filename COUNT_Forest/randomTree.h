#pragma once

#include <vector>
#include <utility>
#include "patch.h"

using std::vector;
using std::pair;

class randomTree
{
public:
	randomTree();
	~randomTree();
	void buildTree(vector<pair<patch, vector<pair<int, int> > > >  samples);
	vector<pair<int, int>> predict(patch p);
};

