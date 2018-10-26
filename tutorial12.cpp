#include <tutorials.hpp>

Mat src; Mat src_gray;
int thresh = 100;
int max_thresh = 255;
RNG rng(12345);

int tutorial12( int argc, char** argv )
{
	src = imread( argv[1], 1 );
	cvtColor( src, src_gray, CV_BGR2GRAY );
	blur( src_gray, src_gray, Size(3,3) );
	
	char source_window = "Source";
	namedWindow( source_window, CV_WINDOW_AUTOSIZE );
	imshow( source_window, src );
	
	createTrackbar( "Canny thresh:" )
	
	return 0;
}

void thresh_callback( int, void* )
{
	
}
