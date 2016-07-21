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
void splice2patchF(string img, string personMark, vector<pair<Mat, vector<pair<int, int> > > >& patchAndDispVector);      //ѵ����ʱ����ͼƬ����صı������ȥ���ֳɿ飬�������λ��������Ӧ����,pair<patch,vector<vector<int>>,���浽txt�ļ�
void splice2patchF(string img, vector<Mat> patches);							//���Ե�ʱ��ֻ��Ҫ��ͼƬ���ֳɿ�