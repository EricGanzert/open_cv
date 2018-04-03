#ifndef TUTORIALS_H
#define TUTORIALS_H

#include "main.hpp"
#include <dirent.h>

using namespace cv;

<<<<<<< HEAD
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
=======
int tutorial(int argc, char** argv);
>>>>>>> e1de05cab382980a2ed55ddb605bce1e31e8b2b1

#endif //TUTORIALS_H
