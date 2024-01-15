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

// C++: class MSDDetector
/**
 * Class implementing the MSD (*Maximal Self-Dissimilarity*) keypoint detector, described in CITE: Tombari14.
 *
 * The algorithm implements a novel interest point detector stemming from the intuition that image patches
 * which are highly dissimilar over a relatively large extent of their surroundings hold the property of
 * being repeatable and distinctive. This concept of "contextual self-dissimilarity" reverses the key
 * paradigm of recent successful techniques such as the Local Self-Similarity descriptor and the Non-Local
 * Means filter, which build upon the presence of similar - rather than dissimilar - patches. Moreover,
 * it extends to contextual information the local self-dissimilarity notion embedded in established
 * detectors of corner-like interest points, thereby achieving enhanced repeatability, distinctiveness and
 * localization accuracy.
 *
 * Member of `Xfeatures2d`
 */
CV_EXPORTS @interface MSDDetector : Feature2D


#ifdef __cplusplus
@property(readonly)cv::Ptr<cv::xfeatures2d::MSDDetector> nativePtrMSDDetector;
#endif

#ifdef __cplusplus
- (instancetype)initWithNativePtr:(cv::Ptr<cv::xfeatures2d::MSDDetector>)nativePtr;
+ (instancetype)fromNative:(cv::Ptr<cv::xfeatures2d::MSDDetector>)nativePtr;
#endif


#pragma mark - Methods



@end

NS_ASSUME_NONNULL_END


