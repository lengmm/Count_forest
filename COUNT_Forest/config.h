#pragma once
#include <string>
#include <vector>

using std::vector;
using std::string;

class config
{
public:
	config(char* configFile);
	~config();
	string trainImgDir;
	string trainMarkDir;
	vector<string> trainImgs;
	vector<string> markFiles;
};

void readDir(char* filelist, vector<string>&  files);
//void readDir(char* dir, vector<string>& files,char* type);