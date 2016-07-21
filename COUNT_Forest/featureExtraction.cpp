#include "featureExtraction.h"
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;

Mat featureExtraction::getFeature(patch p){
	Mat  Log;   //用来保存特征提取的结果
	Mat afterRmNoise;
	Mat dst;
	cv::GaussianBlur(p.patchData, afterRmNoise, Size(3, 3), 0, 0, BORDER_DEFAULT);
	Laplacian(afterRmNoise, dst, ddepth, kernel_size, scale, delta, BORDER_DEFAULT);
	convertScaleAbs(dst, Log);
	return Log;
}
