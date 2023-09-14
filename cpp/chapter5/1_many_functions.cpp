#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc.hpp"

#define ROWS     100
#define COLUMNS   100

using namespace cv;

int main(int argc, char *argv[])
{
  Mat mat(Mat::zeros(ROWS,COLUMNS,CV_8UC3));
  namedWindow("mat",WINDOW_AUTOSIZE);

  // Draw circle
  circle(mat, Point(50,50), 10, Scalar(128,255,100));
  imshow("mat",mat);
  char c;
  c = waitKey(0);

  destroyAllWindows();
  return 0;
}
