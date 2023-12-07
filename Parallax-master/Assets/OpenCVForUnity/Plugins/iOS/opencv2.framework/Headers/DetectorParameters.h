//
// This file is auto-generated. Please don't modify it!
//
#pragma once

#ifdef __cplusplus
//#import "opencv.hpp"
#import "opencv2/aruco.hpp"
#else
#define CV_EXPORTS
#endif

#import <Foundation/Foundation.h>






NS_ASSUME_NONNULL_BEGIN

// C++: class DetectorParameters
/**
 * Parameters for the detectMarker process:
 * - adaptiveThreshWinSizeMin: minimum window size for adaptive thresholding before finding
 * contours (default 3).
 * - adaptiveThreshWinSizeMax: maximum window size for adaptive thresholding before finding
 * contours (default 23).
 * - adaptiveThreshWinSizeStep: increments from adaptiveThreshWinSizeMin to adaptiveThreshWinSizeMax
 * during the thresholding (default 10).
 * - adaptiveThreshConstant: constant for adaptive thresholding before finding contours (default 7)
 * - minMarkerPerimeterRate: determine minimum perimeter for marker contour to be detected. This
 * is defined as a rate respect to the maximum dimension of the input image (default 0.03).
 * - maxMarkerPerimeterRate:  determine maximum perimeter for marker contour to be detected. This
 * is defined as a rate respect to the maximum dimension of the input image (default 4.0).
 * - polygonalApproxAccuracyRate: minimum accuracy during the polygonal approximation process to
 * determine which contours are squares. (default 0.03)
 * - minCornerDistanceRate: minimum distance between corners for detected markers relative to its
 * perimeter (default 0.05)
 * - minDistanceToBorder: minimum distance of any corner to the image border for detected markers
 * (in pixels) (default 3)
 * - minMarkerDistanceRate: minimum mean distance beetween two marker corners to be considered
 * similar, so that the smaller one is removed. The rate is relative to the smaller perimeter
 * of the two markers (default 0.05).
 * - cornerRefinementMethod: corner refinement method. (CORNER_REFINE_NONE, no refinement.
 * CORNER_REFINE_SUBPIX, do subpixel refinement. CORNER_REFINE_CONTOUR use contour-Points,
 * CORNER_REFINE_APRILTAG  use the AprilTag2 approach). (default CORNER_REFINE_NONE)
 * - cornerRefinementWinSize: window size for the corner refinement process (in pixels) (default 5).
 * - cornerRefinementMaxIterations: maximum number of iterations for stop criteria of the corner
 * refinement process (default 30).
 * - cornerRefinementMinAccuracy: minimum error for the stop cristeria of the corner refinement
 * process (default: 0.1)
 * - markerBorderBits: number of bits of the marker border, i.e. marker border width (default 1).
 * - perspectiveRemovePixelPerCell: number of bits (per dimension) for each cell of the marker
 * when removing the perspective (default 4).
 * - perspectiveRemoveIgnoredMarginPerCell: width of the margin of pixels on each cell not
 * considered for the determination of the cell bit. Represents the rate respect to the total
 * size of the cell, i.e. perspectiveRemovePixelPerCell (default 0.13)
 * - maxErroneousBitsInBorderRate: maximum number of accepted erroneous bits in the border (i.e.
 * number of allowed white bits in the border). Represented as a rate respect to the total
 * number of bits per marker (default 0.35).
 * - minOtsuStdDev: minimun standard deviation in pixels values during the decodification step to
 * apply Otsu thresholding (otherwise, all the bits are set to 0 or 1 depending on mean higher
 * than 128 or not) (default 5.0)
 * - errorCorrectionRate error correction rate respect to the maximun error correction capability
 * for each dictionary. (default 0.6).
 * - aprilTagMinClusterPixels: reject quads containing too few pixels. (default 5)
 * - aprilTagMaxNmaxima: how many corner candidates to consider when segmenting a group of pixels into a quad. (default 10)
 * - aprilTagCriticalRad: Reject quads where pairs of edges have angles that are close to straight or close to
 * 180 degrees. Zero means that no quads are rejected. (In radians) (default 10*PI/180)
 * - aprilTagMaxLineFitMse:  When fitting lines to the contours, what is the maximum mean squared error
 * allowed?  This is useful in rejecting contours that are far from being quad shaped; rejecting
 * these quads "early" saves expensive decoding processing. (default 10.0)
 * - aprilTagMinWhiteBlackDiff: When we build our model of black & white pixels, we add an extra check that
 * the white model must be (overall) brighter than the black model.  How much brighter? (in pixel values, [0,255]). (default 5)
 * - aprilTagDeglitch:  should the thresholded image be deglitched? Only useful for very noisy images. (default 0)
 * - aprilTagQuadDecimate: Detection of quads can be done on a lower-resolution image, improving speed at a
 * cost of pose accuracy and a slight decrease in detection rate. Decoding the binary payload is still
 * done at full resolution. (default 0.0)
 * - aprilTagQuadSigma: What Gaussian blur should be applied to the segmented image (used for quad detection?)
 * Parameter is the standard deviation in pixels.  Very noisy images benefit from non-zero values (e.g. 0.8). (default 0.0)
 * - detectInvertedMarker: to check if there is a white marker. In order to generate a "white" marker just
 * invert a normal marker by using a tilde, ~markerImage. (default false)
 *
 * Member of `Aruco`
 */
CV_EXPORTS @interface DetectorParameters : NSObject


#ifdef __cplusplus
@property(readonly)cv::Ptr<cv::aruco::DetectorParameters> nativePtr;
#endif

#ifdef __cplusplus
- (instancetype)initWithNativePtr:(cv::Ptr<cv::aruco::DetectorParameters>)nativePtr;
+ (instancetype)fromNative:(cv::Ptr<cv::aruco::DetectorParameters>)nativePtr;
#endif


#pragma mark - Methods


//
// static Ptr_DetectorParameters cv::aruco::DetectorParameters::create()
//
+ (DetectorParameters*)create NS_SWIFT_NAME(create());


    //
    // C++: int cv::aruco::DetectorParameters::adaptiveThreshWinSizeMin
    //

@property int adaptiveThreshWinSizeMin;

    //
    // C++: int cv::aruco::DetectorParameters::adaptiveThreshWinSizeMax
    //

@property int adaptiveThreshWinSizeMax;

    //
    // C++: int cv::aruco::DetectorParameters::adaptiveThreshWinSizeStep
    //

@property int adaptiveThreshWinSizeStep;

    //
    // C++: double cv::aruco::DetectorParameters::adaptiveThreshConstant
    //

@property double adaptiveThreshConstant;

    //
    // C++: double cv::aruco::DetectorParameters::minMarkerPerimeterRate
    //

@property double minMarkerPerimeterRate;

    //
    // C++: double cv::aruco::DetectorParameters::maxMarkerPerimeterRate
    //

@property double maxMarkerPerimeterRate;

    //
    // C++: double cv::aruco::DetectorParameters::polygonalApproxAccuracyRate
    //

@property double polygonalApproxAccuracyRate;

    //
    // C++: double cv::aruco::DetectorParameters::minCornerDistanceRate
    //

@property double minCornerDistanceRate;

    //
    // C++: int cv::aruco::DetectorParameters::minDistanceToBorder
    //

@property int minDistanceToBorder;

    //
    // C++: double cv::aruco::DetectorParameters::minMarkerDistanceRate
    //

@property double minMarkerDistanceRate;

    //
    // C++: int cv::aruco::DetectorParameters::cornerRefinementMethod
    //

@property int cornerRefinementMethod;

    //
    // C++: int cv::aruco::DetectorParameters::cornerRefinementWinSize
    //

@property int cornerRefinementWinSize;

    //
    // C++: int cv::aruco::DetectorParameters::cornerRefinementMaxIterations
    //

@property int cornerRefinementMaxIterations;

    //
    // C++: double cv::aruco::DetectorParameters::cornerRefinementMinAccuracy
    //

@property double cornerRefinementMinAccuracy;

    //
    // C++: int cv::aruco::DetectorParameters::markerBorderBits
    //

@property int markerBorderBits;

    //
    // C++: int cv::aruco::DetectorParameters::perspectiveRemovePixelPerCell
    //

@property int perspectiveRemovePixelPerCell;

    //
    // C++: double cv::aruco::DetectorParameters::perspectiveRemoveIgnoredMarginPerCell
    //

@property double perspectiveRemoveIgnoredMarginPerCell;

    //
    // C++: double cv::aruco::DetectorParameters::maxErroneousBitsInBorderRate
    //

@property double maxErroneousBitsInBorderRate;

    //
    // C++: double cv::aruco::DetectorParameters::minOtsuStdDev
    //

@property double minOtsuStdDev;

    //
    // C++: double cv::aruco::DetectorParameters::errorCorrectionRate
    //

@property double errorCorrectionRate;

    //
    // C++: float cv::aruco::DetectorParameters::aprilTagQuadDecimate
    //

@property float aprilTagQuadDecimate;

    //
    // C++: float cv::aruco::DetectorParameters::aprilTagQuadSigma
    //

@property float aprilTagQuadSigma;

    //
    // C++: int cv::aruco::DetectorParameters::aprilTagMinClusterPixels
    //

@property int aprilTagMinClusterPixels;

    //
    // C++: int cv::aruco::DetectorParameters::aprilTagMaxNmaxima
    //

@property int aprilTagMaxNmaxima;

    //
    // C++: float cv::aruco::DetectorParameters::aprilTagCriticalRad
    //

@property float aprilTagCriticalRad;

    //
    // C++: float cv::aruco::DetectorParameters::aprilTagMaxLineFitMse
    //

@property float aprilTagMaxLineFitMse;

    //
    // C++: int cv::aruco::DetectorParameters::aprilTagMinWhiteBlackDiff
    //

@property int aprilTagMinWhiteBlackDiff;

    //
    // C++: int cv::aruco::DetectorParameters::aprilTagDeglitch
    //

@property int aprilTagDeglitch;

    //
    // C++: bool cv::aruco::DetectorParameters::detectInvertedMarker
    //

@property BOOL detectInvertedMarker;


@end

NS_ASSUME_NONNULL_END


