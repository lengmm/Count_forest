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
	//��ʼ�ֿ�ͽ����λ��������Ӧ������������
	cout << "��ʼ����ѵ������" << std::endl;
	vector<pair<Mat, vector<pair<int, int> > > >   patchAndDisp;
	for (int i = 0; i < cf.trainImgs.size(),i < cf.markFiles.size(); i++)
	{
		splice2patchF(cf.trainImgs[i], cf.markFiles[i] , patchAndDisp);
	}
	cout << patchAndDisp.size() << endl;
	//����ѵ������done,���濪ʼ��ѵ������ȥѵ�����ɭ��
	for (int index = 0; index < patchAndDisp.size(); index++)
		cout<<patchAndDisp[index].second.size()<<endl;
	system("pause");
}


train::~train()
{
}
