#include <algorithm>
#include <opencv2/opencv.hpp>

int main(int agrc,  char* argv[]){
    std::string name1 = "../../data/lena.png";

    cv::Mat img1=cv::imread(name1, 0);
    cv::Mat img2;
    cv::Mat img2a;
    int64 time0 = cv::getTickCount();
    cv::normalize(img1, img2, 255, 0, cv::NORM_MINMAX);
    img1.convertTo(img2, CV_32F, 1.0/255);
    img2.convertTo(img2a, CV_8UC1, 255);
    int64 time1 = cv::getTickCount();



    int64 time2 = cv::getTickCount();
	cv::Size size=cv::Size(img1.cols, img1.rows);
	cv::Mat img3 = cv::Mat::zeros(size, CV_32F);
	cv::Mat img3a = cv::Mat::zeros(size, CV_8UC1);
    for(int y =0; y<img1.rows; y++){
        for(int x=0; x< img1.cols; x++){
			img3.at<float>(y,x) = static_cast<float>(img1.at<uchar>(y, x))/255.0;
        }
    }

    for(int y =0; y<img1.rows; y++){
        for(int x=0; x< img1.cols; x++){
			img3a.at<uchar>(y,x) = cv::saturate_cast<uchar>(img3.at<float>(y, x)*255);
        }
    }
    
    int64 time3 = cv::getTickCount();
    cv::imwrite("ex_convertTo.png", img2a);
    cv::imwrite("ex_convertTo_loop.png", img3a);

    std::cout << (time1-time0)/cv::getTickFrequency() << std::endl;
    std::cout << (time3-time2)/cv::getTickFrequency() << std::endl;

}


