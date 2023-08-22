#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>

#define ROWS    5
#define COLUMNS 5

using namespace cv;

void fillIntegral(Mat & main, Mat & integral,int i, int j)
{
  if (i ==0 && j == 0)
    *((float *)(integral.data + integral.step[0]*i + integral.step[1]*j)) = *(main.data + main.step[0]*i + main.step[1]*j);

  else if ((i == 1 && j  == 0) || (i == 0 && j  == 1))
    *((float *)(integral.data + integral.step[0]*i + integral.step[1]*j)) =
        *(main.data + main.step[0]*i + main.step[1]*j) + *main.data;
  else if (i > 1 && j == 0) {
    fillIntegral(main, integral, i-1, j);
    *((float *)(integral.data + integral.step[0]*i + integral.step[1]*j)) =
        *((float *)(integral.data + integral.step[0]* (i-1) + integral.step[1]*j)) +
        *(main.data + main.step[0]*i + main.step[1]*j);
  }
  else if (i == 0 && j > 1) {
    fillIntegral(main, integral, i, j-1);
    *((float *)(integral.data + integral.step[0]*i + integral.step[1]*j)) =
        *((float *)(integral.data + integral.step[0]* (i) + integral.step[1]*(j-1))) +
        *(main.data + main.step[0]*i + main.step[1]*j);
  }

  else {
    int lasti = i > 0 ? i - 1 : i;
    int lastj = j > 0 ? j - 1 : j;

    if (integral.at<float>(lasti,lastj) < 0)
      fillIntegral(main, integral, lasti, lastj);

    if (integral.at<float>(lasti,j) < 0)
      fillIntegral(main, integral, lasti, j);

    if (integral.at<float>(i,lastj) < 0)
      fillIntegral(main, integral, i, lastj);

    *((float *)(integral.data + integral.step[0]*i + integral.step[1]*j)) =
        *((float *)(integral.data + integral.step[0]*lasti + integral.step[1]*j)) +
        *((float *)(integral.data + integral.step[0]*i + integral.step[1]*lastj)) +
        *(main.data + main.step[0]*i + main.step[1]*j) -
        *((float *)(integral.data + integral.step[0]*lasti + integral.step[1]*lastj));

  }

}

int main(int argc, char *argv[])
{
  Mat main1(ROWS,COLUMNS,CV_8UC1);
  Mat integral(Mat(ROWS,COLUMNS,CV_32FC1,Scalar(-1.f)));

  RNG rng;
  rng.fill(main1,RNG::UNIFORM,0,11);

  std::cout<<main1<<'\n';
  std::cout<<integral<<'\n';

  fillIntegral(main1, integral, ROWS-1, COLUMNS-1);
  Mat output;
  cv::integral(main1,output,-1);
  printf("All done\n");
  std::cout<<main1<<'\n';
  std::cout<<integral<<'\n';
  std::cout<<output<<'\n';
  return 0;
}
// https://docs.opencv.org/2.4/doc/tutorials/core/how_to_scan_images/how_to_scan_images.html#performance-difference
