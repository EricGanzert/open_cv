#include <tutorials.hpp>

Mat src, src_gray;

int maxCorners = 23;
int maxTrackbar = 100;

RNG rng(12345);
char source_window[] = "Image";

int tutorial18( int argc, char** argv )
{
	src = imread( argv[1], 1 );
	
	cvtColor( src, src_gray, CV_BGR2GRAY );
	
	namedWindow( source_window, CV_WINDOW_AUTOSIZE );
	
	createTrackbar( "Max corners: ", source_window, &maxCorners, maxTrackbar, goodFeaturesToTrack_Demo );
	
	imshow( source_window, src );
	
	goodFeaturesToTrack_Demo( 0,0 );
	
	waitKey(0);
	return 0;
}

void goodFeaturesToTrack_Demo( int, void* )
{
	if ( maxCorners < 1 ) { maxCorners = 1; }
	
	//Parameters for Shi-Tomasi algorithm
	vector<Point2f> corners;
	double qualityLevel = 0.01;
	double minDistance = 10;
	int blockSize = 3;
	bool useHarrisDetector = false;
	double k = 0.04;
	
	Mat copy;
	copy = src.clone();
	
	//Apply corner detection
	goodFeaturesToTrack( src_gray,
						 corners,
						 maxCorners,
						 qualityLevel,
						 minDistance,
						 Mat(),
						 blockSize,
						 useHarrisDetector,
						 k );
	
	//Draw corners detected
	std::cout << "Number of corners detected: " << corners.size() << std::endl;
	int r=4;
	for ( int i=0; i<corners.size(); i++ )
	{ circle( copy, corners[i], r, Scalar( rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255)), -1, 8, 0 ); }
	
	//show what you got
	namedWindow( source_window, CV_WINDOW_AUTOSIZE );
	imshow( source_window, copy );
}
