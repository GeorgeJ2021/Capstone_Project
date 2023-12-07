//
// This file is auto-generated. Please don't modify it!
//
#pragma once

#ifdef __cplusplus
//#import "opencv.hpp"
#import "opencv2/ximgproc.hpp"
#import "opencv2/ximgproc/edge_drawing.hpp"
#else
#define CV_EXPORTS
#endif

#import <Foundation/Foundation.h>
#import "Algorithm.h"

@class EdgeDrawingParams;
@class Mat;
@class Point2i;


// C++: enum GradientOperator (cv.ximgproc.EdgeDrawing.GradientOperator)
typedef NS_ENUM(int, GradientOperator) {
    PREWITT = 0,
    SOBEL = 1,
    SCHARR = 2,
    LSD = 3
};



NS_ASSUME_NONNULL_BEGIN

// C++: class EdgeDrawing
/**
 * Class implementing the ED (EdgeDrawing) CITE: topal2012edge, EDLines CITE: akinlar2011edlines, EDPF CITE: akinlar2012edpf and EDCircles CITE: akinlar2013edcircles algorithms
 *
 * Member of `Ximgproc`
 */
CV_EXPORTS @interface EdgeDrawing : Algorithm


#ifdef __cplusplus
@property(readonly)cv::Ptr<cv::ximgproc::EdgeDrawing> nativePtrEdgeDrawing;
#endif

#ifdef __cplusplus
- (instancetype)initWithNativePtr:(cv::Ptr<cv::ximgproc::EdgeDrawing>)nativePtr;
+ (instancetype)fromNative:(cv::Ptr<cv::ximgproc::EdgeDrawing>)nativePtr;
#endif


#pragma mark - Methods


//
//  void cv::ximgproc::EdgeDrawing::detectEdges(Mat src)
//
/**
 * Detects edges and prepares them to detect lines and ellipses.
 *
 * @param src input image
 */
- (void)detectEdges:(Mat*)src NS_SWIFT_NAME(detectEdges(src:));


//
//  void cv::ximgproc::EdgeDrawing::getEdgeImage(Mat& dst)
//
- (void)getEdgeImage:(Mat*)dst NS_SWIFT_NAME(getEdgeImage(dst:));


//
//  void cv::ximgproc::EdgeDrawing::getGradientImage(Mat& dst)
//
- (void)getGradientImage:(Mat*)dst NS_SWIFT_NAME(getGradientImage(dst:));


//
//  vector_vector_Point cv::ximgproc::EdgeDrawing::getSegments()
//
- (NSArray<NSArray<Point2i*>*>*)getSegments NS_SWIFT_NAME(getSegments());


//
//  void cv::ximgproc::EdgeDrawing::detectLines(Mat& lines)
//
/**
 * Detects lines.
 *
 * @param lines  output Vec<4f> contains start point and end point of detected lines.
 *     NOTE: you should call detectEdges() method before call this.
 */
- (void)detectLines:(Mat*)lines NS_SWIFT_NAME(detectLines(lines:));


//
//  void cv::ximgproc::EdgeDrawing::detectEllipses(Mat& ellipses)
//
/**
 * Detects circles and ellipses.
 *
 * @param ellipses  output Vec<6d> contains center point and perimeter for circles.
 *     NOTE: you should call detectEdges() method before call this.
 */
- (void)detectEllipses:(Mat*)ellipses NS_SWIFT_NAME(detectEllipses(ellipses:));


//
//  void cv::ximgproc::EdgeDrawing::setParams(EdgeDrawing_Params parameters)
//
/**
 * sets parameters.
 *
 *     this function is meant to be used for parameter setting in other languages than c++.
 */
- (void)setParams:(EdgeDrawingParams*)parameters NS_SWIFT_NAME(setParams(parameters:));



@end

NS_ASSUME_NONNULL_END


