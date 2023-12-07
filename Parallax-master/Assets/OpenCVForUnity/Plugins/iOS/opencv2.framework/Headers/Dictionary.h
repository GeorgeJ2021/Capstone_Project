//
// This file is auto-generated. Please don't modify it!
//
#pragma once

#ifdef __cplusplus
//#import "opencv.hpp"
#import "opencv2/aruco.hpp"
#import "aruco/dictionary.hpp"
#import "opencv2/aruco/dictionary.hpp"
#else
#define CV_EXPORTS
#endif

#import <Foundation/Foundation.h>


@class Mat;



NS_ASSUME_NONNULL_BEGIN

// C++: class Dictionary
/**
 * Dictionary/Set of markers. It contains the inner codification
 *
 * bytesList contains the marker codewords where
 * - bytesList.rows is the dictionary size
 * - each marker is encoded using `nbytes = ceil(markerSize*markerSize/8.)`
 * - each row contains all 4 rotations of the marker, so its length is `4*nbytes`
 *
 * `bytesList.ptr(i)[k*nbytes + j]` is then the j-th byte of i-th marker, in its k-th rotation.
 *
 * Member of `Aruco`
 */
CV_EXPORTS @interface Dictionary : NSObject


#ifdef __cplusplus
@property(readonly)cv::Ptr<cv::aruco::Dictionary> nativePtr;
#endif

#ifdef __cplusplus
- (instancetype)initWithNativePtr:(cv::Ptr<cv::aruco::Dictionary>)nativePtr;
+ (instancetype)fromNative:(cv::Ptr<cv::aruco::Dictionary>)nativePtr;
#endif


#pragma mark - Methods


//
// static Ptr_Dictionary cv::aruco::Dictionary::create(int nMarkers, int markerSize, int randomSeed = 0)
//
/**
 * @see `generateCustomDictionary`
 */
+ (Dictionary*)create:(int)nMarkers markerSize:(int)markerSize randomSeed:(int)randomSeed NS_SWIFT_NAME(create(nMarkers:markerSize:randomSeed:));

/**
 * @see `generateCustomDictionary`
 */
+ (Dictionary*)create:(int)nMarkers markerSize:(int)markerSize NS_SWIFT_NAME(create(nMarkers:markerSize:));


//
// static Ptr_Dictionary cv::aruco::Dictionary::create(int nMarkers, int markerSize, Ptr_Dictionary baseDictionary, int randomSeed = 0)
//
/**
 * @see `generateCustomDictionary`
 */
+ (Dictionary*)create_from:(int)nMarkers markerSize:(int)markerSize baseDictionary:(Dictionary*)baseDictionary randomSeed:(int)randomSeed NS_SWIFT_NAME(create(nMarkers:markerSize:baseDictionary:randomSeed:));

/**
 * @see `generateCustomDictionary`
 */
+ (Dictionary*)create_from:(int)nMarkers markerSize:(int)markerSize baseDictionary:(Dictionary*)baseDictionary NS_SWIFT_NAME(create(nMarkers:markerSize:baseDictionary:));


//
// static Ptr_Dictionary cv::aruco::Dictionary::get(int dict)
//
/**
 * @see `getPredefinedDictionary`
 */
+ (Dictionary*)get:(int)dict NS_SWIFT_NAME(get(dict:));


//
//  void cv::aruco::Dictionary::drawMarker(int id, int sidePixels, Mat& _img, int borderBits = 1)
//
/**
 * Draw a canonical marker image
 */
- (void)drawMarker:(int)id sidePixels:(int)sidePixels _img:(Mat*)_img borderBits:(int)borderBits NS_SWIFT_NAME(drawMarker(id:sidePixels:_img:borderBits:));

/**
 * Draw a canonical marker image
 */
- (void)drawMarker:(int)id sidePixels:(int)sidePixels _img:(Mat*)_img NS_SWIFT_NAME(drawMarker(id:sidePixels:_img:));


//
// static Mat cv::aruco::Dictionary::getByteListFromBits(Mat bits)
//
/**
 * Transform matrix of bits to list of bytes in the 4 rotations
 */
+ (Mat*)getByteListFromBits:(Mat*)bits NS_SWIFT_NAME(getByteListFromBits(bits:));


//
// static Mat cv::aruco::Dictionary::getBitsFromByteList(Mat byteList, int markerSize)
//
/**
 * Transform list of bytes to matrix of bits
 */
+ (Mat*)getBitsFromByteList:(Mat*)byteList markerSize:(int)markerSize NS_SWIFT_NAME(getBitsFromByteList(byteList:markerSize:));


    //
    // C++: Mat cv::aruco::Dictionary::bytesList
    //

@property Mat* bytesList;

    //
    // C++: int cv::aruco::Dictionary::markerSize
    //

@property int markerSize;

    //
    // C++: int cv::aruco::Dictionary::maxCorrectionBits
    //

@property int maxCorrectionBits;


@end

NS_ASSUME_NONNULL_END


