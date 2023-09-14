#include "opencv2/highgui/highgui.hpp"

#define ROWS    100
#define COLUMNS 100

#define STARTX   20
#define STARTY   5
#define ENDX   40
#define ENDY   20

using namespace cv;

int main(int argc, char *argv[])
{
  Mat m(Mat::zeros(ROWS,COLUMNS,CV_8UC3));
  namedWindow("win");
  int i,j;
  uchar * mp;
  for(j=STARTX -1; j < ENDX;j++)
    for(i=STARTY-1;i<ENDY;i++){
      mp = (m.data + m.step[0]*i +m.step[1]*j);
      mp[0] = 0;
      mp[1] = 255;
      mp[2] = 0;
    }

  imshow("win",m);
  waitKey(0);
  destroyAllWindows();

  return 0;
}
