#include <tutorials.hpp>

using namespace std;

Mat src, canny, hough;
vector<Vec3f> circles;
int thresh = 100;
const int max_value = 255;
int accumulator_thresh = 30; int max_accumulator = 80;
int canny_thresh = 360; int max_canny = 400;

const char source_window_name[] = "source image";
const char canny_window_name[] = "canny image";
const char hough_window_name[] = "hough image";

int tutorial13( int argc, char** argv )
{
	src = imread( argv[1], 1 );
	cvtColor( src, src, CV_BGR2GRAY );
	
	namedWindow(hough_window_name, CV_WINDOW_AUTOSIZE);
	namedWindow(canny_window_name, CV_WINDOW_AUTOSIZE);
	
	createTrackbar( "accumulator thresh", hough_window_name, &accumulator_thresh, max_accumulator, hough_callback);
	createTrackbar( "canny thresh", hough_window_name, &canny_thresh, max_canny, hough_callback );
	createTrackbar( "canny thresh", canny_window_name, &canny_thresh, max_canny, canny_callback );
	
	canny_callback(0,0);
	hough_callback(0,0);
	
	waitKey(0);
	return 0;
}

void hough_callback( int, void* )
{
	canny_thresh = max(canny_thresh, 1);
	accumulator_thresh = max(accumulator_thresh, 1);
	
	HoughCircles( src, circles, CV_HOUGH_GRADIENT, 1, 300, canny_thresh, accumulator_thresh, 1, 500 );
	
	hough = src.clone();
	
	for (int i=0; i<circles.size(); i++)
	{
		Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
		int radius = cvRound(circles[i][2]);
		
		circle( hough, center, 3, Scalar(0,255,0), -1, 8, 0 );
		circle( hough, center, radius, Scalar(0,0,255), 2, 8, 0 );		
	}
	
	imshow( hough_window_name, hough );
}

void canny_callback(int, void*)
{
	canny_thresh = max(canny_thresh, 1);
	Canny( src, canny, cvRound(canny_thresh/2), canny_thresh, 3 );
	
	imshow( canny_window_name, canny );
}
