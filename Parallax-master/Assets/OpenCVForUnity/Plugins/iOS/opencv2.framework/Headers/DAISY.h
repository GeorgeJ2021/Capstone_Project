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

@class Mat;


// C++: enum NormalizationType (cv.xfeatures2d.DAISY.NormalizationType)
typedef NS_ENUM(int, NormalizationType) {
    NRM_NONE = 100,
    NRM_PARTIAL = 101,
    NRM_FULL = 102,
    NRM_SIFT = 103
};



NS_ASSUME_NONNULL_BEGIN

// C++: class DAISY
/**
 * Class implementing DAISY descriptor, described in CITE: Tola10
 *
 * radius radius of the descriptor at the initial scale
 * q_radius amount of radial range division quantity
 * q_theta amount of angular range division quantity
 * q_hist amount of gradient orientations range division quantity
 * norm choose descriptors normalization type, where
 * DAISY::NRM_NONE will not do any normalization (default),
 * DAISY::NRM_PARTIAL mean that histograms are normalized independently for L2 norm equal to 1.0,
 * DAISY::NRM_FULL mean that descriptors are normalized for L2 norm equal to 1.0,
 * DAISY::NRM_SIFT mean that descriptors are normalized for L2 norm equal to 1.0 but no individual one is bigger than 0.154 as in SIFT
 * H optional 3x3 homography matrix used to warp the grid of daisy but sampling keypoints remains unwarped on image
 * interpolation switch to disable interpolation for speed improvement at minor quality loss
 * use_orientation sample patterns using keypoints orientation, disabled by default.
 *
 * Member of `Xfeatures2d`
 */
CV_EXPORTS @interface DAISY : Feature2D


#ifdef __cplusplus
@property(readonly)cv::Ptr<cv::xfeatures2d::DAISY> nativePtrDAISY;
#endif

#ifdef __cplusplus
- (instancetype)initWithNativePtr:(cv::Ptr<cv::xfeatures2d::DAISY>)nativePtr;
+ (instancetype)fromNative:(cv::Ptr<cv::xfeatures2d::DAISY>)nativePtr;
#endif


#pragma mark - Methods


//
// static Ptr_DAISY cv::xfeatures2d::DAISY::create(float radius = 15, int q_radius = 3, int q_theta = 8, int q_hist = 8, NormalizationType norm = cv::xfeatures2d::DAISY::NRM_NONE, Mat H = Mat(), bool interpolation = true, bool use_orientation = false)
//
+ (DAISY*)create:(float)radius q_radius:(int)q_radius q_theta:(int)q_theta q_hist:(int)q_hist norm:(NormalizationType)norm H:(Mat*)H interpolation:(BOOL)interpolation use_orientation:(BOOL)use_orientation NS_SWIFT_NAME(create(radius:q_radius:q_theta:q_hist:norm:H:interpolation:use_orientation:));

+ (DAISY*)create:(float)radius q_radius:(int)q_radius q_theta:(int)q_theta q_hist:(int)q_hist norm:(NormalizationType)norm H:(Mat*)H interpolation:(BOOL)interpolation NS_SWIFT_NAME(create(radius:q_radius:q_theta:q_hist:norm:H:interpolation:));

+ (DAISY*)create:(float)radius q_radius:(int)q_radius q_theta:(int)q_theta q_hist:(int)q_hist norm:(NormalizationType)norm H:(Mat*)H NS_SWIFT_NAME(create(radius:q_radius:q_theta:q_hist:norm:H:));

+ (DAISY*)create:(float)radius q_radius:(int)q_radius q_theta:(int)q_theta q_hist:(int)q_hist norm:(NormalizationType)norm NS_SWIFT_NAME(create(radius:q_radius:q_theta:q_hist:norm:));

+ (DAISY*)create:(float)radius q_radius:(int)q_radius q_theta:(int)q_theta q_hist:(int)q_hist NS_SWIFT_NAME(create(radius:q_radius:q_theta:q_hist:));

+ (DAISY*)create:(float)radius q_radius:(int)q_radius q_theta:(int)q_theta NS_SWIFT_NAME(create(radius:q_radius:q_theta:));

+ (DAISY*)create:(float)radius q_radius:(int)q_radius NS_SWIFT_NAME(create(radius:q_radius:));

+ (DAISY*)create:(float)radius NS_SWIFT_NAME(create(radius:));

+ (DAISY*)create NS_SWIFT_NAME(create());



@end

NS_ASSUME_NONNULL_END


