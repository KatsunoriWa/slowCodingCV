#include <opencv2/opencv.hpp>

int main(int agrc,  char* argv[]){
    int64 time0 = cv::getTickCount();
    cv::Size size(1024, 1024);
	for(int i=0; i<100; i++){
		cv::Mat img3 = cv::Mat::zeros(size, CV_8UC3);
	}
    int64 time1 = cv::getTickCount();

    int64 time2= cv::getTickCount();
	for(int i=0; i<100; i++){
		cv::Mat img4(size, CV_8UC3, 0);
	}
    int64 time3=cv::getTickCount();

    std::cout << (time1-time0)/cv::getTickFrequency() << std::endl;
    std::cout << (time3-time2)/cv::getTickFrequency() << std::endl;

}


