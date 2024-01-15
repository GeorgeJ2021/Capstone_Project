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


@class Dictionary;
@class IntVector;
@class Mat;
@class Point3f;



NS_ASSUME_NONNULL_BEGIN

// C++: class Board
/**
 * Board of markers
 *
 * A board is a set of markers in the 3D space with a common coordinate system.
 * The common form of a board of marker is a planar (2D) board, however any 3D layout can be used.
 * A Board object is composed by:
 * - The object points of the marker corners, i.e. their coordinates respect to the board system.
 * - The dictionary which indicates the type of markers of the board
 * - The identifier of all the markers in the board.
 *
 * Member of `Aruco`
 */
CV_EXPORTS @interface Board : NSObject


#ifdef __cplusplus
@property(readonly)cv::Ptr<cv::aruco::Board> nativePtr;
#endif

#ifdef __cplusplus
- (instancetype)initWithNativePtr:(cv::Ptr<cv::aruco::Board>)nativePtr;
+ (instancetype)fromNative:(cv::Ptr<cv::aruco::Board>)nativePtr;
#endif


#pragma mark - Methods


//
// static Ptr_Board cv::aruco::Board::create(vector_Mat objPoints, Ptr_Dictionary dictionary, Mat ids)
//
/**
 * Provide way to create Board by passing necessary data. Specially needed in Python.
 *
 * @param objPoints array of object points of all the marker corners in the board
 * @param dictionary the dictionary of markers employed for this board
 * @param ids vector of the identifiers of the markers in the board
 *
 */
+ (Board*)create:(NSArray<Mat*>*)objPoints dictionary:(Dictionary*)dictionary ids:(Mat*)ids NS_SWIFT_NAME(create(objPoints:dictionary:ids:));


//
//  void cv::aruco::Board::setIds(Mat ids)
//
/**
 * Set ids vector
 *
 * @param ids vector of the identifiers of the markers in the board (should be the same size
 * as objPoints)
 *
 * Recommended way to set ids vector, which will fail if the size of ids does not match size
 * of objPoints.
 */
- (void)setIdsMat:(Mat*)ids NS_SWIFT_NAME(setIds(ids:));


    //
    // C++: vector_vector_Point3f cv::aruco::Board::objPoints
    //

@property (readonly) Point3f* objPoints;

    //
    // C++: Ptr_Dictionary cv::aruco::Board::dictionary
    //

@property (readonly) Dictionary* dictionary;

    //
    // C++: vector_int cv::aruco::Board::ids
    //

@property IntVector* ids;


@end

NS_ASSUME_NONNULL_END


