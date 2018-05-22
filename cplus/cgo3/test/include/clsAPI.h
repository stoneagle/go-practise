/************************************************************************/
/* 
created by roobovision
version 0.0.1
*/
/************************************************************************/
#ifndef __CLSAPI_H__
#define __CLSAPI_H__

#include <string>
#include <vector>
#include "cv.h"

struct stru_predrst{
    stru_predrst():
        bookid(-1),
        contentid(-1),
        subid(-1),
        score(-1),
        isCover(0)
    {
        name = "";
    }

    int bookid;
    int contentid;
    int subid;
    float score;
    int isCover;
    std::string name;
};


class BookReading{
public:
	BookReading(const std::string path);

	~BookReading();

	void readcover(cv::Mat& srcImg, std::vector<stru_predrst>& vRst);
	//stru_predrst readcover(cv::Mat& srcImg);

	void readcontent(cv::Mat& srcImg, int sid, std::vector<stru_predrst>& vRst, int cid = -1);
	//stru_predrst readcontent(cv::Mat& srcImg, int sid, int cid = -1);

	/*
	 * operate cover data(already preprocess)
	 */
	//void readcover_fixedsize(const char* coverbuf, const int coversize, std::vector<stru_predrst>& vRst);
	stru_predrst readcover_fixedsize(cv::Mat& cover_fixed_img);

	/*
	 * operate content data(already preprocess)
	 */
	//void readcontent_fixedsize(const char* contentbuf, const int contentsize, const char* coverbuf, const int coversize, int sid, std::vector<stru_predrst>& vRst, int cid);
	stru_predrst readcontent_fixedsize(cv::Mat& content_fixed_img, cv::Mat& cover_fixed_img, int sid, int cid);

private:
	void* pRet;
};


#endif

