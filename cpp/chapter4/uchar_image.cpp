#include "opencv2/highgui/highgui.hpp"

#define ROWS    500
#define COLUMNS 500
#define HEIGHT  20
#define WIDTH   10

using namespace cv;

void print0(Mat & m, Rect & r)
{
  Mat subMat = m(r);
  subMat.row(0).setTo(255);
  subMat.row(19).setTo(255);

  subMat.col(0).setTo(255);
  subMat.col(9).setTo(255);
  imshow("uchar_image",m);

}


void print1(Mat & m, Rect & r)
{
  Mat subMat = m(r);
  subMat.col(9).setTo(255);
  imshow("uchar_image",m);


}

void print2(Mat & m, Rect & r)
{
  Mat subMat = m(r);
  subMat.row(0).setTo(255);
  subMat.row(9).setTo(255);
  subMat.row(19).setTo(255);

  subMat(Range(0,10),Range(9,10)).setTo(255);
  subMat(Range(10,19),Range(0,1)).setTo(255);
  imshow("uchar_image",m);

}

void print3(Mat & m, Rect & r)
{
  Mat subMat = m(r);
  subMat.row(0).setTo(255);
  subMat.row(9).setTo(255);
  subMat.row(19).setTo(255);

  subMat.col(9).setTo(255);
  imshow("uchar_image",m);

}

void print4(Mat & m, Rect & r)
{
  Mat subMat = m(r);
  subMat(Range(0,9),Range(0,1)).setTo(255);
  subMat.row(9).setTo(255);

  subMat.col(9).setTo(255);
  imshow("uchar_image",m);

}

void print5(Mat & m, Rect & r)
{
  Mat subMat = m(r);
  subMat.row(0).setTo(255);
  subMat.row(9).setTo(255);
  subMat.row(19).setTo(255);

  subMat(Range(10,19),Range(9,10)).setTo(255);
  subMat(Range(0,10),Range(0,1)).setTo(255);
  imshow("uchar_image",m);

}

void print6(Mat & m, Rect & r)
{
  Mat subMat = m(r);
  subMat.row(0).setTo(255);
  subMat.row(9).setTo(255);
  subMat.row(19).setTo(255);

  subMat.col(0).setTo(255);
  subMat(Range(10,19),Range(9,10)).setTo(255);
  imshow("uchar_image",m);

}

void print7(Mat & m, Rect & r)
{
  Mat subMat = m(r);
  subMat.row(0).setTo(255);
  subMat.col(9).setTo(255);
  imshow("uchar_image",m);
}

void print8(Mat & m, Rect & r)
{
  Mat subMat = m(r);
  subMat.row(0).setTo(255);
  subMat.row(9).setTo(255);
  subMat.row(19).setTo(255);

  subMat.col(0).setTo(255);
  subMat.col(9).setTo(255);
  imshow("uchar_image",m);

}

void print9(Mat & m, Rect & r)
{
  Mat subMat = m(r);
  subMat.row(0).setTo(255);
  subMat.row(9).setTo(255);
  subMat.row(19).setTo(255);

  subMat(Range(0,9),Range(0,1)).setTo(255);
  subMat.col(9).setTo(255);
  imshow("uchar_image",m);

}

void reset(Mat & m, Rect & r)
{
  Mat subMat = m(r);
  subMat.setTo(0);
  imshow("uchar_image",m);
}

void printNum(Mat & m, char c, Rect & r)
{
  switch (c) {
    case '0':
      print0(m,r);
      break;
    case '1':
      print1(m,r);
      break;
    case '2':
      print2(m,r);
      break;
    case '3':
      print3(m,r);
      break;
    case '4':
      print4(m,r);
      break;
    case '5':
      print5(m,r);
      break;
    case '6':
      print6(m,r);
      break;
    case '7':
      print7(m,r);
      break;
    case '8':
      print8(m,r);
      break;
    case '9':
      print9(m,r);
      break;

  }
}

void print(Mat & m,char c, int * i, int * j)
{

  Rect r;
  switch(c) {
    case 8:
      if (*i <= 0)
        return;
      (*i) -= 2;
      r = Rect(*i * WIDTH, *j * HEIGHT, WIDTH, HEIGHT);
      reset(m,r);
      break;
    case 13:
      if ((ROWS - (*j+1) * HEIGHT) < HEIGHT)
        return;
      (*j) += 2;
      (*i) = 0;
      break;
    default:
      if ((COLUMNS - *i * WIDTH) < WIDTH)
        return;
      r = Rect(*i * WIDTH, *j * HEIGHT, WIDTH, HEIGHT);
      (*i) += 2;
      printNum(m,c,r);
      break;
  }
}

int main(int argc, char *argv[])
{
  int i = 0, j = 0;
  namedWindow("uchar_image",cv::WINDOW_AUTOSIZE);
  Mat m = cv::Mat::zeros(ROWS,COLUMNS,CV_8U);
  imshow("uchar_image",m);
  char c;

  while((c=waitKey(0)) != 27)
    print(m,c,&i, &j);

  destroyAllWindows();

  return 0;
}
