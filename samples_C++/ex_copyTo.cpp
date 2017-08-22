#include <opencv2/opencv.hpp>

int main(int agrc,  char* argv[]){
    std::string name1 = "../../data/lena.png";
	std::string name2 = "../../data/home.jpg";

    cv::Mat img1=cv::imread(name1, 1);
    cv::Mat img2=cv::imread(name2, 1);
    
    cv::Mat gray1=cv::imread(name1, 0);

    cv::Mat img3 = img2.clone();
    cv::Mat img4 = img2.clone();

    int64 time0 = cv::getTickCount();
    img1.copyTo(img3, gray1>64);

    int64 time1 = cv::getTickCount();

    std::cout << (time1-time0)/cv::getTickFrequency() << std::endl;


    int64 time2 = cv::getTickCount();

    for(int y =0; y<img1.rows; y++){
        for(int x=0; x< img1.cols; x++){
            if(gray1.at<uchar>(y, x)>64){
                img4.at<cv::Vec3b>(y, x)=img1.at<cv::Vec3b>(y, x);
            }
        }
    }
    int64 time3 = cv::getTickCount();
    std::cout << (time3-time2)/cv::getTickFrequency() << std::endl;

    cv::imwrite("ex_copyTo.png", img3);
    cv::imwrite("ex_copyTo_loop.png", img4);
}


