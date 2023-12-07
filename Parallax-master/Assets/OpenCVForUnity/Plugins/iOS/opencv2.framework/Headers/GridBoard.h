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
#import "Board.h"

@class Dictionary;
@class Mat;
@class Size2i;



NS_ASSUME_NONNULL_BEGIN

// C++: class GridBoard
/**
 * Planar board with grid arrangement of markers
 * More common type of board. All markers are placed in the same plane in a grid arrangement.
 * The board can be drawn using drawPlanarBoard() function (@see drawPlanarBoard)
 *
 * Member of `Aruco`
 */
CV_EXPORTS @interface GridBoard : Board


#ifdef __cplusplus
@property(readonly)cv::Ptr<cv::aruco::GridBoard> nativePtrGridBoard;
#endif

#ifdef __cplusplus
- (instancetype)initWithNativePtr:(cv::Ptr<cv::aruco::GridBoard>)nativePtr;
+ (instancetype)fromNative:(cv::Ptr<cv::aruco::GridBoard>)nativePtr;
#endif


#pragma mark - Methods


//
//  void cv::aruco::GridBoard::draw(Size outSize, Mat& img, int marginSize = 0, int borderBits = 1)
//
/**
 * Draw a GridBoard
 *
 * @param outSize size of the output image in pixels.
 * @param img output image with the board. The size of this image will be outSize
 * and the board will be on the center, keeping the board proportions.
 * @param marginSize minimum margins (in pixels) of the board in the output image
 * @param borderBits width of the marker borders.
 *
 * This function return the image of the GridBoard, ready to be printed.
 */
- (void)draw:(Size2i*)outSize img:(Mat*)img marginSize:(int)marginSize borderBits:(int)borderBits NS_SWIFT_NAME(draw(outSize:img:marginSize:borderBits:));

/**
 * Draw a GridBoard
 *
 * @param outSize size of the output image in pixels.
 * @param img output image with the board. The size of this image will be outSize
 * and the board will be on the center, keeping the board proportions.
 * @param marginSize minimum margins (in pixels) of the board in the output image
 *
 * This function return the image of the GridBoard, ready to be printed.
 */
- (void)draw:(Size2i*)outSize img:(Mat*)img marginSize:(int)marginSize NS_SWIFT_NAME(draw(outSize:img:marginSize:));

/**
 * Draw a GridBoard
 *
 * @param outSize size of the output image in pixels.
 * @param img output image with the board. The size of this image will be outSize
 * and the board will be on the center, keeping the board proportions.
 *
 * This function return the image of the GridBoard, ready to be printed.
 */
- (void)draw:(Size2i*)outSize img:(Mat*)img NS_SWIFT_NAME(draw(outSize:img:));


//
// static Ptr_GridBoard cv::aruco::GridBoard::create(int markersX, int markersY, float markerLength, float markerSeparation, Ptr_Dictionary dictionary, int firstMarker = 0)
//
/**
 * Create a GridBoard object
 *
 * @param markersX number of markers in X direction
 * @param markersY number of markers in Y direction
 * @param markerLength marker side length (normally in meters)
 * @param markerSeparation separation between two markers (same unit as markerLength)
 * @param dictionary dictionary of markers indicating the type of markers
 * @param firstMarker id of first marker in dictionary to use on board.
 * @return the output GridBoard object
 *
 * This functions creates a GridBoard object given the number of markers in each direction and
 * the marker size and marker separation.
 */
+ (GridBoard*)create:(int)markersX markersY:(int)markersY markerLength:(float)markerLength markerSeparation:(float)markerSeparation dictionary:(Dictionary*)dictionary firstMarker:(int)firstMarker NS_SWIFT_NAME(create(markersX:markersY:markerLength:markerSeparation:dictionary:firstMarker:));

/**
 * Create a GridBoard object
 *
 * @param markersX number of markers in X direction
 * @param markersY number of markers in Y direction
 * @param markerLength marker side length (normally in meters)
 * @param markerSeparation separation between two markers (same unit as markerLength)
 * @param dictionary dictionary of markers indicating the type of markers
 * @return the output GridBoard object
 *
 * This functions creates a GridBoard object given the number of markers in each direction and
 * the marker size and marker separation.
 */
+ (GridBoard*)create:(int)markersX markersY:(int)markersY markerLength:(float)markerLength markerSeparation:(float)markerSeparation dictionary:(Dictionary*)dictionary NS_SWIFT_NAME(create(markersX:markersY:markerLength:markerSeparation:dictionary:));


//
//  Size cv::aruco::GridBoard::getGridSize()
//
- (Size2i*)getGridSize NS_SWIFT_NAME(getGridSize());


//
//  float cv::aruco::GridBoard::getMarkerLength()
//
- (float)getMarkerLength NS_SWIFT_NAME(getMarkerLength());


//
//  float cv::aruco::GridBoard::getMarkerSeparation()
//
- (float)getMarkerSeparation NS_SWIFT_NAME(getMarkerSeparation());



@end

NS_ASSUME_NONNULL_END


