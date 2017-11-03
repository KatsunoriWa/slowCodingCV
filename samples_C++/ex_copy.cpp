//#include <opencv2/opencv.hpp>
#include <vector>
class MyClass{
	std::vector<int> data;
	int n;
	public:
		MyClass(int n);
};

MyClass::MyClass(int n){
	this->data.reserve(n);
	this->n = n;
};


int main(int agrc,  char* argv[]){
    
//    int64 time0 = cv::getTickCount();
    for(int i=0; i< 1000; i++){
		MyClass m = MyClass(10000);
	}
//    int64 time1 = cv::getTickCount();

//    int64 time2 = cv::getTickCount();
    for(int i=0; i< 1000; i++){
		MyClass m(10000);
	}
//    int64 time3 = cv::getTickCount();

//    std::cout << (time1-time0)/cv::getTickFrequency() << std::endl;
//    std::cout << (time3-time2)/cv::getTickFrequency() << std::endl;

//	cv::imwrite("img1.png", img1);
//	cv::imwrite("img2.png", img2);
}

/**
 * コピーコンストラクタを呼び出すような書き方を避けること。
 * コピーコンストラクタを無効化すること。
 */
