#include <opencv2/opencv.hpp>

int main(int agrc,  char* argv[]){
    std::string name1 = "../../data/lena.png";

    cv::Mat img1=cv::imread(name1, 0);
    int64 time0 = cv::getTickCount();
    cv::Mat     mean;
    cv::Mat     stddev;
    cv::meanStdDev(img1, mean, stddev );
    int64 time1 = cv::getTickCount();

    std::cout << "mean= " << mean << std::endl;
    std::cout << "stddev= " << stddev << std::endl;
    std::cout << "mean= " <<  mean.at<double>(0,0) << std::endl;
    std::cout << "stddev= " <<stddev.at<double>(0,0) << std::endl;

    int64 time2 = cv::getTickCount();
    double sum=0;
    for(int y=0; y<img1.rows; y++){
        for(int x=0; x< img1.cols; x++){
            sum += img1.at<uchar>(y, x);
        }
    }

    double meanv = sum /(img1.rows*img1.cols);
    int64 time3 = cv::getTickCount();
    std::cout <<"meanv=" << meanv << std::endl;

    std::cout << (time1-time0)/cv::getTickFrequency() << std::endl;
    std::cout << (time3-time2)/cv::getTickFrequency() << std::endl;

}


