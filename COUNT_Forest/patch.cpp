#include "patch.h"
#include <utility>
#include "featureExtraction.h"
using std::pair;
using std::make_pair;
using namespace cv;
#include <iostream>
using std::cout;
using std::endl;

//将图像划分成块，并将块的特征计算出来
void splice2patchF(string img, vector<Mat>& patches){
	featureExtraction fg;
	Mat originalImg = imread(img);
	for (int r = 0; r < originalImg.rows/13; r++)  //每个238*158的图像产生[238/13]*[158/13]=936个patch
	{
		for (int c = 0; c < originalImg.cols/13; c++)
		{
			patch p;
			Rect region(r * 13, c * 13, 13, 13);
			p.patchData(region);
			Mat feature = fg.getFeature(p);
			patches.push_back(feature);
		}
	}
}

//将图像划分成块，并将块的特征计算出来，和块中的位移向量集合一起放在patchesAndDispVector中
void splice2patchF(string img, string personMark, vector<pair<Mat, vector<pair<int, int> > > >& patchesAndDispVector){
	//多一些搜索的过程，对一个块，查找markfile(txt)找到块的范围内的人的位置，得到这个块的位移向量的集合
	featureExtraction fg;
	Mat originalImg = imread(img);
	vector<pair<int, int> > pos;
	readMarkFile(personMark, pos);
	for (int r = 0; r < originalImg.rows / 13; r++)  //每个238*158的图像产生[238/13]*[158/13]=936个patch
	{
		for (int c = 0; c < originalImg.cols / 13; c++)
		{
			patch p;
			vector<pair<int, int>>  dispVectors;
			Rect region(c * 13, r * 13, 13, 13);
			for (auto it = pos.begin(); it != pos.end(); it++) //这里全部都遍历一遍，性能上还可以优化
			{
				if (it->first < (r + 1) * 13 && it->first >= r * 13 && it->second < (c + 1) * 13 && it->second >= c * 13)
					dispVectors.push_back({ r * 13 + 6 - it->first, c * 13 + 6 - it->second });
			}
			p.patchData = originalImg(region);
			Mat feature = fg.getFeature(p);
			//if (dispVectors.size() != 0)
				patchesAndDispVector.push_back({feature,dispVectors});
		}
	}
}

void readMarkFile(string markfile,vector<pair<int,int>>& pos){
	FILE *in = fopen(markfile.c_str(), "r");
	float x = 0;
	float y = 0;
	int z = 0;
	while (1){
		fscanf(in, "%f	%f	%d\n", &x, &y,&z);
		cout << "x = " << x << "    " << "y = " << y << endl;
		pos.push_back(make_pair((int)x,(int)y));
		if (feof(in))
			break;
	}
	fclose(in);
}