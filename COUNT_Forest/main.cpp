#include "train.h"
#include "predict.h"
#include <iostream>
using std::cout;
using std::endl;


int main(int argc, char** argv){
	if (strcmp(argv[1],"train") == 0)			//�����ѵ���׶Σ�������ѵ�����ݼ���ص������������ڵ��ļ���·��
	{
		train   tr;
	}else if (argv[1] == "predict")		//�����Ԥ��׶Ρ��������Ԥ���ͼƬ��·��
	{
		predict  pr(argv[2]);
	}
}