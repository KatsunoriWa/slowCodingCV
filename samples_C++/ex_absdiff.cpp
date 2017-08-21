#include <opencv2/opencv.hpp>

int main(int agrc,  char* argv[]){
	std::string name1 = "../../data/lena.png";
	std::string name2 = "../../data/home.jpg";

	cv::Mat img1=cv::imread(name1, 0);
	cv::Mat img2=cv::imread(name2, 0);

	int64 time0 = cv::getTickCount();
	cv::Mat img3;
	cv::absdiff(img1, img2, img3);
	int64 time1 = cv::getTickCount();
	
	std::cout << (time1-time0)/cv::getTickFrequency() << std::endl;
	
	cv::Mat img4=cv::Mat::zeros(img1.size(), img1.type());
	int64 time2 = cv::getTickCount();
	for(int i=0; i<img1.rows; i++){
		for(int j=0; j<img1.cols;j++){
			img4.at<uchar>(i,j) = std::abs(img1.at<uchar>(i,j) - img2.at<uchar>(i,j));
		}
	}
	int64 time3 = cv::getTickCount();
	std::cout << (time3-time2)/cv::getTickFrequency() << std::endl;

	cv::imwrite("ex_absdiff.png", img3);
	cv::imwrite("ex_absdiff_loop.png", img4);
}

