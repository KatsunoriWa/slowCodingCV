#include <opencv2/opencv.hpp>

int main(int agrc,  char* argv[]){
    std::string name1 = "../data/lena.png";

    cv::Mat img1=cv::imread(name1, 0);
    cv::Mat img2;
    cv::flip(img1, img2, 1);
    cv::Mat img3;
    
    int64 time0 = cv::getTickCount();
    cv::addWeighted(img2, 0.5, img1, -0.5, 128, img3);
    int64 time1 = cv::getTickCount();

	cv::imwrite("addWeighted.png", img3);

	cv::Size size=cv::Size(img1.cols, img1.rows);
	cv::Mat img4 = cv::Mat::zeros(size, CV_8UC1);
	
    int64 time2 = cv::getTickCount();
	for(int y=0; y< img1.rows; y++){
		for(int x=0; x< img1.cols; x++){
			img4.at<uchar>(y,x) = 0.5*img2.at<uchar>(y,x) - 0.5* img1.at<uchar>(y,x) +128;
		}
	}
    int64 time3 = cv::getTickCount();
	cv::imwrite("addWeighted_loop.png", img4);
	
    std::cout << (time1-time0)/cv::getTickFrequency() << std::endl;
    std::cout << (time3-time2)/cv::getTickFrequency() << std::endl;

}
