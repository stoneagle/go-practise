//#include "global.h"
#include "clsAPI.h"
#include <pthread.h>
#include <iostream>
using namespace std;
using namespace cv;

#include <cv.hpp>

/* Pair (label, confidence) representing a prediction. */

//#include "squeezenet.hpp"

// 0: read mat; 1: read buffer
#define READBUFFER 0

pthread_mutex_t mutex;

static int THREAD_NUM;

struct thread_param{
	BookReading* objBR;
#if READBUFFER 
    char* ptr_img;
    int len;
#else
	cv::Mat* ptr_img;
#endif
	int modelid;
	int coverid;
	int threadID;
};

void* proc(void* arg){
	thread_param ti = *((thread_param*)arg);
	std::vector<stru_predrst> predictions;

	clock_t time1 = clock();
#if READBUFFER
	//ti.objBR->readcover_fixedsize(ti.ptr_img, ti.len, predictions);
	//pthread_mutex_lock(&mutex);
	Mat buffer = Mat(1, ti.len, CV_8U, ti.ptr_img);
	Mat cover_fixed_img = imdecode(buffer, CV_LOAD_IMAGE_COLOR);
	stru_predrst res = ti.objBR->readcover_fixedsize(cover_fixed_img);
	//pthread_mutex_unlock(&mutex);

	predictions.push_back(res);
#else
	ti.objBR->readcover(*(ti.ptr_img), predictions);
#endif
	clock_t time2 = clock();
	std::cout<<"bookid: "<< predictions[0].bookid<< "; contentid: "<<predictions[0].contentid<<
			   "; subid:"<<predictions[0].subid<<"; scor:"<< predictions[0].score<<"; isCover: "<<predictions[0].isCover<<std::endl;

	float totaltime = 1000*(float)(time2-time1)/CLOCKS_PER_SEC;
	std::cout<<"threadID<"<<ti.threadID<<">  "
			 <<"proc proc time :"<<totaltime<<"ms"<<std::endl;

	predictions.clear();


/*
	time1 = clock();
#if READBUFFER
	//ti.objBR->readcontent_fixedsize(ti.ptr_img, ti.len, ti.ptr_img, ti.len, ti.modelid, predictions, ti.coverid);
	res = ti.objBR->readcontent_fixedsize(cover_fixed_img, cover_fixed_img, ti.modelid, ti.coverid);
	predictions.push_back(res);
#else
	ti.objBR->readcontent(*(ti.ptr_img), ti.modelid, predictions, ti.coverid);
#endif
	time2 = clock();

	totaltime = 1000*(float)(time2-time1)/CLOCKS_PER_SEC;
	std::cout<<"threadID<"<<ti.threadID<<">  "
			 <<"proc proc time :"<<totaltime<<"ms"<<std::endl;

	for(size_t i = 0; i < predictions.size(); i++){
		stru_predrst p = predictions[i];
		std::cout <<"threadID<"<<ti.threadID<<">  "
				  << p.bookid << " - \"" << p.name << "\" " << p.score << std::endl;
	}
*/
}

int main(int argc, char** argv){
	if(argc != 4){
		std::cerr << "Usage: " << argv[0]
				  << " model img.jpg threadsNum" << std::endl;
		return 1;
	}

	string model_file = argv[1];
	if(model_file[model_file.size() - 1] == '/')
		model_file = model_file.substr(0, model_file.size()-1);
	string tmp_num = argv[3];
	THREAD_NUM = atoi(tmp_num.c_str());


    string file = argv[2];
#if READBUFFER
    FILE*fpr = fopen(file.c_str(),"rb");
    int prev = ftell(fpr);
    fseek(fpr, 0L, SEEK_END);
    int len = ftell(fpr);
    fseek(fpr, prev, SEEK_SET);
    char* img = (char*)malloc(len * sizeof(char));
    fread(img, sizeof(char), len, fpr);
    fclose(fpr);
#else 
	cv::Mat img = cv::imread(file, -1);
#endif


	std::cout << "---------Prediction for" << file << "----------"<< std::endl;

	int modelid = 1;
	int coverid = 32; //12

	pthread_t* thp_dicore = (pthread_t*)malloc(THREAD_NUM * sizeof(pthread_t));
	thread_param ti[THREAD_NUM];
	for(int i = 0; i < THREAD_NUM; i++){
		//////init thread_param ti[THREAD_NUM]/////
		ti[i].objBR = new BookReading(model_file);
#if READBUFFER
        ti[i].ptr_img = img;
        ti[i].len = len;
#else
		ti[i].ptr_img = &img;
#endif
		ti[i].modelid = modelid;
		ti[i].coverid = coverid;
		ti[i].threadID = i+1;
		//////////////////////////////
		pthread_create(&(thp_dicore[i]), NULL, proc, &ti[i]);
	}
	
	for(int i = 0; i < THREAD_NUM; i++){
		pthread_join(thp_dicore[i], NULL);
	}
	
	if(thp_dicore != NULL){
		free(thp_dicore);
		thp_dicore = NULL;
	}
	
	//free thread_param ti[THREAD_NUM]
	for(int i = 0; i < THREAD_NUM; i++){
		delete ti[i].objBR;
	}
#if READBUFFER
    free(img);
#endif

}
