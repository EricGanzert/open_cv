#include <tutorials.hpp>

Mat src, sharp, edges;
int edgeThresh = 1;
int lowThreshold = 38;
int const max_lowThreshold = 100;
int ratio = 3;
int kernel_size = 3;

int tutorial8(int argc, char** argv)
{
	src = imread(argv[1], 1);
	sharp = Mat::zeros( src.size(), src.type() );
	edges = Mat::zeros( src.size(), src.type() );
	
	GaussianBlur(src, sharp, Size(0,0), 3);
	//GaussianBlur(src, src, Size(0,0), 3);
	
	addWeighted( src, 1.5, sharp, -0.5, 0, sharp );
	
	namedWindow( "original Image", CV_WINDOW_AUTOSIZE );
	namedWindow( "new image", CV_WINDOW_AUTOSIZE );
	
	createTrackbar("MinThreshold", "new image", &lowThreshold, max_lowThreshold, CannyThreshold);
	
	imshow( "original Image", src );
	
	CannyThreshold(0,0);
	
	waitKey(0);
}

void CannyThreshold( int, void* )
{
	Canny( src, edges, lowThreshold, lowThreshold*ratio, kernel_size );
	
	imshow("new image", edges);
	imwrite( "edges.jpg", edges);
}
