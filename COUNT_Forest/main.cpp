#include "train.h"
#include "predict.h"
#include <iostream>
using std::cout;
using std::endl;


int main(int argc, char** argv){
	if (strcmp(argv[1],"train") == 0)			//如果是训练阶段，则输入训练数据集相关的配置数据所在的文件的路径
	{
		train   tr;
	}else if (argv[1] == "predict")		//如果是预测阶段。则输入待预测的图片的路径
	{
		predict  pr(argv[2]);
	}
}