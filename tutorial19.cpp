#include <tutorials.hpp>

int tutorial19( int argc, char** argv )
{
	Mat img = imread( argv[1], CV_LOAD_IMAGE_GRAYSCALE );
	
	int minHessian = 400;
	
	//Detect features using SURF detector
	SurfFeatureDetector detector( minHessian );
	
	std::vector<KeyPoint> keypoints;
	
	detector.detect( img, keypoints );
	
	//Draw keypoints
	Mat img_keypoints;
	
	drawKeypoints( img, keypoints, img_keypoints, Scalar::all(-1), DrawMatchesFlags::DEFAULT );
	
	imshow( "KeyPoints", img_keypoints );
	
	waitKey(0);
	return 0;
}
