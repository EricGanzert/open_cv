#ifndef TUTORIALS_H
#define TUTORIALS_H

#include "main.hpp"
#include <dirent.h>

using namespace cv;

//remapping
int tutorial1( int argc, char** argv );
void update_map( void );

//affine transformations
//warpAffine, getRotationMatrix2D
int tutorial2( int argc, char** argv );

//histogram equalization
int tutorial3( int argc, char** argv );

//Histogram calculation
int tutorial4( int argc, char** argv );

//Histogram comparison
int tutorial5( int argc, char** argv );

//Back Projection
int tutorial6( int argc, char** argv );
void Hist_and_Backproj( int, void* );

//Template Matching
int tutorial7( int argc, char** argv );
void MatchingMethod( int, void* );

//smoothing, sharpening, edge detection
int tutorial8( int argc, char** argv );
void CannyThreshold( int, void* );

//finding the contours of an image
int tutorial9( int argc, char** argv );
void thresh_callback( int, void* );

//convex hull
int tutorial10( int argc, char** argv );
void thresh_callback( int, void* );

//bounding boxes and circles for contours
int tutorial11( int argc, char** argv );
void thresh_callback( int, void* );

//Image moments, contour arclength, contour area
int tutorial12( int argc, char** argv );
void thresh_callback( int, void* );

//experiment with thresholding the image of the docking target at close range
//to create a sharper image for HoughCircleDetection. The problem im solving is that when at close range (less than 2 meters) the 
//the screen nearby the LED lights appears illuminated making circle detection ineffective
int tutorial13( int argc, char** argv );
void hough_callback( int, void* );
void canny_callback( int, void* );

//image moments
int tutorial14( int argc, char** argv );

//calculate distance from the image to contours
int tutorial15( int argc, char** argv );

//HighGui: Trackbar application
int tutorial16( int argc, char** argv );
void on_trackbar( int, void* );

//2D features: Harris corner detector
int tutorial17( int argc, char** argv );
void cornerHarris_demo( int, void* );

//2D features: Shi Tomasi corner detector using goodFeaturesToTrack
int tutorial18( int argc, char** argv );
void goodFeaturesToTrack_Demo( int, void* );

//2D features: Feature Detection using SurfFeatureDetector, drawKeyPoints
int tutorial19( int argc, char** argv );

int lightDetection( int argc, char** argv );

#endif //TUTORIALS_H
