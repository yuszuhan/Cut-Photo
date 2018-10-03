#pragma once
#ifndef CUT_PHOTO_H // __TEST_H__ 由 progrmmer 自己取名
#define CUT_PHOTO_H

#include <iostream>
#include <string>
#include <vector>
#include <opencv2/opencv.hpp>

class cut_photo
{
public:
	cut_photo();
	~cut_photo();

	std::vector<std::string> photo_v;
	std::vector<cv::Mat> cut_photo_result;

	void set_x(int);
	void set_y(int);
	void cutcut_photo(std::vector<std::string> photo_v);

private:
	int x = 0;
	int y = 0;
	/*
	Photo :

	   /              寬   width               \
	    ---------------------------------------
	/  |                                       |
	   |                                       |
	   |                                       |
	   |                                       |
	   |                                       |
	長 |                                       |
	h  |                                       |
	e  |                                       |
	i  |                                       |
	g  |                                       |
	h  |                                       |
	t  |                                       |
	   |                                       |
	   |                                       |
	   |                                       |
	\  |                                       |
	    ---------------------------------------
	*/
};


#endif