#include "config.h"
#include <iostream>
#include <io.h>
using std::cout;
using std::endl;

config::config(char* configFile)
{
	FILE* in = fopen(configFile, "r");
	if (!in){
		printf("not found file %s.\n", configFile);
		exit(1);
	}
	char buf[256];
	fscanf(in, "trainImgDir: %255s\n", buf);
	trainImgDir = buf;
	cout << trainImgDir << std::endl;
	readDir(buf,trainImgs);
	fscanf(in, "trainMarkDir: %255s\n", buf);
	trainMarkDir = buf;
	cout << trainMarkDir << std::endl;
	readDir(buf, markFiles);
	fclose(in);
}

config::~config()
{

}

//��Ŀ¼��Ŀ¼�µ��ļ�·��д��files��,���ַ�ʽ��һ���ܰ�˳���������Ҫ�����е��ļ���д��һ���ļ���Ȼ����ļ�
//void readDir(char* dir,vector<string>& files,char* type){
//	char pattern[512];
//	sprintf(pattern,"%s\\*.%s",dir,type);
//	_finddata_t file;
//	long lf;
//	if ((lf = _findfirst(pattern, &file)) == -1)
//		cout << "�ļ�û���ҵ���" << endl;
//	else{
//		while (_findnext(lf, &file) == 0){
//			char filepath[512];
//			sprintf(filepath,"%s/%s", dir, file.name);
//			//cout << filepath << endl;
//			files.push_back(filepath);
//		}
//	}
//	
//
//}

void readDir(char* filelist, vector<string>&  files){
	FILE* in = fopen(filelist, "r");
	if (!in)
	{
		printf("not found file %s.\n", filelist);
		exit(1);
	}
	char file[256];
	while (1){
		fscanf(in, "%255s", file);
		files.push_back(file);
		if (feof(in))
			break;
	}
	fclose(in);
}


extern config cf("config.txt");