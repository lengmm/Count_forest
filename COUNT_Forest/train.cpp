#include "train.h"
#include "patch.h"
#include  "config.h"
#include <utility>
#include <iostream>

using std::pair;
using std::cout;
using std::endl;

extern config cf;
train::train()
{
	//开始分块和将块和位移向量对应起来生成样本
	cout << "开始生成训练样本" << std::endl;
	vector<pair<Mat, vector<pair<int, int> > > >   patchAndDisp;
	for (int i = 0; i < cf.trainImgs.size(),i < cf.markFiles.size(); i++)
	{
		splice2patchF(cf.trainImgs[i], cf.markFiles[i] , patchAndDisp);
	}
	cout << patchAndDisp.size() << endl;
	//生成训练样本done,下面开始用训练样本去训练随机森林
	for (int index = 0; index < patchAndDisp.size(); index++)
		cout<<patchAndDisp[index].second.size()<<endl;
	system("pause");
}


train::~train()
{
}
