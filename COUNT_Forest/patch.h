#pragma once
#include <vector>
#include <string>
#include <opencv2/opencv.hpp>
#include <utility>
using cv::Mat;
using std::vector;
using std::string;
using std::pair;

class patch
{
public:
	Mat patchData;
};

void readMarkFile(string markfile, vector<pair<int, int>>& pos);
void splice2patchF(string img, string personMark, vector<pair<Mat, vector<pair<int, int> > > >& patchAndDispVector);      //训练的时候用图片和相关的标记数据去划分成块，并将块和位移向量对应起来,pair<patch,vector<vector<int>>,保存到txt文件
void splice2patchF(string img, vector<Mat> patches);							//测试的时候只需要把图片划分成块