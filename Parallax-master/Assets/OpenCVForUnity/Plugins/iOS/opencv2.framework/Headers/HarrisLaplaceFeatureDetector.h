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

// C++: class HarrisLaplaceFeatureDetector
/**
 * Class implementing the Harris-Laplace feature detector as described in CITE: Mikolajczyk2004.
 *
 * Member of `Xfeatures2d`
 */
CV_EXPORTS @interface HarrisLaplaceFeatureDetector : Feature2D


#ifdef __cplusplus
@property(readonly)cv::Ptr<cv::xfeatures2d::HarrisLaplaceFeatureDetector> nativePtrHarrisLaplaceFeatureDetector;
#endif

#ifdef __cplusplus
- (instancetype)initWithNativePtr:(cv::Ptr<cv::xfeatures2d::HarrisLaplaceFeatureDetector>)nativePtr;
+ (instancetype)fromNative:(cv::Ptr<cv::xfeatures2d::HarrisLaplaceFeatureDetector>)nativePtr;
#endif


#pragma mark - Methods


//
// static Ptr_HarrisLaplaceFeatureDetector cv::xfeatures2d::HarrisLaplaceFeatureDetector::create(int numOctaves = 6, float corn_thresh = 0.01f, float DOG_thresh = 0.01f, int maxCorners = 5000, int num_layers = 4)
//
/**
 * Creates a new implementation instance.
 *
 * @param numOctaves the number of octaves in the scale-space pyramid
 * @param corn_thresh the threshold for the Harris cornerness measure
 * @param DOG_thresh the threshold for the Difference-of-Gaussians scale selection
 * @param maxCorners the maximum number of corners to consider
 * @param num_layers the number of intermediate scales per octave
 */
+ (HarrisLaplaceFeatureDetector*)create:(int)numOctaves corn_thresh:(float)corn_thresh DOG_thresh:(float)DOG_thresh maxCorners:(int)maxCorners num_layers:(int)num_layers NS_SWIFT_NAME(create(numOctaves:corn_thresh:DOG_thresh:maxCorners:num_layers:));

/**
 * Creates a new implementation instance.
 *
 * @param numOctaves the number of octaves in the scale-space pyramid
 * @param corn_thresh the threshold for the Harris cornerness measure
 * @param DOG_thresh the threshold for the Difference-of-Gaussians scale selection
 * @param maxCorners the maximum number of corners to consider
 */
+ (HarrisLaplaceFeatureDetector*)create:(int)numOctaves corn_thresh:(float)corn_thresh DOG_thresh:(float)DOG_thresh maxCorners:(int)maxCorners NS_SWIFT_NAME(create(numOctaves:corn_thresh:DOG_thresh:maxCorners:));

/**
 * Creates a new implementation instance.
 *
 * @param numOctaves the number of octaves in the scale-space pyramid
 * @param corn_thresh the threshold for the Harris cornerness measure
 * @param DOG_thresh the threshold for the Difference-of-Gaussians scale selection
 */
+ (HarrisLaplaceFeatureDetector*)create:(int)numOctaves corn_thresh:(float)corn_thresh DOG_thresh:(float)DOG_thresh NS_SWIFT_NAME(create(numOctaves:corn_thresh:DOG_thresh:));

/**
 * Creates a new implementation instance.
 *
 * @param numOctaves the number of octaves in the scale-space pyramid
 * @param corn_thresh the threshold for the Harris cornerness measure
 */
+ (HarrisLaplaceFeatureDetector*)create:(int)numOctaves corn_thresh:(float)corn_thresh NS_SWIFT_NAME(create(numOctaves:corn_thresh:));

/**
 * Creates a new implementation instance.
 *
 * @param numOctaves the number of octaves in the scale-space pyramid
 */
+ (HarrisLaplaceFeatureDetector*)create:(int)numOctaves NS_SWIFT_NAME(create(numOctaves:));

/**
 * Creates a new implementation instance.
 *
 */
+ (HarrisLaplaceFeatureDetector*)create NS_SWIFT_NAME(create());



@end

NS_ASSUME_NONNULL_END


