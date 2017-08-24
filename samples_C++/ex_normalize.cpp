#include <algorithm>
#include <opencv2/opencv.hpp>

int main(int agrc,  char* argv[]){
    std::string name1 = "../../data/lena.png";

    cv::Mat img1=cv::imread(name1, 0);
    cv::Mat img2;
    int64 time0 = cv::getTickCount();
    cv::normalize(img1, img2, 255, 0, cv::NORM_MINMAX);
    int64 time1 = cv::getTickCount();



    int64 time2 = cv::getTickCount();
	cv::Size size=cv::Size(img1.cols, img1.rows);
	cv::Mat img3 = cv::Mat::zeros(size, CV_8UC1);
    uchar maxv=img1.at<uchar>(0, 0);
    uchar minv=img1.at<uchar>(0, 0);
    for(int y =0; y<img1.rows; y++){
        for(int x=0; x< img1.cols; x++){
			maxv = std::max(img1.at<uchar>(y, x), maxv);
			minv = std::min(img1.at<uchar>(y, x), minv);
        }
    }

    for(int y =0; y<img1.rows; y++){
        for(int x=0; x< img1.cols; x++){
			img3.at<uchar>(y,x) = cv::saturate_cast<uchar>(img1.at<uchar>(y, x) * 255.0/(maxv -minv));
        }
    }
    
    int64 time3 = cv::getTickCount();
    cv::imwrite("ex_normalize.png", img2);
    cv::imwrite("ex_normalize_loop.png", img3);

    std::cout << (time1-time0)/cv::getTickFrequency() << std::endl;
    std::cout << (time3-time2)/cv::getTickFrequency() << std::endl;

}


