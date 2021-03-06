#include <tutorials.hpp>

int tutorial5( int argc, char** argv )
{
	Mat src_base, hsv_base;
	Mat src_test1, hsv_test1;
	Mat src_test2, hsv_test2;
	Mat hsv_half_down;
	
	if( argc < 4 )
	{
		printf("error, please provide 3 images in argv\n");
		return -1;
	}
	
	src_base = imread( argv[1], 1 );
	src_test1 = imread( argv[2], 1 );
	src_test2 = imread( argv[3], 1 );
	
	//Comvert to HSV
	cvtColor( src_base, hsv_base, COLOR_BGR2HSV );
	cvtColor( src_test1, hsv_test1, COLOR_BGR2HSV );
	cvtColor( src_test2, hsv_test2, COLOR_BGR2HSV );
	
	hsv_half_down = hsv_base( Range( hsv_base.rows/2, hsv_base.rows - 1 ), Range( 0, hsv_base.cols -  1 ) );
	
	//Using 50 bins for hue and 60 for saturation
	int h_bins = 50; int s_bins = 60;
	int histSize[] = { h_bins, s_bins };
	
	//Hue varies from 0-179, saturation from 0-255
	float h_ranges[] = { 0, 180 };
	float s_ranges[] = { 0, 256 };
	
	const float* ranges[] = { h_ranges, s_ranges };
	
	//Use the o-th and 1-st channels
	int channels[] = { 0, 1 };
	
	//Histograms
	MatND hist_base;
	MatND hist_half_down;
	MatND hist_test1;
	MatND hist_test2;
	
	//Calculate the histograms for the HSV images
	calcHist( &hsv_base, 1, channels, Mat(), hist_base, 2, histSize, ranges, true, false );
	normalize( hist_base, hist_base, 0, 1, NORM_MINMAX, -1, Mat() );
	
	calcHist( &hsv_half_down, 1, channels, Mat(), hist_half_down, 2, histSize, ranges, true, false );
	normalize( hist_half_down, hist_half_down, 0, 1, NORM_MINMAX, -1, Mat() );
	
	calcHist( &hsv_test1, 1, channels, Mat(), hist_test1, 2, histSize, ranges, true, false );
	normalize( hsv_test1, hsv_test1, 0, 1, NORM_MINMAX, -1, Mat() );
	
	calcHist( &hsv_test2, 1, channels, Mat(), hist_test2, 2, histSize, ranges, true, false );
	normalize( hsv_test2, hsv_test2, 0, 1, NORM_MINMAX, -1, Mat() );
	
	//Apply the histogam comparision methods
	for(int i=0; i<4; i++)
	{
		int compare_method = i;
		double base_base = compareHist( hist_base, hist_base, compare_method );
		double base_half = compareHist( hist_base, hist_half_down, compare_method );
		double base_test1 = compareHist( hist_base, hist_test1, compare_method );
		double base_test2 = compareHist( hist_base, hist_test2, compare_method );
		
		printf( "Method [%d] Perfectr, Base-Half, Base-Test(1), Base-Test(2) : %f, %f, %f, %f \n", i, base_base, base_half, base_test1, base_test2 );
	}
	
	printf( "Done\n" );
 	
	return 0;
}
