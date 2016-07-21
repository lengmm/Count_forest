#include "patch.h"
#include <utility>
#include "featureExtraction.h"
using std::pair;
using std::make_pair;
using namespace cv;
#include <iostream>
using std::cout;
using std::endl;

//��ͼ�񻮷ֳɿ飬������������������
void splice2patchF(string img, vector<Mat>& patches){
	featureExtraction fg;
	Mat originalImg = imread(img);
	for (int r = 0; r < originalImg.rows/13; r++)  //ÿ��238*158��ͼ�����[238/13]*[158/13]=936��patch
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

//��ͼ�񻮷ֳɿ飬���������������������Ϳ��е�λ����������һ�����patchesAndDispVector��
void splice2patchF(string img, string personMark, vector<pair<Mat, vector<pair<int, int> > > >& patchesAndDispVector){
	//��һЩ�����Ĺ��̣���һ���飬����markfile(txt)�ҵ���ķ�Χ�ڵ��˵�λ�ã��õ�������λ�������ļ���
	featureExtraction fg;
	Mat originalImg = imread(img);
	vector<pair<int, int> > pos;
	readMarkFile(personMark, pos);
	for (int r = 0; r < originalImg.rows / 13; r++)  //ÿ��238*158��ͼ�����[238/13]*[158/13]=936��patch
	{
		for (int c = 0; c < originalImg.cols / 13; c++)
		{
			patch p;
			vector<pair<int, int>>  dispVectors;
			Rect region(c * 13, r * 13, 13, 13);
			for (auto it = pos.begin(); it != pos.end(); it++) //����ȫ��������һ�飬�����ϻ������Ż�
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