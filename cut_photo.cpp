#include "cut_photo.h"

cut_photo::cut_photo()
{
}

cut_photo::~cut_photo()
{
}

void cut_photo::set_x(int a)
{
	if (a <= 0)
	{
		std::cout << " x vaild " << std::endl;
	}
	else
	{
		x = a;
	}
}

void cut_photo::set_y(int b)
{
	if (b <= 0)
	{
		std::cout << " y vaild " << std::endl;
	}
	else
	{
		y = b;
	}
}

void cut_photo::cutcut_photo(std::vector<std::string> photo_v)
{
	int check_use = 0;

	if (x <= 0 || y <= 0)
	{
		std::cout << " x or y vaild " << std::endl;
	}
	else
	{
		for (unsigned int i = 0; i < photo_v.size(); i++)
		{
			cv::Mat src = cv::imread(photo_v[i] + ".jpg");
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
							cut_photo_result.push_back(image);
							// ¥ª¤W ((src.cols - y), j)  ¥k¤U(src.cols - 1, j+x-1)
						}
						else
						{
							cv::Rect rect((k - y), j, y, x);
							cv::Mat image = src(rect);
							cut_photo_result.push_back(image);
							// ¥ª¤W ((k-y),j)  ¥k¤U (k-1,j+x-1)
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
}
