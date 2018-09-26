#include <iostream>
#include <string>
#include <vector>
#include <opencv2/opencv.hpp>

// 切割圖片 cut photo
void cutcut_photo(std::vector<std::string> ,int,int, int);

int main()
{	
	std::vector<std::string> photo_v;  // store which photos want to cut
	photo_v.push_back("a.jpg");  // "a.jpg" is the name of the photo
	photo_v.push_back("b.jpg");  // "b.jpg" is also the name of the photo
	//void cutcut_photo(std::vector<std::string> photo_v, int x, int y, int photo_i)
	// x : 長 (height) 要幾 piexl
	// y : 寬 (width)  要幾 piexl
	// photo_i : first the name of finished photo  (ex: if photo_i == 1 ,the first the name of finished photo is "1.jpg")
	cutcut_photo(photo_v, 416, 416, 1);

	/*
       /              寬   width               \
	    ---------------------------------------
	 / |                                       |
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
	 \ |                                       |
	    ---------------------------------------



	*/

	std::system("pause");

	return 0;
}

void cutcut_photo(std::vector<std::string> photo_v, int x, int y, int photo_i)
{
	// x : 長 (height) 要幾 piexl
	// y : 寬 (width)  要幾 piexl

	int check_use = 0;
	for (unsigned int i = 0; i < photo_v.size(); i++)
	{
		cv::Mat src = cv::imread(photo_v[i]);
		check_use = 0;
		for (int j = 0; j < src.rows; j)
		{
			for (int k = 0; k < src.cols; k)
			{
				if (k < src.cols && j + x < (src.rows + 1))
				{
					k = k + y;
					if (k >= src.cols)
					{
						// k = src.cols - y;
						cv::Rect rect((src.cols - y), j, y, x);
						cv::Mat image = src(rect);
						cv::imwrite((std::to_string(photo_i) + ".jpg"), image);
						photo_i = photo_i + 1;
					}
					else
					{
						cv::Rect rect((k - y), j, y, x);
						cv::Mat image = src(rect);
						cv::imwrite((std::to_string(photo_i) + ".jpg"), image);
						photo_i = photo_i + 1;
						if (k + y == (src.cols))
						{
							k = k + y;
						}
						else
						{
							k = (k - y + (y / 2));
						}
					}
				}
				else
				{
					k = src.cols;
				}
			}
			if (check_use == 1)
			{
				j = src.rows;
			}
			else
			{
				if (j + x >= src.rows)
				{
					j = j + x;
				}
				else
				{
					j = j + (x / 2);
				}
				if (j < src.rows)
				{
					j = j + x;
					if (j >= src.rows)
					{
						j = src.rows - x;
						check_use = 1;
					}
					else
					{
						j = j - x;
					}
				}
			}
		}
	}
	
}