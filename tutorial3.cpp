#include <tutorials.hpp>

using namespace std;

//histogram equalization
int tutorial3( int argc, char** argv )
{
	Mat src, dst;
	
	char source_window[] = "Source Image";
	char equalized_window[] = "Equalized Image";
	
	//Load the image
	src = imread( argv[1], 1 );
	
	if ( !src.data )
	{
		cout << "Usage: ./Histogram_Demo <path_to_image>" << endl;
		return -1;
	}
	
	//convert to grayscale
	cvtColor( src, src, CV_BGR2GRAY );
	
	//Apply Histogram equalization
	equalizeHist( src, dst );
	
	//Display results
	namedWindow( source_window, CV_WINDOW_AUTOSIZE );
	namedWindow( equalized_window, CV_WINDOW_AUTOSIZE );
	
	imshow( source_window, src );
	imshow( equalized_window, dst );
	
	waitKey(0);
}
