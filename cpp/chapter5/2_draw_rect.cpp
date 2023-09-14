#include "opencv2/highgui/highgui.hpp"

#define ROWS     100
#define COLUMNS  100

using namespace cv;

int main(int argc, char *argv[])
{
  Mat mat(Mat::zeros(ROWS,COLUMNS,CV_8UC3));
  char c;

  Rect r = Rect(Point(20,5),Point(40,20));
  mat(r).setTo(Scalar(0,255,0));

  namedWindow("win");

  imshow("win",mat);
  waitKey(0);
  destroyAllWindows();
  return 0;
}
