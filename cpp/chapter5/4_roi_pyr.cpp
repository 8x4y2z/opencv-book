#include "opencv2/highgui/highgui.hpp"

#define ROWS         210
#define COLUMNS      ROWS
#define STRIP        10
#define STEP         20

using namespace cv;

int main(int argc, char *argv[])
{
  Mat mat = Mat::zeros(ROWS,COLUMNS,CV_8UC1);
  int i,j;
  uchar pixelVal = 0;
  namedWindow("mat");
  for(i=0,j=0; ROWS-2*i-STRIP > 0; i+=STRIP,j += STRIP,pixelVal += STEP)
    mat(Rect(i,j,ROWS-2*i,COLUMNS-2*j)).setTo(pixelVal);

  imshow("mat",mat);
  waitKey(0);
  destroyAllWindows();
  return 0;
}
