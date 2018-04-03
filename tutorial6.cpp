#include <tutorials.hpp>

//Calculate the histogram model of a feature and then use it to find this feature in an image 

//If you have a histogram of a target pattern then you can use it to find that target in an image

Mat src; Mat hsv; Mat hue;
int bins = 25;
	
int tutorial6( int argc, char** argv )
{
	src = imread(argv[1], 1);
	resize( src, src, Size(0,0), 0.1, 0.1 );
	
	//transform to HSV
	cvtColor( src, hsv, CV_BGR2HSV );
	
	//Use only the hue value
	hue.create( hsv.size(), hsv.depth() );
	int ch[] = {0,0};
	mixChannels( &hsv, 1, &hue, 1, ch, 1 );
	
	//Create trackbar to enter the number of bins
	char window_image[] = "source_image";
	namedWindow( window_image, CV_WINDOW_AUTOSIZE );
	createTrackbar( "HUE bins:  ", window_image, &bins, 180, Hist_and_Backproj );
	Hist_and_Backproj( 0,0 );
	
	//Show the image
	imshow( window_image, src );
	
	waitKey(0);
	
	return 0;
}

void Hist_and_Backproj( int, void* )
{
	MatND hist;
	int histSize = MAX( bins, 2 );
	float hue_range[] = { 0, 180 };
	const float* ranges = { hue_range };
	
	//get the histogram and normalize it
	calcHist( &hue, 1, 0, Mat(), hist, 1, &histSize, &ranges, true, false );
	normalize( hist, hist, 0, 255, NORM_MINMAX, -1, Mat() );
	
	//Get Backprojection
	MatND backproj;
	calcBackProject( &hue, 1, 0, hist, backproj, &ranges, 1, true );
	
	//Draw backprojection
	imshow( "BackProj", backproj );
	
	//Draw the histogram
	int w=400; int h=400;
	int bin_w = cvRound( (double)w/histSize );
	Mat histImg = Mat::zeros( w, h, CV_8UC3 );
	
	for( int i=0; i < bins; i++ )
	{
		rectangle( histImg, Point( i*bin_w, h ), Point( (i+1)*bin_w, h - cvRound( hist.at<float>(i)*h/255.0 ) ), Scalar( 0, 0, 255 ) );
	}
	
	imshow( "Histogram", histImg );
}
