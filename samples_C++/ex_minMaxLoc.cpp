#include <algorithm>
#include <opencv2/opencv.hpp>

int main(int agrc,  char* argv[]){
    std::string name1 = "../../data/lena.png";

    cv::Mat img1=cv::imread(name1, 0);
    cv::Mat img2;
    int64 time0 = cv::getTickCount();
    double minVal;
    double maxVal;
    cv::Point minLoc(0,0);
    cv::Point maxLoc(0,0);
    cv::minMaxLoc(img1, &minVal, &maxVal, &minLoc, &maxLoc);
    int64 time1 = cv::getTickCount();

    int64 time2 = cv::getTickCount();
	
    double maxv=img1.at<uchar>(0, 0);
    double minv=img1.at<uchar>(0, 0);

    cv::Point minLoc2(0,0);
    cv::Point maxLoc2(0,0);
    for(int y =0; y<img1.rows; y++){
        for(int x=0; x< img1.cols; x++){
			uchar count = img1.at<uchar>(y, x);
			if(count > maxv){
				maxv = count;
				maxLoc2 = cv::Point(x, y);
			}
			else if(count < minv){
				minv = count;
				minLoc2 = cv::Point(x, y);
			}
        }
    }

    int64 time3 = cv::getTickCount();
    std::cout << "min, max = " << minVal << " " << maxVal << std::endl;
    std::cout << "minLoc, maxLoc = " << minLoc << " " << maxLoc << std::endl;
     
    std::cout << "min2, max2 = " << minv << " " << maxv << std::endl;
    std::cout << "minLoc2, maxLoc2 = " << minLoc2 << " " << maxLoc2 << std::endl;

    std::cout << (time1-time0)/cv::getTickFrequency() << std::endl;
    std::cout << (time3-time2)/cv::getTickFrequency() << std::endl;

}


