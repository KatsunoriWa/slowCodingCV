#include <opencv2/opencv.hpp>

int main(int agrc,  char* argv[]){
    std::string name1 = "../data/lena.png";

    cv::Mat img1=cv::imread(name1, 0);

    cv::Mat img3 = cv::Mat::zeros(img1.size(), img1.type());
    cv::Mat img4=cv::Mat::zeros(img1.size(), img1.type());

    int64 time0 = cv::getTickCount();
    img3.setTo(255, img1>128);

    int64 time1 = cv::getTickCount();

    std::cout << (time1-time0)/cv::getTickFrequency() << std::endl;


    int64 time2 = cv::getTickCount();

    for(int y =0; y<img1.rows; y++){
        for(int x=0; x< img1.cols; x++){
            if(img1.at<uchar>(y, x)>128){
                img4.at<uchar>(y, x)=255;
            }
        }
    }
    int64 time3 = cv::getTickCount();
    std::cout << (time3-time2)/cv::getTickFrequency() << std::endl;

    cv::imwrite("img3.png", img3);
    cv::imwrite("img4.png", img4);
}


