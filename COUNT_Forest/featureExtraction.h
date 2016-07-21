#pragma once

#include "patch.h"

class featureExtraction
{
public:
	featureExtraction(int s = 1, int d = 0, int dd = CV_16S, int k= 3):scale(s),delta(d),ddepth(dd),kernel_size(k){};
	Mat getFeature(patch p);
private:
	int scale;
	int delta;
	int ddepth;
	int kernel_size;
};

