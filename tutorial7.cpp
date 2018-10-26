#include <tutorials.hpp>

Mat img; Mat templ; Mat result;
char image_window[] = "Source Image";
char result_window[] = "Result Image";
char templ_window[] = "Template Image";

int match_method;
int max_trackbar = 5;

int tutorial7( int argc, char** argv )
{
	img = imread( argv[1], 1 );
	Size subImgSize( img.cols/2, img.rows/2.5 );
	templ = Mat::zeros( subImgSize, img.type() );
	img( Range( img.rows/3.5, img.rows/3.5 + templ.rows ), Range( img.cols/4.0, img.cols/4.0 + templ.cols ) ).copyTo(templ);
	
	//Create Window
	namedWindow( image_window, CV_WINDOW_AUTOSIZE );
	namedWindow( result_window, CV_WINDOW_AUTOSIZE );
	namedWindow( templ_window, CV_WINDOW_AUTOSIZE );	
	
	//Create trackbar
	char trackbar_label[] = "Method: \n 0: SQDIFF \n 1: SQDIFF NORMED \n 2: TM CCORR \n 3: TM CCORR NORMED \n 4: TM COEFF \n 5: TM COEFF NORMED";
	createTrackbar( trackbar_label, image_window, &match_method, max_trackbar, MatchingMethod );
	
	MatchingMethod( 0, 0 );
	
	waitKey(0);
	return 0;
}

void MatchingMethod( int, void* )
{
	//Source image to display
	Mat img_display;
	img.copyTo( img_display );
	
	//Create the result matrix
	int result_cols = img.cols - templ.cols + 1;
	int result_rows = img.rows - templ.rows + 1;
	
	result.create( result_cols, result_rows, CV_32FC1 );
	
	//Do the matching and normalize
	matchTemplate( img, templ, result, match_method );
	normalize( result, result, 0, 1, NORM_MINMAX, -1, Mat() );
	
	//Localizing the best match with minMaxLoc
	double minVal; double maxVal; Point minLoc; Point maxLoc;
	Point matchLoc;
	
	minMaxLoc( result, &minVal, &maxVal, &minLoc, &maxLoc, Mat() );
	
	//For SQDIFF and SQDIFF NORMED, the best matches are lower values. For all other methods the higher the better
	if( match_method == CV_TM_SQDIFF || match_method == CV_TM_SQDIFF_NORMED )
		matchLoc = minLoc;
	else
		matchLoc = maxLoc;
		
	//Show what you got
	rectangle( img_display, matchLoc, Point( matchLoc.x + templ.cols, matchLoc.y + templ.rows ), Scalar(0,0,255), 2, 8, 0 );
	rectangle( result, matchLoc, Point( matchLoc.x + templ.cols, matchLoc.y + templ.rows ), Scalar(0,0,255), 2, 8, 0 );

	imshow( image_window, img_display );
	imshow( result_window, result );
	imshow( templ_window, templ );
	
	return;
}
