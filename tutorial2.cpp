#include <tutorials.hpp>

char source_window[] = "Source image";
char warp_window[] = "Warp";
char warp_rotate_window[] = "Warp + Rotate";

int tutorial2(int argc, char** argv)
{
	Point2f srcTri[3];
	Point2f dstTri[3];
	
	Mat rot_mat( 2, 3, CV_32FC1 );
	Mat warp_mat( 2, 3, CV_32FC1 );
	Mat src, warp_dst, warp_rotate_dst;
	
	//load the image
	src = imread( argv[1], 1 );
	
	warp_dst = Mat::zeros( src.rows, src.cols, src.type() );
	
	//Set the 3 points to calculate the Affine Transformation
	srcTri[0] = Point2f( 0, 0 );
	srcTri[1] = Point2f( src.cols-1, 0 );
	srcTri[2] = Point2f( 0, src.rows-1 );
	
	dstTri[0] = Point2f( src.cols*0.0, src.rows*0.33 );
	dstTri[1] = Point2f( src.cols*0.85, src.rows*0.25 );
	dstTri[2] = Point2f( src.cols*0.15, src.rows*0.7 );
	
	//Get Affine Transform
	warp_mat = getAffineTransform( srcTri, dstTri );
	
	//Apply the Affine Transformationjust found to the src image
	warpAffine( src, warp_dst, warp_mat, warp_dst.size() );
	
	//Rotating the image after transform
	//compute a rotation matrix WRT the center of the image
	Point center = Point( warp_dst.cols/2, warp_dst.rows/2 );
	double angle = -50.0;
	double scale = 0.6;
	
	//Get the rotation matrix with the above parameters
	rot_mat = getRotationMatrix2D( center, angle, scale );
	
	//Rotate the warped image
	warpAffine( warp_dst, warp_rotate_dst, rot_mat, warp_dst.size() );
	
	//Show what you got
	namedWindow( source_window, CV_WINDOW_AUTOSIZE );
	imshow( source_window, src );
	
	namedWindow( warp_window, CV_WINDOW_AUTOSIZE );
	imshow( warp_window, warp_dst );
	
	namedWindow( warp_rotate_window, CV_WINDOW_AUTOSIZE );
	imshow( warp_rotate_window, warp_rotate_dst );
	
	waitKey(0);
		
	return 0;
}
