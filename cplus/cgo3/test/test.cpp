// test.cpp
#include "test.h"
#include "clsAPI.h"
#include <iostream>
using namespace std;
using namespace cv;
#include <cv.hpp>

struct thread_param{
	BookReading* objBR;
	cv::Mat* ptr_img;
	int modelid;
	int coverid;
	int threadID;
};

void CardIdentify(struct data card) {
    std::string model_file(card.modelPath, strlen(card.modelPath));
    std::string file(card.imgPath, strlen(card.imgPath));

	if(model_file[model_file.size() - 1] == '/')
		model_file = model_file.substr(0, model_file.size()-1);
	cv::Mat img = cv::imread(file, -1);
	int modelid = 1;
	int coverid = 32;
	thread_param ti;
	ti.objBR = new BookReading(model_file);
	ti.ptr_img = &img;
    ti.modelid = modelid;
    ti.coverid = coverid;
    ti.threadID = 1;

	std::vector<stru_predrst> predictions;
	ti.objBR->readcover(*(ti.ptr_img), predictions);
	delete ti.objBR;
    cardCallBack(card.appId, predictions[0].bookid);
}
