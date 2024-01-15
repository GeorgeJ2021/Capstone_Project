//
// This file is auto-generated. Please don't modify it!
//
#pragma once

#ifdef __cplusplus
//#import "opencv.hpp"
#import "opencv2/xfeatures2d.hpp"
#else
#define CV_EXPORTS
#endif

#import <Foundation/Foundation.h>
#import "Feature2D.h"





NS_ASSUME_NONNULL_BEGIN

// C++: class LATCH
/**
 * latch Class for computing the LATCH descriptor.
 * If you find this code useful, please add a reference to the following paper in your work:
 * Gil Levi and Tal Hassner, "LATCH: Learned Arrangements of Three Patch Codes", arXiv preprint arXiv:1501.03719, 15 Jan. 2015
 *
 * LATCH is a binary descriptor based on learned comparisons of triplets of image patches.
 *
 * bytes is the size of the descriptor - can be 64, 32, 16, 8, 4, 2 or 1
 * rotationInvariance - whether or not the descriptor should compansate for orientation changes.
 * half_ssd_size - the size of half of the mini-patches size. For example, if we would like to compare triplets of patches of size 7x7x
 *     then the half_ssd_size should be (7-1)/2 = 3.
 * sigma - sigma value for GaussianBlur smoothing of the source image. Source image will be used without smoothing in case sigma value is 0.
 *
 * Note: the descriptor can be coupled with any keypoint extractor. The only demand is that if you use set rotationInvariance = True then
 *     you will have to use an extractor which estimates the patch orientation (in degrees). Examples for such extractors are ORB and SIFT.
 *
 * Note: a complete example can be found under /samples/cpp/tutorial_code/xfeatures2D/latch_match.cpp
 *
 * Member of `Xfeatures2d`
 */
CV_EXPORTS @interface LATCH : Feature2D


#ifdef __cplusplus
@property(readonly)cv::Ptr<cv::xfeatures2d::LATCH> nativePtrLATCH;
#endif

#ifdef __cplusplus
- (instancetype)initWithNativePtr:(cv::Ptr<cv::xfeatures2d::LATCH>)nativePtr;
+ (instancetype)fromNative:(cv::Ptr<cv::xfeatures2d::LATCH>)nativePtr;
#endif


#pragma mark - Methods


//
// static Ptr_LATCH cv::xfeatures2d::LATCH::create(int bytes = 32, bool rotationInvariance = true, int half_ssd_size = 3, double sigma = 2.0)
//
+ (LATCH*)create:(int)bytes rotationInvariance:(BOOL)rotationInvariance half_ssd_size:(int)half_ssd_size sigma:(double)sigma NS_SWIFT_NAME(create(bytes:rotationInvariance:half_ssd_size:sigma:));

+ (LATCH*)create:(int)bytes rotationInvariance:(BOOL)rotationInvariance half_ssd_size:(int)half_ssd_size NS_SWIFT_NAME(create(bytes:rotationInvariance:half_ssd_size:));

+ (LATCH*)create:(int)bytes rotationInvariance:(BOOL)rotationInvariance NS_SWIFT_NAME(create(bytes:rotationInvariance:));

+ (LATCH*)create:(int)bytes NS_SWIFT_NAME(create(bytes:));

+ (LATCH*)create NS_SWIFT_NAME(create());



@end

NS_ASSUME_NONNULL_END


