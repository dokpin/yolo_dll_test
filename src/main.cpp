#include "yolo_v2_class.hpp"
#include <string>
//#include "opencv2/opencv.hpp"

int main()
{
	Detector dt((std::string)"./yolo/yolov4.cfg", (std::string)"./yolo/yolov4.weights");

	std::vector<bbox_t> results;
	results = dt.detect("./yolo/dog.jpg", 0.7);

	//cv::Mat img = cv::imread("./yolo/dog.jpg");

	for (int i = 0; i < results.size(); i++)
	{
		//cv::rectangle(img, cv::Rect(results[i].x, results[i].y, results[i].w, results[i].h), cv::Scalar(0, 0, 255), 3);
		printf("index: %d / confidence: %g\n", results[i].obj_id, results[i].prob);
	}
	
	//cv::imshow("results", img);
	//cv::waitKey();/

	return 0;
}