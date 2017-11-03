#include <opencv2/opencv.hpp>

int main(int agrc,  char* argv[]){
    cv::Size size = cv::Size(1024, 1024);
    
    int64 time0 = cv::getTickCount();
    for(int i=0; i< 1000; i++){
		cv::Mat img1=cv::Mat(size, CV_8UC3, cv::Scalar(128, 128, 128));
	}
    int64 time1 = cv::getTickCount();

    int64 time2 = cv::getTickCount();
    for(int i=0; i< 1000; i++){
		cv::Mat img2(size, CV_8UC3, cv::Scalar(128, 128, 128));
	}
    int64 time3 = cv::getTickCount();

    std::cout << (time1-time0)/cv::getTickFrequency() << std::endl;
    std::cout << (time3-time2)/cv::getTickFrequency() << std::endl;

//	cv::imwrite("img1.png", img1);
//	cv::imwrite("img2.png", img2);
}

