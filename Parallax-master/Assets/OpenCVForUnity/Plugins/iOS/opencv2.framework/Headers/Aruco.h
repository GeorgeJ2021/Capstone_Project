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

@class Board;
@class CharucoBoard;
@class DetectorParameters;
@class Dictionary;
@class Int4;
@class Mat;
@class Scalar;
@class Size2i;
@class TermCriteria;


// C++: enum CornerRefineMethod (cv.aruco.CornerRefineMethod)
typedef NS_ENUM(int, CornerRefineMethod) {
    CORNER_REFINE_NONE = 0,
    CORNER_REFINE_SUBPIX = 1,
    CORNER_REFINE_CONTOUR = 2,
    CORNER_REFINE_APRILTAG = 3
};


// C++: enum PREDEFINED_DICTIONARY_NAME (cv.aruco.PREDEFINED_DICTIONARY_NAME)
typedef NS_ENUM(int, PREDEFINED_DICTIONARY_NAME) {
    DICT_4X4_50 = 0,
    DICT_4X4_100 = 0+1,
    DICT_4X4_250 = 0+2,
    DICT_4X4_1000 = 0+3,
    DICT_5X5_50 = 0+4,
    DICT_5X5_100 = 0+5,
    DICT_5X5_250 = 0+6,
    DICT_5X5_1000 = 0+7,
    DICT_6X6_50 = 0+8,
    DICT_6X6_100 = 0+9,
    DICT_6X6_250 = 0+10,
    DICT_6X6_1000 = 0+11,
    DICT_7X7_50 = 0+12,
    DICT_7X7_100 = 0+13,
    DICT_7X7_250 = 0+14,
    DICT_7X7_1000 = 0+15,
    DICT_ARUCO_ORIGINAL = 0+16,
    DICT_APRILTAG_16h5 = 0+17,
    DICT_APRILTAG_25h9 = 0+18,
    DICT_APRILTAG_36h10 = 0+19,
    DICT_APRILTAG_36h11 = 0+20
};



NS_ASSUME_NONNULL_BEGIN

// C++: class Aruco
/**
 * The Aruco module
 *
 * Member classes: `DetectorParameters`, `Board`, `GridBoard`, `Dictionary`, `CharucoBoard`
 *
 * Member enums: `CornerRefineMethod`, `PREDEFINED_DICTIONARY_NAME`
 */
CV_EXPORTS @interface Aruco : NSObject

#pragma mark - Methods


//
//  void cv::aruco::detectMarkers(Mat image, Ptr_Dictionary dictionary, vector_Mat& corners, Mat& ids, Ptr_DetectorParameters parameters = DetectorParameters::create(), vector_Mat& rejectedImgPoints = vector_Mat(), Mat cameraMatrix = Mat(), Mat distCoeff = Mat())
//
/**
 * Basic marker detection
 *
 * @param image input image
 * @param dictionary indicates the type of markers that will be searched
 * @param corners vector of detected marker corners. For each marker, its four corners
 * are provided, (e.g std::vector<std::vector<cv::Point2f> > ). For N detected markers,
 * the dimensions of this array is Nx4. The order of the corners is clockwise.
 * @param ids vector of identifiers of the detected markers. The identifier is of type int
 * (e.g. std::vector<int>). For N detected markers, the size of ids is also N.
 * The identifiers have the same order than the markers in the imgPoints array.
 * @param parameters marker detection parameters
 * @param rejectedImgPoints contains the imgPoints of those squares whose inner code has not a
 * correct codification. Useful for debugging purposes.
 * @param cameraMatrix optional input 3x3 floating-point camera matrix
 * `$$\newcommand{\vecthreethree}[9]{ \begin{bmatrix} #1 & #2 & #3\\\\ #4 & #5 & #6\\\\ #7 & #8 & #9 \end{bmatrix} } A = \vecthreethree{f_x}{0}{c_x}{0}{f_y}{c_y}{0}{0}{1}$$`
 * @param distCoeff optional vector of distortion coefficients
 * `$$(k_1, k_2, p_1, p_2[, k_3[, k_4, k_5, k_6],[s_1, s_2, s_3, s_4]])$$` of 4, 5, 8 or 12 elements
 *
 * Performs marker detection in the input image. Only markers included in the specific dictionary
 * are searched. For each detected marker, it returns the 2D position of its corner in the image
 * and its corresponding identifier.
 * Note that this function does not perform pose estimation.
 * @see `+estimatePoseSingleMarkers:markerLength:cameraMatrix:distCoeffs:rvecs:tvecs:_objPoints:`, `+estimatePoseBoard:ids:board:cameraMatrix:distCoeffs:rvec:tvec:useExtrinsicGuess:`
 *
 */
+ (void)detectMarkers:(Mat*)image dictionary:(Dictionary*)dictionary corners:(NSMutableArray<Mat*>*)corners ids:(Mat*)ids parameters:(DetectorParameters*)parameters rejectedImgPoints:(NSMutableArray<Mat*>*)rejectedImgPoints cameraMatrix:(Mat*)cameraMatrix distCoeff:(Mat*)distCoeff NS_SWIFT_NAME(detectMarkers(image:dictionary:corners:ids:parameters:rejectedImgPoints:cameraMatrix:distCoeff:));

/**
 * Basic marker detection
 *
 * @param image input image
 * @param dictionary indicates the type of markers that will be searched
 * @param corners vector of detected marker corners. For each marker, its four corners
 * are provided, (e.g std::vector<std::vector<cv::Point2f> > ). For N detected markers,
 * the dimensions of this array is Nx4. The order of the corners is clockwise.
 * @param ids vector of identifiers of the detected markers. The identifier is of type int
 * (e.g. std::vector<int>). For N detected markers, the size of ids is also N.
 * The identifiers have the same order than the markers in the imgPoints array.
 * @param parameters marker detection parameters
 * @param rejectedImgPoints contains the imgPoints of those squares whose inner code has not a
 * correct codification. Useful for debugging purposes.
 * @param cameraMatrix optional input 3x3 floating-point camera matrix
 * `$$\newcommand{\vecthreethree}[9]{ \begin{bmatrix} #1 & #2 & #3\\\\ #4 & #5 & #6\\\\ #7 & #8 & #9 \end{bmatrix} } A = \vecthreethree{f_x}{0}{c_x}{0}{f_y}{c_y}{0}{0}{1}$$`
 * `$$(k_1, k_2, p_1, p_2[, k_3[, k_4, k_5, k_6],[s_1, s_2, s_3, s_4]])$$` of 4, 5, 8 or 12 elements
 *
 * Performs marker detection in the input image. Only markers included in the specific dictionary
 * are searched. For each detected marker, it returns the 2D position of its corner in the image
 * and its corresponding identifier.
 * Note that this function does not perform pose estimation.
 * @see `+estimatePoseSingleMarkers:markerLength:cameraMatrix:distCoeffs:rvecs:tvecs:_objPoints:`, `+estimatePoseBoard:ids:board:cameraMatrix:distCoeffs:rvec:tvec:useExtrinsicGuess:`
 *
 */
+ (void)detectMarkers:(Mat*)image dictionary:(Dictionary*)dictionary corners:(NSMutableArray<Mat*>*)corners ids:(Mat*)ids parameters:(DetectorParameters*)parameters rejectedImgPoints:(NSMutableArray<Mat*>*)rejectedImgPoints cameraMatrix:(Mat*)cameraMatrix NS_SWIFT_NAME(detectMarkers(image:dictionary:corners:ids:parameters:rejectedImgPoints:cameraMatrix:));

/**
 * Basic marker detection
 *
 * @param image input image
 * @param dictionary indicates the type of markers that will be searched
 * @param corners vector of detected marker corners. For each marker, its four corners
 * are provided, (e.g std::vector<std::vector<cv::Point2f> > ). For N detected markers,
 * the dimensions of this array is Nx4. The order of the corners is clockwise.
 * @param ids vector of identifiers of the detected markers. The identifier is of type int
 * (e.g. std::vector<int>). For N detected markers, the size of ids is also N.
 * The identifiers have the same order than the markers in the imgPoints array.
 * @param parameters marker detection parameters
 * @param rejectedImgPoints contains the imgPoints of those squares whose inner code has not a
 * correct codification. Useful for debugging purposes.
 * `$$\newcommand{\vecthreethree}[9]{ \begin{bmatrix} #1 & #2 & #3\\\\ #4 & #5 & #6\\\\ #7 & #8 & #9 \end{bmatrix} } A = \vecthreethree{f_x}{0}{c_x}{0}{f_y}{c_y}{0}{0}{1}$$`
 * `$$(k_1, k_2, p_1, p_2[, k_3[, k_4, k_5, k_6],[s_1, s_2, s_3, s_4]])$$` of 4, 5, 8 or 12 elements
 *
 * Performs marker detection in the input image. Only markers included in the specific dictionary
 * are searched. For each detected marker, it returns the 2D position of its corner in the image
 * and its corresponding identifier.
 * Note that this function does not perform pose estimation.
 * @see `+estimatePoseSingleMarkers:markerLength:cameraMatrix:distCoeffs:rvecs:tvecs:_objPoints:`, `+estimatePoseBoard:ids:board:cameraMatrix:distCoeffs:rvec:tvec:useExtrinsicGuess:`
 *
 */
+ (void)detectMarkers:(Mat*)image dictionary:(Dictionary*)dictionary corners:(NSMutableArray<Mat*>*)corners ids:(Mat*)ids parameters:(DetectorParameters*)parameters rejectedImgPoints:(NSMutableArray<Mat*>*)rejectedImgPoints NS_SWIFT_NAME(detectMarkers(image:dictionary:corners:ids:parameters:rejectedImgPoints:));

/**
 * Basic marker detection
 *
 * @param image input image
 * @param dictionary indicates the type of markers that will be searched
 * @param corners vector of detected marker corners. For each marker, its four corners
 * are provided, (e.g std::vector<std::vector<cv::Point2f> > ). For N detected markers,
 * the dimensions of this array is Nx4. The order of the corners is clockwise.
 * @param ids vector of identifiers of the detected markers. The identifier is of type int
 * (e.g. std::vector<int>). For N detected markers, the size of ids is also N.
 * The identifiers have the same order than the markers in the imgPoints array.
 * @param parameters marker detection parameters
 * correct codification. Useful for debugging purposes.
 * `$$\newcommand{\vecthreethree}[9]{ \begin{bmatrix} #1 & #2 & #3\\\\ #4 & #5 & #6\\\\ #7 & #8 & #9 \end{bmatrix} } A = \vecthreethree{f_x}{0}{c_x}{0}{f_y}{c_y}{0}{0}{1}$$`
 * `$$(k_1, k_2, p_1, p_2[, k_3[, k_4, k_5, k_6],[s_1, s_2, s_3, s_4]])$$` of 4, 5, 8 or 12 elements
 *
 * Performs marker detection in the input image. Only markers included in the specific dictionary
 * are searched. For each detected marker, it returns the 2D position of its corner in the image
 * and its corresponding identifier.
 * Note that this function does not perform pose estimation.
 * @see `+estimatePoseSingleMarkers:markerLength:cameraMatrix:distCoeffs:rvecs:tvecs:_objPoints:`, `+estimatePoseBoard:ids:board:cameraMatrix:distCoeffs:rvec:tvec:useExtrinsicGuess:`
 *
 */
+ (void)detectMarkers:(Mat*)image dictionary:(Dictionary*)dictionary corners:(NSMutableArray<Mat*>*)corners ids:(Mat*)ids parameters:(DetectorParameters*)parameters NS_SWIFT_NAME(detectMarkers(image:dictionary:corners:ids:parameters:));

/**
 * Basic marker detection
 *
 * @param image input image
 * @param dictionary indicates the type of markers that will be searched
 * @param corners vector of detected marker corners. For each marker, its four corners
 * are provided, (e.g std::vector<std::vector<cv::Point2f> > ). For N detected markers,
 * the dimensions of this array is Nx4. The order of the corners is clockwise.
 * @param ids vector of identifiers of the detected markers. The identifier is of type int
 * (e.g. std::vector<int>). For N detected markers, the size of ids is also N.
 * The identifiers have the same order than the markers in the imgPoints array.
 * correct codification. Useful for debugging purposes.
 * `$$\newcommand{\vecthreethree}[9]{ \begin{bmatrix} #1 & #2 & #3\\\\ #4 & #5 & #6\\\\ #7 & #8 & #9 \end{bmatrix} } A = \vecthreethree{f_x}{0}{c_x}{0}{f_y}{c_y}{0}{0}{1}$$`
 * `$$(k_1, k_2, p_1, p_2[, k_3[, k_4, k_5, k_6],[s_1, s_2, s_3, s_4]])$$` of 4, 5, 8 or 12 elements
 *
 * Performs marker detection in the input image. Only markers included in the specific dictionary
 * are searched. For each detected marker, it returns the 2D position of its corner in the image
 * and its corresponding identifier.
 * Note that this function does not perform pose estimation.
 * @see `+estimatePoseSingleMarkers:markerLength:cameraMatrix:distCoeffs:rvecs:tvecs:_objPoints:`, `+estimatePoseBoard:ids:board:cameraMatrix:distCoeffs:rvec:tvec:useExtrinsicGuess:`
 *
 */
+ (void)detectMarkers:(Mat*)image dictionary:(Dictionary*)dictionary corners:(NSMutableArray<Mat*>*)corners ids:(Mat*)ids NS_SWIFT_NAME(detectMarkers(image:dictionary:corners:ids:));


//
//  void cv::aruco::estimatePoseSingleMarkers(vector_Mat corners, float markerLength, Mat cameraMatrix, Mat distCoeffs, Mat& rvecs, Mat& tvecs, Mat& _objPoints = Mat())
//
/**
 * Pose estimation for single markers
 *
 * @param corners vector of already detected markers corners. For each marker, its four corners
 * are provided, (e.g std::vector<std::vector<cv::Point2f> > ). For N detected markers,
 * the dimensions of this array should be Nx4. The order of the corners should be clockwise.
 * @see `+detectMarkers:dictionary:corners:ids:parameters:rejectedImgPoints:cameraMatrix:distCoeff:`
 * @param markerLength the length of the markers' side. The returning translation vectors will
 * be in the same unit. Normally, unit is meters.
 * @param cameraMatrix input 3x3 floating-point camera matrix
 * `$$\newcommand{\vecthreethree}[9]{ \begin{bmatrix} #1 & #2 & #3\\\\ #4 & #5 & #6\\\\ #7 & #8 & #9 \end{bmatrix} } A = \vecthreethree{f_x}{0}{c_x}{0}{f_y}{c_y}{0}{0}{1}$$`
 * @param distCoeffs vector of distortion coefficients
 * `$$(k_1, k_2, p_1, p_2[, k_3[, k_4, k_5, k_6],[s_1, s_2, s_3, s_4]])$$` of 4, 5, 8 or 12 elements
 * @param rvecs array of output rotation vectors (@see Rodrigues) (e.g. std::vector<cv::Vec3d>).
 * Each element in rvecs corresponds to the specific marker in imgPoints.
 * @param tvecs array of output translation vectors (e.g. std::vector<cv::Vec3d>).
 * Each element in tvecs corresponds to the specific marker in imgPoints.
 * @param _objPoints array of object points of all the marker corners
 *
 * This function receives the detected markers and returns their pose estimation respect to
 * the camera individually. So for each marker, one rotation and translation vector is returned.
 * The returned transformation is the one that transforms points from each marker coordinate system
 * to the camera coordinate system.
 * The marker corrdinate system is centered on the middle of the marker, with the Z axis
 * perpendicular to the marker plane.
 * The coordinates of the four corners of the marker in its own coordinate system are:
 * (-markerLength/2, markerLength/2, 0), (markerLength/2, markerLength/2, 0),
 * (markerLength/2, -markerLength/2, 0), (-markerLength/2, -markerLength/2, 0)
 */
+ (void)estimatePoseSingleMarkers:(NSArray<Mat*>*)corners markerLength:(float)markerLength cameraMatrix:(Mat*)cameraMatrix distCoeffs:(Mat*)distCoeffs rvecs:(Mat*)rvecs tvecs:(Mat*)tvecs _objPoints:(Mat*)_objPoints NS_SWIFT_NAME(estimatePoseSingleMarkers(corners:markerLength:cameraMatrix:distCoeffs:rvecs:tvecs:_objPoints:));

/**
 * Pose estimation for single markers
 *
 * @param corners vector of already detected markers corners. For each marker, its four corners
 * are provided, (e.g std::vector<std::vector<cv::Point2f> > ). For N detected markers,
 * the dimensions of this array should be Nx4. The order of the corners should be clockwise.
 * @see `+detectMarkers:dictionary:corners:ids:parameters:rejectedImgPoints:cameraMatrix:distCoeff:`
 * @param markerLength the length of the markers' side. The returning translation vectors will
 * be in the same unit. Normally, unit is meters.
 * @param cameraMatrix input 3x3 floating-point camera matrix
 * `$$\newcommand{\vecthreethree}[9]{ \begin{bmatrix} #1 & #2 & #3\\\\ #4 & #5 & #6\\\\ #7 & #8 & #9 \end{bmatrix} } A = \vecthreethree{f_x}{0}{c_x}{0}{f_y}{c_y}{0}{0}{1}$$`
 * @param distCoeffs vector of distortion coefficients
 * `$$(k_1, k_2, p_1, p_2[, k_3[, k_4, k_5, k_6],[s_1, s_2, s_3, s_4]])$$` of 4, 5, 8 or 12 elements
 * @param rvecs array of output rotation vectors (@see Rodrigues) (e.g. std::vector<cv::Vec3d>).
 * Each element in rvecs corresponds to the specific marker in imgPoints.
 * @param tvecs array of output translation vectors (e.g. std::vector<cv::Vec3d>).
 * Each element in tvecs corresponds to the specific marker in imgPoints.
 *
 * This function receives the detected markers and returns their pose estimation respect to
 * the camera individually. So for each marker, one rotation and translation vector is returned.
 * The returned transformation is the one that transforms points from each marker coordinate system
 * to the camera coordinate system.
 * The marker corrdinate system is centered on the middle of the marker, with the Z axis
 * perpendicular to the marker plane.
 * The coordinates of the four corners of the marker in its own coordinate system are:
 * (-markerLength/2, markerLength/2, 0), (markerLength/2, markerLength/2, 0),
 * (markerLength/2, -markerLength/2, 0), (-markerLength/2, -markerLength/2, 0)
 */
+ (void)estimatePoseSingleMarkers:(NSArray<Mat*>*)corners markerLength:(float)markerLength cameraMatrix:(Mat*)cameraMatrix distCoeffs:(Mat*)distCoeffs rvecs:(Mat*)rvecs tvecs:(Mat*)tvecs NS_SWIFT_NAME(estimatePoseSingleMarkers(corners:markerLength:cameraMatrix:distCoeffs:rvecs:tvecs:));


//
//  int cv::aruco::estimatePoseBoard(vector_Mat corners, Mat ids, Ptr_Board board, Mat cameraMatrix, Mat distCoeffs, Mat& rvec, Mat& tvec, bool useExtrinsicGuess = false)
//
/**
 * Pose estimation for a board of markers
 *
 * @param corners vector of already detected markers corners. For each marker, its four corners
 * are provided, (e.g std::vector<std::vector<cv::Point2f> > ). For N detected markers, the
 * dimensions of this array should be Nx4. The order of the corners should be clockwise.
 * @param ids list of identifiers for each marker in corners
 * @param board layout of markers in the board. The layout is composed by the marker identifiers
 * and the positions of each marker corner in the board reference system.
 * @param cameraMatrix input 3x3 floating-point camera matrix
 * `$$\newcommand{\vecthreethree}[9]{ \begin{bmatrix} #1 & #2 & #3\\\\ #4 & #5 & #6\\\\ #7 & #8 & #9 \end{bmatrix} } A = \vecthreethree{f_x}{0}{c_x}{0}{f_y}{c_y}{0}{0}{1}$$`
 * @param distCoeffs vector of distortion coefficients
 * `$$(k_1, k_2, p_1, p_2[, k_3[, k_4, k_5, k_6],[s_1, s_2, s_3, s_4]])$$` of 4, 5, 8 or 12 elements
 * @param rvec Output vector (e.g. cv::Mat) corresponding to the rotation vector of the board
 * (see cv::Rodrigues). Used as initial guess if not empty.
 * @param tvec Output vector (e.g. cv::Mat) corresponding to the translation vector of the board.
 * @param useExtrinsicGuess defines whether initial guess for \b rvec and \b tvec will be used or not.
 * Used as initial guess if not empty.
 *
 * This function receives the detected markers and returns the pose of a marker board composed
 * by those markers.
 * A Board of marker has a single world coordinate system which is defined by the board layout.
 * The returned transformation is the one that transforms points from the board coordinate system
 * to the camera coordinate system.
 * Input markers that are not included in the board layout are ignored.
 * The function returns the number of markers from the input employed for the board pose estimation.
 * Note that returning a 0 means the pose has not been estimated.
 */
+ (int)estimatePoseBoard:(NSArray<Mat*>*)corners ids:(Mat*)ids board:(Board*)board cameraMatrix:(Mat*)cameraMatrix distCoeffs:(Mat*)distCoeffs rvec:(Mat*)rvec tvec:(Mat*)tvec useExtrinsicGuess:(BOOL)useExtrinsicGuess NS_SWIFT_NAME(estimatePoseBoard(corners:ids:board:cameraMatrix:distCoeffs:rvec:tvec:useExtrinsicGuess:));

/**
 * Pose estimation for a board of markers
 *
 * @param corners vector of already detected markers corners. For each marker, its four corners
 * are provided, (e.g std::vector<std::vector<cv::Point2f> > ). For N detected markers, the
 * dimensions of this array should be Nx4. The order of the corners should be clockwise.
 * @param ids list of identifiers for each marker in corners
 * @param board layout of markers in the board. The layout is composed by the marker identifiers
 * and the positions of each marker corner in the board reference system.
 * @param cameraMatrix input 3x3 floating-point camera matrix
 * `$$\newcommand{\vecthreethree}[9]{ \begin{bmatrix} #1 & #2 & #3\\\\ #4 & #5 & #6\\\\ #7 & #8 & #9 \end{bmatrix} } A = \vecthreethree{f_x}{0}{c_x}{0}{f_y}{c_y}{0}{0}{1}$$`
 * @param distCoeffs vector of distortion coefficients
 * `$$(k_1, k_2, p_1, p_2[, k_3[, k_4, k_5, k_6],[s_1, s_2, s_3, s_4]])$$` of 4, 5, 8 or 12 elements
 * @param rvec Output vector (e.g. cv::Mat) corresponding to the rotation vector of the board
 * (see cv::Rodrigues). Used as initial guess if not empty.
 * @param tvec Output vector (e.g. cv::Mat) corresponding to the translation vector of the board.
 * Used as initial guess if not empty.
 *
 * This function receives the detected markers and returns the pose of a marker board composed
 * by those markers.
 * A Board of marker has a single world coordinate system which is defined by the board layout.
 * The returned transformation is the one that transforms points from the board coordinate system
 * to the camera coordinate system.
 * Input markers that are not included in the board layout are ignored.
 * The function returns the number of markers from the input employed for the board pose estimation.
 * Note that returning a 0 means the pose has not been estimated.
 */
+ (int)estimatePoseBoard:(NSArray<Mat*>*)corners ids:(Mat*)ids board:(Board*)board cameraMatrix:(Mat*)cameraMatrix distCoeffs:(Mat*)distCoeffs rvec:(Mat*)rvec tvec:(Mat*)tvec NS_SWIFT_NAME(estimatePoseBoard(corners:ids:board:cameraMatrix:distCoeffs:rvec:tvec:));


//
//  void cv::aruco::refineDetectedMarkers(Mat image, Ptr_Board board, vector_Mat& detectedCorners, Mat& detectedIds, vector_Mat& rejectedCorners, Mat cameraMatrix = Mat(), Mat distCoeffs = Mat(), float minRepDistance = 10.f, float errorCorrectionRate = 3.f, bool checkAllOrders = true, Mat& recoveredIdxs = Mat(), Ptr_DetectorParameters parameters = DetectorParameters::create())
//
/**
 * Refind not detected markers based on the already detected and the board layout
 *
 * @param image input image
 * @param board layout of markers in the board.
 * @param detectedCorners vector of already detected marker corners.
 * @param detectedIds vector of already detected marker identifiers.
 * @param rejectedCorners vector of rejected candidates during the marker detection process.
 * @param cameraMatrix optional input 3x3 floating-point camera matrix
 * `$$\newcommand{\vecthreethree}[9]{ \begin{bmatrix} #1 & #2 & #3\\\\ #4 & #5 & #6\\\\ #7 & #8 & #9 \end{bmatrix} } A = \vecthreethree{f_x}{0}{c_x}{0}{f_y}{c_y}{0}{0}{1}$$`
 * @param distCoeffs optional vector of distortion coefficients
 * `$$(k_1, k_2, p_1, p_2[, k_3[, k_4, k_5, k_6],[s_1, s_2, s_3, s_4]])$$` of 4, 5, 8 or 12 elements
 * @param minRepDistance minimum distance between the corners of the rejected candidate and the
 * reprojected marker in order to consider it as a correspondence.
 * @param errorCorrectionRate rate of allowed erroneous bits respect to the error correction
 * capability of the used dictionary. -1 ignores the error correction step.
 * @param checkAllOrders Consider the four posible corner orders in the rejectedCorners array.
 * If it set to false, only the provided corner order is considered (default true).
 * @param recoveredIdxs Optional array to returns the indexes of the recovered candidates in the
 * original rejectedCorners array.
 * @param parameters marker detection parameters
 *
 * This function tries to find markers that were not detected in the basic detecMarkers function.
 * First, based on the current detected marker and the board layout, the function interpolates
 * the position of the missing markers. Then it tries to find correspondence between the reprojected
 * markers and the rejected candidates based on the minRepDistance and errorCorrectionRate
 * parameters.
 * If camera parameters and distortion coefficients are provided, missing markers are reprojected
 * using projectPoint function. If not, missing marker projections are interpolated using global
 * homography, and all the marker corners in the board must have the same Z coordinate.
 */
+ (void)refineDetectedMarkers:(Mat*)image board:(Board*)board detectedCorners:(NSMutableArray<Mat*>*)detectedCorners detectedIds:(Mat*)detectedIds rejectedCorners:(NSMutableArray<Mat*>*)rejectedCorners cameraMatrix:(Mat*)cameraMatrix distCoeffs:(Mat*)distCoeffs minRepDistance:(float)minRepDistance errorCorrectionRate:(float)errorCorrectionRate checkAllOrders:(BOOL)checkAllOrders recoveredIdxs:(Mat*)recoveredIdxs parameters:(DetectorParameters*)parameters NS_SWIFT_NAME(refineDetectedMarkers(image:board:detectedCorners:detectedIds:rejectedCorners:cameraMatrix:distCoeffs:minRepDistance:errorCorrectionRate:checkAllOrders:recoveredIdxs:parameters:));

/**
 * Refind not detected markers based on the already detected and the board layout
 *
 * @param image input image
 * @param board layout of markers in the board.
 * @param detectedCorners vector of already detected marker corners.
 * @param detectedIds vector of already detected marker identifiers.
 * @param rejectedCorners vector of rejected candidates during the marker detection process.
 * @param cameraMatrix optional input 3x3 floating-point camera matrix
 * `$$\newcommand{\vecthreethree}[9]{ \begin{bmatrix} #1 & #2 & #3\\\\ #4 & #5 & #6\\\\ #7 & #8 & #9 \end{bmatrix} } A = \vecthreethree{f_x}{0}{c_x}{0}{f_y}{c_y}{0}{0}{1}$$`
 * @param distCoeffs optional vector of distortion coefficients
 * `$$(k_1, k_2, p_1, p_2[, k_3[, k_4, k_5, k_6],[s_1, s_2, s_3, s_4]])$$` of 4, 5, 8 or 12 elements
 * @param minRepDistance minimum distance between the corners of the rejected candidate and the
 * reprojected marker in order to consider it as a correspondence.
 * @param errorCorrectionRate rate of allowed erroneous bits respect to the error correction
 * capability of the used dictionary. -1 ignores the error correction step.
 * @param checkAllOrders Consider the four posible corner orders in the rejectedCorners array.
 * If it set to false, only the provided corner order is considered (default true).
 * @param recoveredIdxs Optional array to returns the indexes of the recovered candidates in the
 * original rejectedCorners array.
 *
 * This function tries to find markers that were not detected in the basic detecMarkers function.
 * First, based on the current detected marker and the board layout, the function interpolates
 * the position of the missing markers. Then it tries to find correspondence between the reprojected
 * markers and the rejected candidates based on the minRepDistance and errorCorrectionRate
 * parameters.
 * If camera parameters and distortion coefficients are provided, missing markers are reprojected
 * using projectPoint function. If not, missing marker projections are interpolated using global
 * homography, and all the marker corners in the board must have the same Z coordinate.
 */
+ (void)refineDetectedMarkers:(Mat*)image board:(Board*)board detectedCorners:(NSMutableArray<Mat*>*)detectedCorners detectedIds:(Mat*)detectedIds rejectedCorners:(NSMutableArray<Mat*>*)rejectedCorners cameraMatrix:(Mat*)cameraMatrix distCoeffs:(Mat*)distCoeffs minRepDistance:(float)minRepDistance errorCorrectionRate:(float)errorCorrectionRate checkAllOrders:(BOOL)checkAllOrders recoveredIdxs:(Mat*)recoveredIdxs NS_SWIFT_NAME(refineDetectedMarkers(image:board:detectedCorners:detectedIds:rejectedCorners:cameraMatrix:distCoeffs:minRepDistance:errorCorrectionRate:checkAllOrders:recoveredIdxs:));

/**
 * Refind not detected markers based on the already detected and the board layout
 *
 * @param image input image
 * @param board layout of markers in the board.
 * @param detectedCorners vector of already detected marker corners.
 * @param detectedIds vector of already detected marker identifiers.
 * @param rejectedCorners vector of rejected candidates during the marker detection process.
 * @param cameraMatrix optional input 3x3 floating-point camera matrix
 * `$$\newcommand{\vecthreethree}[9]{ \begin{bmatrix} #1 & #2 & #3\\\\ #4 & #5 & #6\\\\ #7 & #8 & #9 \end{bmatrix} } A = \vecthreethree{f_x}{0}{c_x}{0}{f_y}{c_y}{0}{0}{1}$$`
 * @param distCoeffs optional vector of distortion coefficients
 * `$$(k_1, k_2, p_1, p_2[, k_3[, k_4, k_5, k_6],[s_1, s_2, s_3, s_4]])$$` of 4, 5, 8 or 12 elements
 * @param minRepDistance minimum distance between the corners of the rejected candidate and the
 * reprojected marker in order to consider it as a correspondence.
 * @param errorCorrectionRate rate of allowed erroneous bits respect to the error correction
 * capability of the used dictionary. -1 ignores the error correction step.
 * @param checkAllOrders Consider the four posible corner orders in the rejectedCorners array.
 * If it set to false, only the provided corner order is considered (default true).
 * original rejectedCorners array.
 *
 * This function tries to find markers that were not detected in the basic detecMarkers function.
 * First, based on the current detected marker and the board layout, the function interpolates
 * the position of the missing markers. Then it tries to find correspondence between the reprojected
 * markers and the rejected candidates based on the minRepDistance and errorCorrectionRate
 * parameters.
 * If camera parameters and distortion coefficients are provided, missing markers are reprojected
 * using projectPoint function. If not, missing marker projections are interpolated using global
 * homography, and all the marker corners in the board must have the same Z coordinate.
 */
+ (void)refineDetectedMarkers:(Mat*)image board:(Board*)board detectedCorners:(NSMutableArray<Mat*>*)detectedCorners detectedIds:(Mat*)detectedIds rejectedCorners:(NSMutableArray<Mat*>*)rejectedCorners cameraMatrix:(Mat*)cameraMatrix distCoeffs:(Mat*)distCoeffs minRepDistance:(float)minRepDistance errorCorrectionRate:(float)errorCorrectionRate checkAllOrders:(BOOL)checkAllOrders NS_SWIFT_NAME(refineDetectedMarkers(image:board:detectedCorners:detectedIds:rejectedCorners:cameraMatrix:distCoeffs:minRepDistance:errorCorrectionRate:checkAllOrders:));

/**
 * Refind not detected markers based on the already detected and the board layout
 *
 * @param image input image
 * @param board layout of markers in the board.
 * @param detectedCorners vector of already detected marker corners.
 * @param detectedIds vector of already detected marker identifiers.
 * @param rejectedCorners vector of rejected candidates during the marker detection process.
 * @param cameraMatrix optional input 3x3 floating-point camera matrix
 * `$$\newcommand{\vecthreethree}[9]{ \begin{bmatrix} #1 & #2 & #3\\\\ #4 & #5 & #6\\\\ #7 & #8 & #9 \end{bmatrix} } A = \vecthreethree{f_x}{0}{c_x}{0}{f_y}{c_y}{0}{0}{1}$$`
 * @param distCoeffs optional vector of distortion coefficients
 * `$$(k_1, k_2, p_1, p_2[, k_3[, k_4, k_5, k_6],[s_1, s_2, s_3, s_4]])$$` of 4, 5, 8 or 12 elements
 * @param minRepDistance minimum distance between the corners of the rejected candidate and the
 * reprojected marker in order to consider it as a correspondence.
 * @param errorCorrectionRate rate of allowed erroneous bits respect to the error correction
 * capability of the used dictionary. -1 ignores the error correction step.
 * If it set to false, only the provided corner order is considered (default true).
 * original rejectedCorners array.
 *
 * This function tries to find markers that were not detected in the basic detecMarkers function.
 * First, based on the current detected marker and the board layout, the function interpolates
 * the position of the missing markers. Then it tries to find correspondence between the reprojected
 * markers and the rejected candidates based on the minRepDistance and errorCorrectionRate
 * parameters.
 * If camera parameters and distortion coefficients are provided, missing markers are reprojected
 * using projectPoint function. If not, missing marker projections are interpolated using global
 * homography, and all the marker corners in the board must have the same Z coordinate.
 */
+ (void)refineDetectedMarkers:(Mat*)image board:(Board*)board detectedCorners:(NSMutableArray<Mat*>*)detectedCorners detectedIds:(Mat*)detectedIds rejectedCorners:(NSMutableArray<Mat*>*)rejectedCorners cameraMatrix:(Mat*)cameraMatrix distCoeffs:(Mat*)distCoeffs minRepDistance:(float)minRepDistance errorCorrectionRate:(float)errorCorrectionRate NS_SWIFT_NAME(refineDetectedMarkers(image:board:detectedCorners:detectedIds:rejectedCorners:cameraMatrix:distCoeffs:minRepDistance:errorCorrectionRate:));

/**
 * Refind not detected markers based on the already detected and the board layout
 *
 * @param image input image
 * @param board layout of markers in the board.
 * @param detectedCorners vector of already detected marker corners.
 * @param detectedIds vector of already detected marker identifiers.
 * @param rejectedCorners vector of rejected candidates during the marker detection process.
 * @param cameraMatrix optional input 3x3 floating-point camera matrix
 * `$$\newcommand{\vecthreethree}[9]{ \begin{bmatrix} #1 & #2 & #3\\\\ #4 & #5 & #6\\\\ #7 & #8 & #9 \end{bmatrix} } A = \vecthreethree{f_x}{0}{c_x}{0}{f_y}{c_y}{0}{0}{1}$$`
 * @param distCoeffs optional vector of distortion coefficients
 * `$$(k_1, k_2, p_1, p_2[, k_3[, k_4, k_5, k_6],[s_1, s_2, s_3, s_4]])$$` of 4, 5, 8 or 12 elements
 * @param minRepDistance minimum distance between the corners of the rejected candidate and the
 * reprojected marker in order to consider it as a correspondence.
 * capability of the used dictionary. -1 ignores the error correction step.
 * If it set to false, only the provided corner order is considered (default true).
 * original rejectedCorners array.
 *
 * This function tries to find markers that were not detected in the basic detecMarkers function.
 * First, based on the current detected marker and the board layout, the function interpolates
 * the position of the missing markers. Then it tries to find correspondence between the reprojected
 * markers and the rejected candidates based on the minRepDistance and errorCorrectionRate
 * parameters.
 * If camera parameters and distortion coefficients are provided, missing markers are reprojected
 * using projectPoint function. If not, missing marker projections are interpolated using global
 * homography, and all the marker corners in the board must have the same Z coordinate.
 */
+ (void)refineDetectedMarkers:(Mat*)image board:(Board*)board detectedCorners:(NSMutableArray<Mat*>*)detectedCorners detectedIds:(Mat*)detectedIds rejectedCorners:(NSMutableArray<Mat*>*)rejectedCorners cameraMatrix:(Mat*)cameraMatrix distCoeffs:(Mat*)distCoeffs minRepDistance:(float)minRepDistance NS_SWIFT_NAME(refineDetectedMarkers(image:board:detectedCorners:detectedIds:rejectedCorners:cameraMatrix:distCoeffs:minRepDistance:));

/**
 * Refind not detected markers based on the already detected and the board layout
 *
 * @param image input image
 * @param board layout of markers in the board.
 * @param detectedCorners vector of already detected marker corners.
 * @param detectedIds vector of already detected marker identifiers.
 * @param rejectedCorners vector of rejected candidates during the marker detection process.
 * @param cameraMatrix optional input 3x3 floating-point camera matrix
 * `$$\newcommand{\vecthreethree}[9]{ \begin{bmatrix} #1 & #2 & #3\\\\ #4 & #5 & #6\\\\ #7 & #8 & #9 \end{bmatrix} } A = \vecthreethree{f_x}{0}{c_x}{0}{f_y}{c_y}{0}{0}{1}$$`
 * @param distCoeffs optional vector of distortion coefficients
 * `$$(k_1, k_2, p_1, p_2[, k_3[, k_4, k_5, k_6],[s_1, s_2, s_3, s_4]])$$` of 4, 5, 8 or 12 elements
 * reprojected marker in order to consider it as a correspondence.
 * capability of the used dictionary. -1 ignores the error correction step.
 * If it set to false, only the provided corner order is considered (default true).
 * original rejectedCorners array.
 *
 * This function tries to find markers that were not detected in the basic detecMarkers function.
 * First, based on the current detected marker and the board layout, the function interpolates
 * the position of the missing markers. Then it tries to find correspondence between the reprojected
 * markers and the rejected candidates based on the minRepDistance and errorCorrectionRate
 * parameters.
 * If camera parameters and distortion coefficients are provided, missing markers are reprojected
 * using projectPoint function. If not, missing marker projections are interpolated using global
 * homography, and all the marker corners in the board must have the same Z coordinate.
 */
+ (void)refineDetectedMarkers:(Mat*)image board:(Board*)board detectedCorners:(NSMutableArray<Mat*>*)detectedCorners detectedIds:(Mat*)detectedIds rejectedCorners:(NSMutableArray<Mat*>*)rejectedCorners cameraMatrix:(Mat*)cameraMatrix distCoeffs:(Mat*)distCoeffs NS_SWIFT_NAME(refineDetectedMarkers(image:board:detectedCorners:detectedIds:rejectedCorners:cameraMatrix:distCoeffs:));

/**
 * Refind not detected markers based on the already detected and the board layout
 *
 * @param image input image
 * @param board layout of markers in the board.
 * @param detectedCorners vector of already detected marker corners.
 * @param detectedIds vector of already detected marker identifiers.
 * @param rejectedCorners vector of rejected candidates during the marker detection process.
 * @param cameraMatrix optional input 3x3 floating-point camera matrix
 * `$$\newcommand{\vecthreethree}[9]{ \begin{bmatrix} #1 & #2 & #3\\\\ #4 & #5 & #6\\\\ #7 & #8 & #9 \end{bmatrix} } A = \vecthreethree{f_x}{0}{c_x}{0}{f_y}{c_y}{0}{0}{1}$$`
 * `$$(k_1, k_2, p_1, p_2[, k_3[, k_4, k_5, k_6],[s_1, s_2, s_3, s_4]])$$` of 4, 5, 8 or 12 elements
 * reprojected marker in order to consider it as a correspondence.
 * capability of the used dictionary. -1 ignores the error correction step.
 * If it set to false, only the provided corner order is considered (default true).
 * original rejectedCorners array.
 *
 * This function tries to find markers that were not detected in the basic detecMarkers function.
 * First, based on the current detected marker and the board layout, the function interpolates
 * the position of the missing markers. Then it tries to find correspondence between the reprojected
 * markers and the rejected candidates based on the minRepDistance and errorCorrectionRate
 * parameters.
 * If camera parameters and distortion coefficients are provided, missing markers are reprojected
 * using projectPoint function. If not, missing marker projections are interpolated using global
 * homography, and all the marker corners in the board must have the same Z coordinate.
 */
+ (void)refineDetectedMarkers:(Mat*)image board:(Board*)board detectedCorners:(NSMutableArray<Mat*>*)detectedCorners detectedIds:(Mat*)detectedIds rejectedCorners:(NSMutableArray<Mat*>*)rejectedCorners cameraMatrix:(Mat*)cameraMatrix NS_SWIFT_NAME(refineDetectedMarkers(image:board:detectedCorners:detectedIds:rejectedCorners:cameraMatrix:));

/**
 * Refind not detected markers based on the already detected and the board layout
 *
 * @param image input image
 * @param board layout of markers in the board.
 * @param detectedCorners vector of already detected marker corners.
 * @param detectedIds vector of already detected marker identifiers.
 * @param rejectedCorners vector of rejected candidates during the marker detection process.
 * `$$\newcommand{\vecthreethree}[9]{ \begin{bmatrix} #1 & #2 & #3\\\\ #4 & #5 & #6\\\\ #7 & #8 & #9 \end{bmatrix} } A = \vecthreethree{f_x}{0}{c_x}{0}{f_y}{c_y}{0}{0}{1}$$`
 * `$$(k_1, k_2, p_1, p_2[, k_3[, k_4, k_5, k_6],[s_1, s_2, s_3, s_4]])$$` of 4, 5, 8 or 12 elements
 * reprojected marker in order to consider it as a correspondence.
 * capability of the used dictionary. -1 ignores the error correction step.
 * If it set to false, only the provided corner order is considered (default true).
 * original rejectedCorners array.
 *
 * This function tries to find markers that were not detected in the basic detecMarkers function.
 * First, based on the current detected marker and the board layout, the function interpolates
 * the position of the missing markers. Then it tries to find correspondence between the reprojected
 * markers and the rejected candidates based on the minRepDistance and errorCorrectionRate
 * parameters.
 * If camera parameters and distortion coefficients are provided, missing markers are reprojected
 * using projectPoint function. If not, missing marker projections are interpolated using global
 * homography, and all the marker corners in the board must have the same Z coordinate.
 */
+ (void)refineDetectedMarkers:(Mat*)image board:(Board*)board detectedCorners:(NSMutableArray<Mat*>*)detectedCorners detectedIds:(Mat*)detectedIds rejectedCorners:(NSMutableArray<Mat*>*)rejectedCorners NS_SWIFT_NAME(refineDetectedMarkers(image:board:detectedCorners:detectedIds:rejectedCorners:));


//
//  void cv::aruco::drawDetectedMarkers(Mat& image, vector_Mat corners, Mat ids = Mat(), Scalar borderColor = Scalar(0, 255, 0))
//
/**
 * Draw detected markers in image
 *
 * @param image input/output image. It must have 1 or 3 channels. The number of channels is not
 * altered.
 * @param corners positions of marker corners on input image.
 * (e.g std::vector<std::vector<cv::Point2f> > ). For N detected markers, the dimensions of
 * this array should be Nx4. The order of the corners should be clockwise.
 * @param ids vector of identifiers for markers in markersCorners .
 * Optional, if not provided, ids are not painted.
 * @param borderColor color of marker borders. Rest of colors (text color and first corner color)
 * are calculated based on this one to improve visualization.
 *
 * Given an array of detected marker corners and its corresponding ids, this functions draws
 * the markers in the image. The marker borders are painted and the markers identifiers if provided.
 * Useful for debugging purposes.
 */
+ (void)drawDetectedMarkers:(Mat*)image corners:(NSArray<Mat*>*)corners ids:(Mat*)ids borderColor:(Scalar*)borderColor NS_SWIFT_NAME(drawDetectedMarkers(image:corners:ids:borderColor:));

/**
 * Draw detected markers in image
 *
 * @param image input/output image. It must have 1 or 3 channels. The number of channels is not
 * altered.
 * @param corners positions of marker corners on input image.
 * (e.g std::vector<std::vector<cv::Point2f> > ). For N detected markers, the dimensions of
 * this array should be Nx4. The order of the corners should be clockwise.
 * @param ids vector of identifiers for markers in markersCorners .
 * Optional, if not provided, ids are not painted.
 * are calculated based on this one to improve visualization.
 *
 * Given an array of detected marker corners and its corresponding ids, this functions draws
 * the markers in the image. The marker borders are painted and the markers identifiers if provided.
 * Useful for debugging purposes.
 */
+ (void)drawDetectedMarkers:(Mat*)image corners:(NSArray<Mat*>*)corners ids:(Mat*)ids NS_SWIFT_NAME(drawDetectedMarkers(image:corners:ids:));

/**
 * Draw detected markers in image
 *
 * @param image input/output image. It must have 1 or 3 channels. The number of channels is not
 * altered.
 * @param corners positions of marker corners on input image.
 * (e.g std::vector<std::vector<cv::Point2f> > ). For N detected markers, the dimensions of
 * this array should be Nx4. The order of the corners should be clockwise.
 * Optional, if not provided, ids are not painted.
 * are calculated based on this one to improve visualization.
 *
 * Given an array of detected marker corners and its corresponding ids, this functions draws
 * the markers in the image. The marker borders are painted and the markers identifiers if provided.
 * Useful for debugging purposes.
 */
+ (void)drawDetectedMarkers:(Mat*)image corners:(NSArray<Mat*>*)corners NS_SWIFT_NAME(drawDetectedMarkers(image:corners:));


//
//  void cv::aruco::drawAxis(Mat& image, Mat cameraMatrix, Mat distCoeffs, Mat rvec, Mat tvec, float length)
//
/**
 * Draw coordinate system axis from pose estimation
 *
 * @param image input/output image. It must have 1 or 3 channels. The number of channels is not
 * altered.
 * @param cameraMatrix input 3x3 floating-point camera matrix
 * `$$\newcommand{\vecthreethree}[9]{ \begin{bmatrix} #1 & #2 & #3\\\\ #4 & #5 & #6\\\\ #7 & #8 & #9 \end{bmatrix} } A = \vecthreethree{f_x}{0}{c_x}{0}{f_y}{c_y}{0}{0}{1}$$`
 * @param distCoeffs vector of distortion coefficients
 * `$$(k_1, k_2, p_1, p_2[, k_3[, k_4, k_5, k_6],[s_1, s_2, s_3, s_4]])$$` of 4, 5, 8 or 12 elements
 * @param rvec rotation vector of the coordinate system that will be drawn. (@see Rodrigues).
 * @param tvec translation vector of the coordinate system that will be drawn.
 * @param length length of the painted axis in the same unit than tvec (usually in meters)
 *
 * Given the pose estimation of a marker or board, this function draws the axis of the world
 * coordinate system, i.e. the system centered on the marker/board. Useful for debugging purposes.
 *
 * @deprecated use cv::drawFrameAxes
 */
+ (void)drawAxis:(Mat*)image cameraMatrix:(Mat*)cameraMatrix distCoeffs:(Mat*)distCoeffs rvec:(Mat*)rvec tvec:(Mat*)tvec length:(float)length NS_SWIFT_NAME(drawAxis(image:cameraMatrix:distCoeffs:rvec:tvec:length:)) DEPRECATED_ATTRIBUTE;


//
//  void cv::aruco::drawMarker(Ptr_Dictionary dictionary, int id, int sidePixels, Mat& img, int borderBits = 1)
//
/**
 * Draw a canonical marker image
 *
 * @param dictionary dictionary of markers indicating the type of markers
 * @param id identifier of the marker that will be returned. It has to be a valid id
 * in the specified dictionary.
 * @param sidePixels size of the image in pixels
 * @param img output image with the marker
 * @param borderBits width of the marker border.
 *
 * This function returns a marker image in its canonical form (i.e. ready to be printed)
 */
+ (void)drawMarker:(Dictionary*)dictionary id:(int)id sidePixels:(int)sidePixels img:(Mat*)img borderBits:(int)borderBits NS_SWIFT_NAME(drawMarker(dictionary:id:sidePixels:img:borderBits:));

/**
 * Draw a canonical marker image
 *
 * @param dictionary dictionary of markers indicating the type of markers
 * @param id identifier of the marker that will be returned. It has to be a valid id
 * in the specified dictionary.
 * @param sidePixels size of the image in pixels
 * @param img output image with the marker
 *
 * This function returns a marker image in its canonical form (i.e. ready to be printed)
 */
+ (void)drawMarker:(Dictionary*)dictionary id:(int)id sidePixels:(int)sidePixels img:(Mat*)img NS_SWIFT_NAME(drawMarker(dictionary:id:sidePixels:img:));


//
//  void cv::aruco::drawPlanarBoard(Ptr_Board board, Size outSize, Mat& img, int marginSize = 0, int borderBits = 1)
//
/**
 * Draw a planar board
 * @see `_drawPlanarBoardImpl`
 *
 * @param board layout of the board that will be drawn. The board should be planar,
 * z coordinate is ignored
 * @param outSize size of the output image in pixels.
 * @param img output image with the board. The size of this image will be outSize
 * and the board will be on the center, keeping the board proportions.
 * @param marginSize minimum margins (in pixels) of the board in the output image
 * @param borderBits width of the marker borders.
 *
 * This function return the image of a planar board, ready to be printed. It assumes
 * the Board layout specified is planar by ignoring the z coordinates of the object points.
 */
+ (void)drawPlanarBoard:(Board*)board outSize:(Size2i*)outSize img:(Mat*)img marginSize:(int)marginSize borderBits:(int)borderBits NS_SWIFT_NAME(drawPlanarBoard(board:outSize:img:marginSize:borderBits:));

/**
 * Draw a planar board
 * @see `_drawPlanarBoardImpl`
 *
 * @param board layout of the board that will be drawn. The board should be planar,
 * z coordinate is ignored
 * @param outSize size of the output image in pixels.
 * @param img output image with the board. The size of this image will be outSize
 * and the board will be on the center, keeping the board proportions.
 * @param marginSize minimum margins (in pixels) of the board in the output image
 *
 * This function return the image of a planar board, ready to be printed. It assumes
 * the Board layout specified is planar by ignoring the z coordinates of the object points.
 */
+ (void)drawPlanarBoard:(Board*)board outSize:(Size2i*)outSize img:(Mat*)img marginSize:(int)marginSize NS_SWIFT_NAME(drawPlanarBoard(board:outSize:img:marginSize:));

/**
 * Draw a planar board
 * @see `_drawPlanarBoardImpl`
 *
 * @param board layout of the board that will be drawn. The board should be planar,
 * z coordinate is ignored
 * @param outSize size of the output image in pixels.
 * @param img output image with the board. The size of this image will be outSize
 * and the board will be on the center, keeping the board proportions.
 *
 * This function return the image of a planar board, ready to be printed. It assumes
 * the Board layout specified is planar by ignoring the z coordinates of the object points.
 */
+ (void)drawPlanarBoard:(Board*)board outSize:(Size2i*)outSize img:(Mat*)img NS_SWIFT_NAME(drawPlanarBoard(board:outSize:img:));


//
//  double cv::aruco::calibrateCameraAruco(vector_Mat corners, Mat ids, Mat counter, Ptr_Board board, Size imageSize, Mat& cameraMatrix, Mat& distCoeffs, vector_Mat& rvecs, vector_Mat& tvecs, Mat& stdDeviationsIntrinsics, Mat& stdDeviationsExtrinsics, Mat& perViewErrors, int flags = 0, TermCriteria criteria = TermCriteria(TermCriteria::COUNT + TermCriteria::EPS, 30, DBL_EPSILON))
//
/**
 * Calibrate a camera using aruco markers
 *
 * @param corners vector of detected marker corners in all frames.
 * The corners should have the same format returned by detectMarkers (see #detectMarkers).
 * @param ids list of identifiers for each marker in corners
 * @param counter number of markers in each frame so that corners and ids can be split
 * @param board Marker Board layout
 * @param imageSize Size of the image used only to initialize the intrinsic camera matrix.
 * @param cameraMatrix Output 3x3 floating-point camera matrix
 * `$$\newcommand{\vecthreethree}[9]{ \begin{bmatrix} #1 & #2 & #3\\\\ #4 & #5 & #6\\\\ #7 & #8 & #9 \end{bmatrix} } A = \vecthreethree{f_x}{0}{c_x}{0}{f_y}{c_y}{0}{0}{1}$$` . If CV\_CALIB\_USE\_INTRINSIC\_GUESS
 * and/or CV_CALIB_FIX_ASPECT_RATIO are specified, some or all of fx, fy, cx, cy must be
 * initialized before calling the function.
 * @param distCoeffs Output vector of distortion coefficients
 * `$$(k_1, k_2, p_1, p_2[, k_3[, k_4, k_5, k_6],[s_1, s_2, s_3, s_4]])$$` of 4, 5, 8 or 12 elements
 * @param rvecs Output vector of rotation vectors (see Rodrigues ) estimated for each board view
 * (e.g. std::vector<cv::Mat>>). That is, each k-th rotation vector together with the corresponding
 * k-th translation vector (see the next output parameter description) brings the board pattern
 * from the model coordinate space (in which object points are specified) to the world coordinate
 * space, that is, a real position of the board pattern in the k-th pattern view (k=0.. *M* -1).
 * @param tvecs Output vector of translation vectors estimated for each pattern view.
 * @param stdDeviationsIntrinsics Output vector of standard deviations estimated for intrinsic parameters.
 * Order of deviations values:
 * `$$(f_x, f_y, c_x, c_y, k_1, k_2, p_1, p_2, k_3, k_4, k_5, k_6 , s_1, s_2, s_3,
 * s_4, \tau_x, \tau_y)$$` If one of parameters is not estimated, it's deviation is equals to zero.
 * @param stdDeviationsExtrinsics Output vector of standard deviations estimated for extrinsic parameters.
 * Order of deviations values: `$$(R_1, T_1, \dotsc , R_M, T_M)$$` where M is number of pattern views,
 * `$$R_i, T_i$$` are concatenated 1x3 vectors.
 * @param perViewErrors Output vector of average re-projection errors estimated for each pattern view.
 * @param flags flags Different flags  for the calibration process (see #calibrateCamera for details).
 * @param criteria Termination criteria for the iterative optimization algorithm.
 *
 * This function calibrates a camera using an Aruco Board. The function receives a list of
 * detected markers from several views of the Board. The process is similar to the chessboard
 * calibration in calibrateCamera(). The function returns the final re-projection error.
 */
+ (double)calibrateCameraArucoExtended:(NSArray<Mat*>*)corners ids:(Mat*)ids counter:(Mat*)counter board:(Board*)board imageSize:(Size2i*)imageSize cameraMatrix:(Mat*)cameraMatrix distCoeffs:(Mat*)distCoeffs rvecs:(NSMutableArray<Mat*>*)rvecs tvecs:(NSMutableArray<Mat*>*)tvecs stdDeviationsIntrinsics:(Mat*)stdDeviationsIntrinsics stdDeviationsExtrinsics:(Mat*)stdDeviationsExtrinsics perViewErrors:(Mat*)perViewErrors flags:(int)flags criteria:(TermCriteria*)criteria NS_SWIFT_NAME(calibrateCameraAruco(corners:ids:counter:board:imageSize:cameraMatrix:distCoeffs:rvecs:tvecs:stdDeviationsIntrinsics:stdDeviationsExtrinsics:perViewErrors:flags:criteria:));

/**
 * Calibrate a camera using aruco markers
 *
 * @param corners vector of detected marker corners in all frames.
 * The corners should have the same format returned by detectMarkers (see #detectMarkers).
 * @param ids list of identifiers for each marker in corners
 * @param counter number of markers in each frame so that corners and ids can be split
 * @param board Marker Board layout
 * @param imageSize Size of the image used only to initialize the intrinsic camera matrix.
 * @param cameraMatrix Output 3x3 floating-point camera matrix
 * `$$\newcommand{\vecthreethree}[9]{ \begin{bmatrix} #1 & #2 & #3\\\\ #4 & #5 & #6\\\\ #7 & #8 & #9 \end{bmatrix} } A = \vecthreethree{f_x}{0}{c_x}{0}{f_y}{c_y}{0}{0}{1}$$` . If CV\_CALIB\_USE\_INTRINSIC\_GUESS
 * and/or CV_CALIB_FIX_ASPECT_RATIO are specified, some or all of fx, fy, cx, cy must be
 * initialized before calling the function.
 * @param distCoeffs Output vector of distortion coefficients
 * `$$(k_1, k_2, p_1, p_2[, k_3[, k_4, k_5, k_6],[s_1, s_2, s_3, s_4]])$$` of 4, 5, 8 or 12 elements
 * @param rvecs Output vector of rotation vectors (see Rodrigues ) estimated for each board view
 * (e.g. std::vector<cv::Mat>>). That is, each k-th rotation vector together with the corresponding
 * k-th translation vector (see the next output parameter description) brings the board pattern
 * from the model coordinate space (in which object points are specified) to the world coordinate
 * space, that is, a real position of the board pattern in the k-th pattern view (k=0.. *M* -1).
 * @param tvecs Output vector of translation vectors estimated for each pattern view.
 * @param stdDeviationsIntrinsics Output vector of standard deviations estimated for intrinsic parameters.
 * Order of deviations values:
 * `$$(f_x, f_y, c_x, c_y, k_1, k_2, p_1, p_2, k_3, k_4, k_5, k_6 , s_1, s_2, s_3,
 * s_4, \tau_x, \tau_y)$$` If one of parameters is not estimated, it's deviation is equals to zero.
 * @param stdDeviationsExtrinsics Output vector of standard deviations estimated for extrinsic parameters.
 * Order of deviations values: `$$(R_1, T_1, \dotsc , R_M, T_M)$$` where M is number of pattern views,
 * `$$R_i, T_i$$` are concatenated 1x3 vectors.
 * @param perViewErrors Output vector of average re-projection errors estimated for each pattern view.
 * @param flags flags Different flags  for the calibration process (see #calibrateCamera for details).
 *
 * This function calibrates a camera using an Aruco Board. The function receives a list of
 * detected markers from several views of the Board. The process is similar to the chessboard
 * calibration in calibrateCamera(). The function returns the final re-projection error.
 */
+ (double)calibrateCameraArucoExtended:(NSArray<Mat*>*)corners ids:(Mat*)ids counter:(Mat*)counter board:(Board*)board imageSize:(Size2i*)imageSize cameraMatrix:(Mat*)cameraMatrix distCoeffs:(Mat*)distCoeffs rvecs:(NSMutableArray<Mat*>*)rvecs tvecs:(NSMutableArray<Mat*>*)tvecs stdDeviationsIntrinsics:(Mat*)stdDeviationsIntrinsics stdDeviationsExtrinsics:(Mat*)stdDeviationsExtrinsics perViewErrors:(Mat*)perViewErrors flags:(int)flags NS_SWIFT_NAME(calibrateCameraAruco(corners:ids:counter:board:imageSize:cameraMatrix:distCoeffs:rvecs:tvecs:stdDeviationsIntrinsics:stdDeviationsExtrinsics:perViewErrors:flags:));

/**
 * Calibrate a camera using aruco markers
 *
 * @param corners vector of detected marker corners in all frames.
 * The corners should have the same format returned by detectMarkers (see #detectMarkers).
 * @param ids list of identifiers for each marker in corners
 * @param counter number of markers in each frame so that corners and ids can be split
 * @param board Marker Board layout
 * @param imageSize Size of the image used only to initialize the intrinsic camera matrix.
 * @param cameraMatrix Output 3x3 floating-point camera matrix
 * `$$\newcommand{\vecthreethree}[9]{ \begin{bmatrix} #1 & #2 & #3\\\\ #4 & #5 & #6\\\\ #7 & #8 & #9 \end{bmatrix} } A = \vecthreethree{f_x}{0}{c_x}{0}{f_y}{c_y}{0}{0}{1}$$` . If CV\_CALIB\_USE\_INTRINSIC\_GUESS
 * and/or CV_CALIB_FIX_ASPECT_RATIO are specified, some or all of fx, fy, cx, cy must be
 * initialized before calling the function.
 * @param distCoeffs Output vector of distortion coefficients
 * `$$(k_1, k_2, p_1, p_2[, k_3[, k_4, k_5, k_6],[s_1, s_2, s_3, s_4]])$$` of 4, 5, 8 or 12 elements
 * @param rvecs Output vector of rotation vectors (see Rodrigues ) estimated for each board view
 * (e.g. std::vector<cv::Mat>>). That is, each k-th rotation vector together with the corresponding
 * k-th translation vector (see the next output parameter description) brings the board pattern
 * from the model coordinate space (in which object points are specified) to the world coordinate
 * space, that is, a real position of the board pattern in the k-th pattern view (k=0.. *M* -1).
 * @param tvecs Output vector of translation vectors estimated for each pattern view.
 * @param stdDeviationsIntrinsics Output vector of standard deviations estimated for intrinsic parameters.
 * Order of deviations values:
 * `$$(f_x, f_y, c_x, c_y, k_1, k_2, p_1, p_2, k_3, k_4, k_5, k_6 , s_1, s_2, s_3,
 * s_4, \tau_x, \tau_y)$$` If one of parameters is not estimated, it's deviation is equals to zero.
 * @param stdDeviationsExtrinsics Output vector of standard deviations estimated for extrinsic parameters.
 * Order of deviations values: `$$(R_1, T_1, \dotsc , R_M, T_M)$$` where M is number of pattern views,
 * `$$R_i, T_i$$` are concatenated 1x3 vectors.
 * @param perViewErrors Output vector of average re-projection errors estimated for each pattern view.
 *
 * This function calibrates a camera using an Aruco Board. The function receives a list of
 * detected markers from several views of the Board. The process is similar to the chessboard
 * calibration in calibrateCamera(). The function returns the final re-projection error.
 */
+ (double)calibrateCameraArucoExtended:(NSArray<Mat*>*)corners ids:(Mat*)ids counter:(Mat*)counter board:(Board*)board imageSize:(Size2i*)imageSize cameraMatrix:(Mat*)cameraMatrix distCoeffs:(Mat*)distCoeffs rvecs:(NSMutableArray<Mat*>*)rvecs tvecs:(NSMutableArray<Mat*>*)tvecs stdDeviationsIntrinsics:(Mat*)stdDeviationsIntrinsics stdDeviationsExtrinsics:(Mat*)stdDeviationsExtrinsics perViewErrors:(Mat*)perViewErrors NS_SWIFT_NAME(calibrateCameraAruco(corners:ids:counter:board:imageSize:cameraMatrix:distCoeffs:rvecs:tvecs:stdDeviationsIntrinsics:stdDeviationsExtrinsics:perViewErrors:));


//
//  double cv::aruco::calibrateCameraAruco(vector_Mat corners, Mat ids, Mat counter, Ptr_Board board, Size imageSize, Mat& cameraMatrix, Mat& distCoeffs, vector_Mat& rvecs = vector_Mat(), vector_Mat& tvecs = vector_Mat(), int flags = 0, TermCriteria criteria = TermCriteria(TermCriteria::COUNT + TermCriteria::EPS, 30, DBL_EPSILON))
//
/**
 * It's the same function as #calibrateCameraAruco but without calibration error estimation.
 */
+ (double)calibrateCameraAruco:(NSArray<Mat*>*)corners ids:(Mat*)ids counter:(Mat*)counter board:(Board*)board imageSize:(Size2i*)imageSize cameraMatrix:(Mat*)cameraMatrix distCoeffs:(Mat*)distCoeffs rvecs:(NSMutableArray<Mat*>*)rvecs tvecs:(NSMutableArray<Mat*>*)tvecs flags:(int)flags criteria:(TermCriteria*)criteria NS_SWIFT_NAME(calibrateCameraAruco(corners:ids:counter:board:imageSize:cameraMatrix:distCoeffs:rvecs:tvecs:flags:criteria:));

/**
 * It's the same function as #calibrateCameraAruco but without calibration error estimation.
 */
+ (double)calibrateCameraAruco:(NSArray<Mat*>*)corners ids:(Mat*)ids counter:(Mat*)counter board:(Board*)board imageSize:(Size2i*)imageSize cameraMatrix:(Mat*)cameraMatrix distCoeffs:(Mat*)distCoeffs rvecs:(NSMutableArray<Mat*>*)rvecs tvecs:(NSMutableArray<Mat*>*)tvecs flags:(int)flags NS_SWIFT_NAME(calibrateCameraAruco(corners:ids:counter:board:imageSize:cameraMatrix:distCoeffs:rvecs:tvecs:flags:));

/**
 * It's the same function as #calibrateCameraAruco but without calibration error estimation.
 */
+ (double)calibrateCameraAruco:(NSArray<Mat*>*)corners ids:(Mat*)ids counter:(Mat*)counter board:(Board*)board imageSize:(Size2i*)imageSize cameraMatrix:(Mat*)cameraMatrix distCoeffs:(Mat*)distCoeffs rvecs:(NSMutableArray<Mat*>*)rvecs tvecs:(NSMutableArray<Mat*>*)tvecs NS_SWIFT_NAME(calibrateCameraAruco(corners:ids:counter:board:imageSize:cameraMatrix:distCoeffs:rvecs:tvecs:));

/**
 * It's the same function as #calibrateCameraAruco but without calibration error estimation.
 */
+ (double)calibrateCameraAruco:(NSArray<Mat*>*)corners ids:(Mat*)ids counter:(Mat*)counter board:(Board*)board imageSize:(Size2i*)imageSize cameraMatrix:(Mat*)cameraMatrix distCoeffs:(Mat*)distCoeffs rvecs:(NSMutableArray<Mat*>*)rvecs NS_SWIFT_NAME(calibrateCameraAruco(corners:ids:counter:board:imageSize:cameraMatrix:distCoeffs:rvecs:));

/**
 * It's the same function as #calibrateCameraAruco but without calibration error estimation.
 */
+ (double)calibrateCameraAruco:(NSArray<Mat*>*)corners ids:(Mat*)ids counter:(Mat*)counter board:(Board*)board imageSize:(Size2i*)imageSize cameraMatrix:(Mat*)cameraMatrix distCoeffs:(Mat*)distCoeffs NS_SWIFT_NAME(calibrateCameraAruco(corners:ids:counter:board:imageSize:cameraMatrix:distCoeffs:));


//
//  void cv::aruco::getBoardObjectAndImagePoints(Ptr_Board board, vector_Mat detectedCorners, Mat detectedIds, Mat& objPoints, Mat& imgPoints)
//
/**
 * Given a board configuration and a set of detected markers, returns the corresponding
 * image points and object points to call solvePnP
 *
 * @param board Marker board layout.
 * @param detectedCorners List of detected marker corners of the board.
 * @param detectedIds List of identifiers for each marker.
 * @param objPoints Vector of vectors of board marker points in the board coordinate space.
 * @param imgPoints Vector of vectors of the projections of board marker corner points.
 */
+ (void)getBoardObjectAndImagePoints:(Board*)board detectedCorners:(NSArray<Mat*>*)detectedCorners detectedIds:(Mat*)detectedIds objPoints:(Mat*)objPoints imgPoints:(Mat*)imgPoints NS_SWIFT_NAME(getBoardObjectAndImagePoints(board:detectedCorners:detectedIds:objPoints:imgPoints:));


//
//  Ptr_Dictionary cv::aruco::getPredefinedDictionary(int dict)
//
/**
 * Returns one of the predefined dictionaries referenced by DICT_*.
 */
+ (Dictionary*)getPredefinedDictionary:(int)dict NS_SWIFT_NAME(getPredefinedDictionary(dict:));


//
//  Ptr_Dictionary cv::aruco::generateCustomDictionary(int nMarkers, int markerSize, int randomSeed = 0)
//
/**
 * @see `generateCustomDictionary`
 */
+ (Dictionary*)custom_dictionary:(int)nMarkers markerSize:(int)markerSize randomSeed:(int)randomSeed NS_SWIFT_NAME(generateCustomDictionary(nMarkers:markerSize:randomSeed:));

/**
 * @see `generateCustomDictionary`
 */
+ (Dictionary*)custom_dictionary:(int)nMarkers markerSize:(int)markerSize NS_SWIFT_NAME(generateCustomDictionary(nMarkers:markerSize:));


//
//  Ptr_Dictionary cv::aruco::generateCustomDictionary(int nMarkers, int markerSize, Ptr_Dictionary baseDictionary, int randomSeed = 0)
//
/**
 * Generates a new customizable marker dictionary
 *
 * @param nMarkers number of markers in the dictionary
 * @param markerSize number of bits per dimension of each markers
 * @param baseDictionary Include the markers in this dictionary at the beginning (optional)
 * @param randomSeed a user supplied seed for theRNG()
 *
 * This function creates a new dictionary composed by nMarkers markers and each markers composed
 * by markerSize x markerSize bits. If baseDictionary is provided, its markers are directly
 * included and the rest are generated based on them. If the size of baseDictionary is higher
 * than nMarkers, only the first nMarkers in baseDictionary are taken and no new marker is added.
 */
+ (Dictionary*)custom_dictionary_from:(int)nMarkers markerSize:(int)markerSize baseDictionary:(Dictionary*)baseDictionary randomSeed:(int)randomSeed NS_SWIFT_NAME(generateCustomDictionary(nMarkers:markerSize:baseDictionary:randomSeed:));

/**
 * Generates a new customizable marker dictionary
 *
 * @param nMarkers number of markers in the dictionary
 * @param markerSize number of bits per dimension of each markers
 * @param baseDictionary Include the markers in this dictionary at the beginning (optional)
 *
 * This function creates a new dictionary composed by nMarkers markers and each markers composed
 * by markerSize x markerSize bits. If baseDictionary is provided, its markers are directly
 * included and the rest are generated based on them. If the size of baseDictionary is higher
 * than nMarkers, only the first nMarkers in baseDictionary are taken and no new marker is added.
 */
+ (Dictionary*)custom_dictionary_from:(int)nMarkers markerSize:(int)markerSize baseDictionary:(Dictionary*)baseDictionary NS_SWIFT_NAME(generateCustomDictionary(nMarkers:markerSize:baseDictionary:));


//
//  int cv::aruco::interpolateCornersCharuco(vector_Mat markerCorners, Mat markerIds, Mat image, Ptr_CharucoBoard board, Mat& charucoCorners, Mat& charucoIds, Mat cameraMatrix = Mat(), Mat distCoeffs = Mat(), int minMarkers = 2)
//
/**
 * Interpolate position of ChArUco board corners
 * @param markerCorners vector of already detected markers corners. For each marker, its four
 * corners are provided, (e.g std::vector<std::vector<cv::Point2f> > ). For N detected markers, the
 * dimensions of this array should be Nx4. The order of the corners should be clockwise.
 * @param markerIds list of identifiers for each marker in corners
 * @param image input image necesary for corner refinement. Note that markers are not detected and
 * should be sent in corners and ids parameters.
 * @param board layout of ChArUco board.
 * @param charucoCorners interpolated chessboard corners
 * @param charucoIds interpolated chessboard corners identifiers
 * @param cameraMatrix optional 3x3 floating-point camera matrix
 * `$$\newcommand{\vecthreethree}[9]{ \begin{bmatrix} #1 & #2 & #3\\\\ #4 & #5 & #6\\\\ #7 & #8 & #9 \end{bmatrix} } A = \vecthreethree{f_x}{0}{c_x}{0}{f_y}{c_y}{0}{0}{1}$$`
 * @param distCoeffs optional vector of distortion coefficients
 * `$$(k_1, k_2, p_1, p_2[, k_3[, k_4, k_5, k_6],[s_1, s_2, s_3, s_4]])$$` of 4, 5, 8 or 12 elements
 * @param minMarkers number of adjacent markers that must be detected to return a charuco corner
 *
 * This function receives the detected markers and returns the 2D position of the chessboard corners
 * from a ChArUco board using the detected Aruco markers. If camera parameters are provided,
 * the process is based in an approximated pose estimation, else it is based on local homography.
 * Only visible corners are returned. For each corner, its corresponding identifier is
 * also returned in charucoIds.
 * The function returns the number of interpolated corners.
 */
+ (int)interpolateCornersCharuco:(NSArray<Mat*>*)markerCorners markerIds:(Mat*)markerIds image:(Mat*)image board:(CharucoBoard*)board charucoCorners:(Mat*)charucoCorners charucoIds:(Mat*)charucoIds cameraMatrix:(Mat*)cameraMatrix distCoeffs:(Mat*)distCoeffs minMarkers:(int)minMarkers NS_SWIFT_NAME(interpolateCornersCharuco(markerCorners:markerIds:image:board:charucoCorners:charucoIds:cameraMatrix:distCoeffs:minMarkers:));

/**
 * Interpolate position of ChArUco board corners
 * @param markerCorners vector of already detected markers corners. For each marker, its four
 * corners are provided, (e.g std::vector<std::vector<cv::Point2f> > ). For N detected markers, the
 * dimensions of this array should be Nx4. The order of the corners should be clockwise.
 * @param markerIds list of identifiers for each marker in corners
 * @param image input image necesary for corner refinement. Note that markers are not detected and
 * should be sent in corners and ids parameters.
 * @param board layout of ChArUco board.
 * @param charucoCorners interpolated chessboard corners
 * @param charucoIds interpolated chessboard corners identifiers
 * @param cameraMatrix optional 3x3 floating-point camera matrix
 * `$$\newcommand{\vecthreethree}[9]{ \begin{bmatrix} #1 & #2 & #3\\\\ #4 & #5 & #6\\\\ #7 & #8 & #9 \end{bmatrix} } A = \vecthreethree{f_x}{0}{c_x}{0}{f_y}{c_y}{0}{0}{1}$$`
 * @param distCoeffs optional vector of distortion coefficients
 * `$$(k_1, k_2, p_1, p_2[, k_3[, k_4, k_5, k_6],[s_1, s_2, s_3, s_4]])$$` of 4, 5, 8 or 12 elements
 *
 * This function receives the detected markers and returns the 2D position of the chessboard corners
 * from a ChArUco board using the detected Aruco markers. If camera parameters are provided,
 * the process is based in an approximated pose estimation, else it is based on local homography.
 * Only visible corners are returned. For each corner, its corresponding identifier is
 * also returned in charucoIds.
 * The function returns the number of interpolated corners.
 */
+ (int)interpolateCornersCharuco:(NSArray<Mat*>*)markerCorners markerIds:(Mat*)markerIds image:(Mat*)image board:(CharucoBoard*)board charucoCorners:(Mat*)charucoCorners charucoIds:(Mat*)charucoIds cameraMatrix:(Mat*)cameraMatrix distCoeffs:(Mat*)distCoeffs NS_SWIFT_NAME(interpolateCornersCharuco(markerCorners:markerIds:image:board:charucoCorners:charucoIds:cameraMatrix:distCoeffs:));

/**
 * Interpolate position of ChArUco board corners
 * @param markerCorners vector of already detected markers corners. For each marker, its four
 * corners are provided, (e.g std::vector<std::vector<cv::Point2f> > ). For N detected markers, the
 * dimensions of this array should be Nx4. The order of the corners should be clockwise.
 * @param markerIds list of identifiers for each marker in corners
 * @param image input image necesary for corner refinement. Note that markers are not detected and
 * should be sent in corners and ids parameters.
 * @param board layout of ChArUco board.
 * @param charucoCorners interpolated chessboard corners
 * @param charucoIds interpolated chessboard corners identifiers
 * @param cameraMatrix optional 3x3 floating-point camera matrix
 * `$$\newcommand{\vecthreethree}[9]{ \begin{bmatrix} #1 & #2 & #3\\\\ #4 & #5 & #6\\\\ #7 & #8 & #9 \end{bmatrix} } A = \vecthreethree{f_x}{0}{c_x}{0}{f_y}{c_y}{0}{0}{1}$$`
 * `$$(k_1, k_2, p_1, p_2[, k_3[, k_4, k_5, k_6],[s_1, s_2, s_3, s_4]])$$` of 4, 5, 8 or 12 elements
 *
 * This function receives the detected markers and returns the 2D position of the chessboard corners
 * from a ChArUco board using the detected Aruco markers. If camera parameters are provided,
 * the process is based in an approximated pose estimation, else it is based on local homography.
 * Only visible corners are returned. For each corner, its corresponding identifier is
 * also returned in charucoIds.
 * The function returns the number of interpolated corners.
 */
+ (int)interpolateCornersCharuco:(NSArray<Mat*>*)markerCorners markerIds:(Mat*)markerIds image:(Mat*)image board:(CharucoBoard*)board charucoCorners:(Mat*)charucoCorners charucoIds:(Mat*)charucoIds cameraMatrix:(Mat*)cameraMatrix NS_SWIFT_NAME(interpolateCornersCharuco(markerCorners:markerIds:image:board:charucoCorners:charucoIds:cameraMatrix:));

/**
 * Interpolate position of ChArUco board corners
 * @param markerCorners vector of already detected markers corners. For each marker, its four
 * corners are provided, (e.g std::vector<std::vector<cv::Point2f> > ). For N detected markers, the
 * dimensions of this array should be Nx4. The order of the corners should be clockwise.
 * @param markerIds list of identifiers for each marker in corners
 * @param image input image necesary for corner refinement. Note that markers are not detected and
 * should be sent in corners and ids parameters.
 * @param board layout of ChArUco board.
 * @param charucoCorners interpolated chessboard corners
 * @param charucoIds interpolated chessboard corners identifiers
 * `$$\newcommand{\vecthreethree}[9]{ \begin{bmatrix} #1 & #2 & #3\\\\ #4 & #5 & #6\\\\ #7 & #8 & #9 \end{bmatrix} } A = \vecthreethree{f_x}{0}{c_x}{0}{f_y}{c_y}{0}{0}{1}$$`
 * `$$(k_1, k_2, p_1, p_2[, k_3[, k_4, k_5, k_6],[s_1, s_2, s_3, s_4]])$$` of 4, 5, 8 or 12 elements
 *
 * This function receives the detected markers and returns the 2D position of the chessboard corners
 * from a ChArUco board using the detected Aruco markers. If camera parameters are provided,
 * the process is based in an approximated pose estimation, else it is based on local homography.
 * Only visible corners are returned. For each corner, its corresponding identifier is
 * also returned in charucoIds.
 * The function returns the number of interpolated corners.
 */
+ (int)interpolateCornersCharuco:(NSArray<Mat*>*)markerCorners markerIds:(Mat*)markerIds image:(Mat*)image board:(CharucoBoard*)board charucoCorners:(Mat*)charucoCorners charucoIds:(Mat*)charucoIds NS_SWIFT_NAME(interpolateCornersCharuco(markerCorners:markerIds:image:board:charucoCorners:charucoIds:));


//
//  bool cv::aruco::estimatePoseCharucoBoard(Mat charucoCorners, Mat charucoIds, Ptr_CharucoBoard board, Mat cameraMatrix, Mat distCoeffs, Mat& rvec, Mat& tvec, bool useExtrinsicGuess = false)
//
/**
 * Pose estimation for a ChArUco board given some of their corners
 * @param charucoCorners vector of detected charuco corners
 * @param charucoIds list of identifiers for each corner in charucoCorners
 * @param board layout of ChArUco board.
 * @param cameraMatrix input 3x3 floating-point camera matrix
 * `$$\newcommand{\vecthreethree}[9]{ \begin{bmatrix} #1 & #2 & #3\\\\ #4 & #5 & #6\\\\ #7 & #8 & #9 \end{bmatrix} } A = \vecthreethree{f_x}{0}{c_x}{0}{f_y}{c_y}{0}{0}{1}$$`
 * @param distCoeffs vector of distortion coefficients
 * `$$(k_1, k_2, p_1, p_2[, k_3[, k_4, k_5, k_6],[s_1, s_2, s_3, s_4]])$$` of 4, 5, 8 or 12 elements
 * @param rvec Output vector (e.g. cv::Mat) corresponding to the rotation vector of the board
 * (see cv::Rodrigues).
 * @param tvec Output vector (e.g. cv::Mat) corresponding to the translation vector of the board.
 * @param useExtrinsicGuess defines whether initial guess for \b rvec and \b tvec will be used or not.
 *
 * This function estimates a Charuco board pose from some detected corners.
 * The function checks if the input corners are enough and valid to perform pose estimation.
 * If pose estimation is valid, returns true, else returns false.
 */
+ (BOOL)estimatePoseCharucoBoard:(Mat*)charucoCorners charucoIds:(Mat*)charucoIds board:(CharucoBoard*)board cameraMatrix:(Mat*)cameraMatrix distCoeffs:(Mat*)distCoeffs rvec:(Mat*)rvec tvec:(Mat*)tvec useExtrinsicGuess:(BOOL)useExtrinsicGuess NS_SWIFT_NAME(estimatePoseCharucoBoard(charucoCorners:charucoIds:board:cameraMatrix:distCoeffs:rvec:tvec:useExtrinsicGuess:));

/**
 * Pose estimation for a ChArUco board given some of their corners
 * @param charucoCorners vector of detected charuco corners
 * @param charucoIds list of identifiers for each corner in charucoCorners
 * @param board layout of ChArUco board.
 * @param cameraMatrix input 3x3 floating-point camera matrix
 * `$$\newcommand{\vecthreethree}[9]{ \begin{bmatrix} #1 & #2 & #3\\\\ #4 & #5 & #6\\\\ #7 & #8 & #9 \end{bmatrix} } A = \vecthreethree{f_x}{0}{c_x}{0}{f_y}{c_y}{0}{0}{1}$$`
 * @param distCoeffs vector of distortion coefficients
 * `$$(k_1, k_2, p_1, p_2[, k_3[, k_4, k_5, k_6],[s_1, s_2, s_3, s_4]])$$` of 4, 5, 8 or 12 elements
 * @param rvec Output vector (e.g. cv::Mat) corresponding to the rotation vector of the board
 * (see cv::Rodrigues).
 * @param tvec Output vector (e.g. cv::Mat) corresponding to the translation vector of the board.
 *
 * This function estimates a Charuco board pose from some detected corners.
 * The function checks if the input corners are enough and valid to perform pose estimation.
 * If pose estimation is valid, returns true, else returns false.
 */
+ (BOOL)estimatePoseCharucoBoard:(Mat*)charucoCorners charucoIds:(Mat*)charucoIds board:(CharucoBoard*)board cameraMatrix:(Mat*)cameraMatrix distCoeffs:(Mat*)distCoeffs rvec:(Mat*)rvec tvec:(Mat*)tvec NS_SWIFT_NAME(estimatePoseCharucoBoard(charucoCorners:charucoIds:board:cameraMatrix:distCoeffs:rvec:tvec:));


//
//  void cv::aruco::drawDetectedCornersCharuco(Mat& image, Mat charucoCorners, Mat charucoIds = Mat(), Scalar cornerColor = Scalar(255, 0, 0))
//
/**
 * Draws a set of Charuco corners
 * @param image input/output image. It must have 1 or 3 channels. The number of channels is not
 * altered.
 * @param charucoCorners vector of detected charuco corners
 * @param charucoIds list of identifiers for each corner in charucoCorners
 * @param cornerColor color of the square surrounding each corner
 *
 * This function draws a set of detected Charuco corners. If identifiers vector is provided, it also
 * draws the id of each corner.
 */
+ (void)drawDetectedCornersCharuco:(Mat*)image charucoCorners:(Mat*)charucoCorners charucoIds:(Mat*)charucoIds cornerColor:(Scalar*)cornerColor NS_SWIFT_NAME(drawDetectedCornersCharuco(image:charucoCorners:charucoIds:cornerColor:));

/**
 * Draws a set of Charuco corners
 * @param image input/output image. It must have 1 or 3 channels. The number of channels is not
 * altered.
 * @param charucoCorners vector of detected charuco corners
 * @param charucoIds list of identifiers for each corner in charucoCorners
 *
 * This function draws a set of detected Charuco corners. If identifiers vector is provided, it also
 * draws the id of each corner.
 */
+ (void)drawDetectedCornersCharuco:(Mat*)image charucoCorners:(Mat*)charucoCorners charucoIds:(Mat*)charucoIds NS_SWIFT_NAME(drawDetectedCornersCharuco(image:charucoCorners:charucoIds:));

/**
 * Draws a set of Charuco corners
 * @param image input/output image. It must have 1 or 3 channels. The number of channels is not
 * altered.
 * @param charucoCorners vector of detected charuco corners
 *
 * This function draws a set of detected Charuco corners. If identifiers vector is provided, it also
 * draws the id of each corner.
 */
+ (void)drawDetectedCornersCharuco:(Mat*)image charucoCorners:(Mat*)charucoCorners NS_SWIFT_NAME(drawDetectedCornersCharuco(image:charucoCorners:));


//
//  double cv::aruco::calibrateCameraCharuco(vector_Mat charucoCorners, vector_Mat charucoIds, Ptr_CharucoBoard board, Size imageSize, Mat& cameraMatrix, Mat& distCoeffs, vector_Mat& rvecs, vector_Mat& tvecs, Mat& stdDeviationsIntrinsics, Mat& stdDeviationsExtrinsics, Mat& perViewErrors, int flags = 0, TermCriteria criteria = TermCriteria(TermCriteria::COUNT + TermCriteria::EPS, 30, DBL_EPSILON))
//
/**
 * Calibrate a camera using Charuco corners
 *
 * @param charucoCorners vector of detected charuco corners per frame
 * @param charucoIds list of identifiers for each corner in charucoCorners per frame
 * @param board Marker Board layout
 * @param imageSize input image size
 * @param cameraMatrix Output 3x3 floating-point camera matrix
 * `$$\newcommand{\vecthreethree}[9]{ \begin{bmatrix} #1 & #2 & #3\\\\ #4 & #5 & #6\\\\ #7 & #8 & #9 \end{bmatrix} } A = \vecthreethree{f_x}{0}{c_x}{0}{f_y}{c_y}{0}{0}{1}$$` . If CV\_CALIB\_USE\_INTRINSIC\_GUESS
 * and/or CV_CALIB_FIX_ASPECT_RATIO are specified, some or all of fx, fy, cx, cy must be
 * initialized before calling the function.
 * @param distCoeffs Output vector of distortion coefficients
 * `$$(k_1, k_2, p_1, p_2[, k_3[, k_4, k_5, k_6],[s_1, s_2, s_3, s_4]])$$` of 4, 5, 8 or 12 elements
 * @param rvecs Output vector of rotation vectors (see Rodrigues ) estimated for each board view
 * (e.g. std::vector<cv::Mat>>). That is, each k-th rotation vector together with the corresponding
 * k-th translation vector (see the next output parameter description) brings the board pattern
 * from the model coordinate space (in which object points are specified) to the world coordinate
 * space, that is, a real position of the board pattern in the k-th pattern view (k=0.. *M* -1).
 * @param tvecs Output vector of translation vectors estimated for each pattern view.
 * @param stdDeviationsIntrinsics Output vector of standard deviations estimated for intrinsic parameters.
 * Order of deviations values:
 * `$$(f_x, f_y, c_x, c_y, k_1, k_2, p_1, p_2, k_3, k_4, k_5, k_6 , s_1, s_2, s_3,
 * s_4, \tau_x, \tau_y)$$` If one of parameters is not estimated, it's deviation is equals to zero.
 * @param stdDeviationsExtrinsics Output vector of standard deviations estimated for extrinsic parameters.
 * Order of deviations values: `$$(R_1, T_1, \dotsc , R_M, T_M)$$` where M is number of pattern views,
 * `$$R_i, T_i$$` are concatenated 1x3 vectors.
 * @param perViewErrors Output vector of average re-projection errors estimated for each pattern view.
 * @param flags flags Different flags  for the calibration process (see #calibrateCamera for details).
 * @param criteria Termination criteria for the iterative optimization algorithm.
 *
 * This function calibrates a camera using a set of corners of a  Charuco Board. The function
 * receives a list of detected corners and its identifiers from several views of the Board.
 * The function returns the final re-projection error.
 */
+ (double)calibrateCameraCharucoExtended:(NSArray<Mat*>*)charucoCorners charucoIds:(NSArray<Mat*>*)charucoIds board:(CharucoBoard*)board imageSize:(Size2i*)imageSize cameraMatrix:(Mat*)cameraMatrix distCoeffs:(Mat*)distCoeffs rvecs:(NSMutableArray<Mat*>*)rvecs tvecs:(NSMutableArray<Mat*>*)tvecs stdDeviationsIntrinsics:(Mat*)stdDeviationsIntrinsics stdDeviationsExtrinsics:(Mat*)stdDeviationsExtrinsics perViewErrors:(Mat*)perViewErrors flags:(int)flags criteria:(TermCriteria*)criteria NS_SWIFT_NAME(calibrateCameraCharuco(charucoCorners:charucoIds:board:imageSize:cameraMatrix:distCoeffs:rvecs:tvecs:stdDeviationsIntrinsics:stdDeviationsExtrinsics:perViewErrors:flags:criteria:));

/**
 * Calibrate a camera using Charuco corners
 *
 * @param charucoCorners vector of detected charuco corners per frame
 * @param charucoIds list of identifiers for each corner in charucoCorners per frame
 * @param board Marker Board layout
 * @param imageSize input image size
 * @param cameraMatrix Output 3x3 floating-point camera matrix
 * `$$\newcommand{\vecthreethree}[9]{ \begin{bmatrix} #1 & #2 & #3\\\\ #4 & #5 & #6\\\\ #7 & #8 & #9 \end{bmatrix} } A = \vecthreethree{f_x}{0}{c_x}{0}{f_y}{c_y}{0}{0}{1}$$` . If CV\_CALIB\_USE\_INTRINSIC\_GUESS
 * and/or CV_CALIB_FIX_ASPECT_RATIO are specified, some or all of fx, fy, cx, cy must be
 * initialized before calling the function.
 * @param distCoeffs Output vector of distortion coefficients
 * `$$(k_1, k_2, p_1, p_2[, k_3[, k_4, k_5, k_6],[s_1, s_2, s_3, s_4]])$$` of 4, 5, 8 or 12 elements
 * @param rvecs Output vector of rotation vectors (see Rodrigues ) estimated for each board view
 * (e.g. std::vector<cv::Mat>>). That is, each k-th rotation vector together with the corresponding
 * k-th translation vector (see the next output parameter description) brings the board pattern
 * from the model coordinate space (in which object points are specified) to the world coordinate
 * space, that is, a real position of the board pattern in the k-th pattern view (k=0.. *M* -1).
 * @param tvecs Output vector of translation vectors estimated for each pattern view.
 * @param stdDeviationsIntrinsics Output vector of standard deviations estimated for intrinsic parameters.
 * Order of deviations values:
 * `$$(f_x, f_y, c_x, c_y, k_1, k_2, p_1, p_2, k_3, k_4, k_5, k_6 , s_1, s_2, s_3,
 * s_4, \tau_x, \tau_y)$$` If one of parameters is not estimated, it's deviation is equals to zero.
 * @param stdDeviationsExtrinsics Output vector of standard deviations estimated for extrinsic parameters.
 * Order of deviations values: `$$(R_1, T_1, \dotsc , R_M, T_M)$$` where M is number of pattern views,
 * `$$R_i, T_i$$` are concatenated 1x3 vectors.
 * @param perViewErrors Output vector of average re-projection errors estimated for each pattern view.
 * @param flags flags Different flags  for the calibration process (see #calibrateCamera for details).
 *
 * This function calibrates a camera using a set of corners of a  Charuco Board. The function
 * receives a list of detected corners and its identifiers from several views of the Board.
 * The function returns the final re-projection error.
 */
+ (double)calibrateCameraCharucoExtended:(NSArray<Mat*>*)charucoCorners charucoIds:(NSArray<Mat*>*)charucoIds board:(CharucoBoard*)board imageSize:(Size2i*)imageSize cameraMatrix:(Mat*)cameraMatrix distCoeffs:(Mat*)distCoeffs rvecs:(NSMutableArray<Mat*>*)rvecs tvecs:(NSMutableArray<Mat*>*)tvecs stdDeviationsIntrinsics:(Mat*)stdDeviationsIntrinsics stdDeviationsExtrinsics:(Mat*)stdDeviationsExtrinsics perViewErrors:(Mat*)perViewErrors flags:(int)flags NS_SWIFT_NAME(calibrateCameraCharuco(charucoCorners:charucoIds:board:imageSize:cameraMatrix:distCoeffs:rvecs:tvecs:stdDeviationsIntrinsics:stdDeviationsExtrinsics:perViewErrors:flags:));

/**
 * Calibrate a camera using Charuco corners
 *
 * @param charucoCorners vector of detected charuco corners per frame
 * @param charucoIds list of identifiers for each corner in charucoCorners per frame
 * @param board Marker Board layout
 * @param imageSize input image size
 * @param cameraMatrix Output 3x3 floating-point camera matrix
 * `$$\newcommand{\vecthreethree}[9]{ \begin{bmatrix} #1 & #2 & #3\\\\ #4 & #5 & #6\\\\ #7 & #8 & #9 \end{bmatrix} } A = \vecthreethree{f_x}{0}{c_x}{0}{f_y}{c_y}{0}{0}{1}$$` . If CV\_CALIB\_USE\_INTRINSIC\_GUESS
 * and/or CV_CALIB_FIX_ASPECT_RATIO are specified, some or all of fx, fy, cx, cy must be
 * initialized before calling the function.
 * @param distCoeffs Output vector of distortion coefficients
 * `$$(k_1, k_2, p_1, p_2[, k_3[, k_4, k_5, k_6],[s_1, s_2, s_3, s_4]])$$` of 4, 5, 8 or 12 elements
 * @param rvecs Output vector of rotation vectors (see Rodrigues ) estimated for each board view
 * (e.g. std::vector<cv::Mat>>). That is, each k-th rotation vector together with the corresponding
 * k-th translation vector (see the next output parameter description) brings the board pattern
 * from the model coordinate space (in which object points are specified) to the world coordinate
 * space, that is, a real position of the board pattern in the k-th pattern view (k=0.. *M* -1).
 * @param tvecs Output vector of translation vectors estimated for each pattern view.
 * @param stdDeviationsIntrinsics Output vector of standard deviations estimated for intrinsic parameters.
 * Order of deviations values:
 * `$$(f_x, f_y, c_x, c_y, k_1, k_2, p_1, p_2, k_3, k_4, k_5, k_6 , s_1, s_2, s_3,
 * s_4, \tau_x, \tau_y)$$` If one of parameters is not estimated, it's deviation is equals to zero.
 * @param stdDeviationsExtrinsics Output vector of standard deviations estimated for extrinsic parameters.
 * Order of deviations values: `$$(R_1, T_1, \dotsc , R_M, T_M)$$` where M is number of pattern views,
 * `$$R_i, T_i$$` are concatenated 1x3 vectors.
 * @param perViewErrors Output vector of average re-projection errors estimated for each pattern view.
 *
 * This function calibrates a camera using a set of corners of a  Charuco Board. The function
 * receives a list of detected corners and its identifiers from several views of the Board.
 * The function returns the final re-projection error.
 */
+ (double)calibrateCameraCharucoExtended:(NSArray<Mat*>*)charucoCorners charucoIds:(NSArray<Mat*>*)charucoIds board:(CharucoBoard*)board imageSize:(Size2i*)imageSize cameraMatrix:(Mat*)cameraMatrix distCoeffs:(Mat*)distCoeffs rvecs:(NSMutableArray<Mat*>*)rvecs tvecs:(NSMutableArray<Mat*>*)tvecs stdDeviationsIntrinsics:(Mat*)stdDeviationsIntrinsics stdDeviationsExtrinsics:(Mat*)stdDeviationsExtrinsics perViewErrors:(Mat*)perViewErrors NS_SWIFT_NAME(calibrateCameraCharuco(charucoCorners:charucoIds:board:imageSize:cameraMatrix:distCoeffs:rvecs:tvecs:stdDeviationsIntrinsics:stdDeviationsExtrinsics:perViewErrors:));


//
//  double cv::aruco::calibrateCameraCharuco(vector_Mat charucoCorners, vector_Mat charucoIds, Ptr_CharucoBoard board, Size imageSize, Mat& cameraMatrix, Mat& distCoeffs, vector_Mat& rvecs = vector_Mat(), vector_Mat& tvecs = vector_Mat(), int flags = 0, TermCriteria criteria = TermCriteria(TermCriteria::COUNT + TermCriteria::EPS, 30, DBL_EPSILON))
//
/**
 * It's the same function as #calibrateCameraCharuco but without calibration error estimation.
 */
+ (double)calibrateCameraCharuco:(NSArray<Mat*>*)charucoCorners charucoIds:(NSArray<Mat*>*)charucoIds board:(CharucoBoard*)board imageSize:(Size2i*)imageSize cameraMatrix:(Mat*)cameraMatrix distCoeffs:(Mat*)distCoeffs rvecs:(NSMutableArray<Mat*>*)rvecs tvecs:(NSMutableArray<Mat*>*)tvecs flags:(int)flags criteria:(TermCriteria*)criteria NS_SWIFT_NAME(calibrateCameraCharuco(charucoCorners:charucoIds:board:imageSize:cameraMatrix:distCoeffs:rvecs:tvecs:flags:criteria:));

/**
 * It's the same function as #calibrateCameraCharuco but without calibration error estimation.
 */
+ (double)calibrateCameraCharuco:(NSArray<Mat*>*)charucoCorners charucoIds:(NSArray<Mat*>*)charucoIds board:(CharucoBoard*)board imageSize:(Size2i*)imageSize cameraMatrix:(Mat*)cameraMatrix distCoeffs:(Mat*)distCoeffs rvecs:(NSMutableArray<Mat*>*)rvecs tvecs:(NSMutableArray<Mat*>*)tvecs flags:(int)flags NS_SWIFT_NAME(calibrateCameraCharuco(charucoCorners:charucoIds:board:imageSize:cameraMatrix:distCoeffs:rvecs:tvecs:flags:));

/**
 * It's the same function as #calibrateCameraCharuco but without calibration error estimation.
 */
+ (double)calibrateCameraCharuco:(NSArray<Mat*>*)charucoCorners charucoIds:(NSArray<Mat*>*)charucoIds board:(CharucoBoard*)board imageSize:(Size2i*)imageSize cameraMatrix:(Mat*)cameraMatrix distCoeffs:(Mat*)distCoeffs rvecs:(NSMutableArray<Mat*>*)rvecs tvecs:(NSMutableArray<Mat*>*)tvecs NS_SWIFT_NAME(calibrateCameraCharuco(charucoCorners:charucoIds:board:imageSize:cameraMatrix:distCoeffs:rvecs:tvecs:));

/**
 * It's the same function as #calibrateCameraCharuco but without calibration error estimation.
 */
+ (double)calibrateCameraCharuco:(NSArray<Mat*>*)charucoCorners charucoIds:(NSArray<Mat*>*)charucoIds board:(CharucoBoard*)board imageSize:(Size2i*)imageSize cameraMatrix:(Mat*)cameraMatrix distCoeffs:(Mat*)distCoeffs rvecs:(NSMutableArray<Mat*>*)rvecs NS_SWIFT_NAME(calibrateCameraCharuco(charucoCorners:charucoIds:board:imageSize:cameraMatrix:distCoeffs:rvecs:));

/**
 * It's the same function as #calibrateCameraCharuco but without calibration error estimation.
 */
+ (double)calibrateCameraCharuco:(NSArray<Mat*>*)charucoCorners charucoIds:(NSArray<Mat*>*)charucoIds board:(CharucoBoard*)board imageSize:(Size2i*)imageSize cameraMatrix:(Mat*)cameraMatrix distCoeffs:(Mat*)distCoeffs NS_SWIFT_NAME(calibrateCameraCharuco(charucoCorners:charucoIds:board:imageSize:cameraMatrix:distCoeffs:));


//
//  void cv::aruco::detectCharucoDiamond(Mat image, vector_Mat markerCorners, Mat markerIds, float squareMarkerLengthRate, vector_Mat& diamondCorners, Mat& diamondIds, Mat cameraMatrix = Mat(), Mat distCoeffs = Mat())
//
/**
 * Detect ChArUco Diamond markers
 *
 * @param image input image necessary for corner subpixel.
 * @param markerCorners list of detected marker corners from detectMarkers function.
 * @param markerIds list of marker ids in markerCorners.
 * @param squareMarkerLengthRate rate between square and marker length:
 * squareMarkerLengthRate = squareLength/markerLength. The real units are not necessary.
 * @param diamondCorners output list of detected diamond corners (4 corners per diamond). The order
 * is the same than in marker corners: top left, top right, bottom right and bottom left. Similar
 * format than the corners returned by detectMarkers (e.g std::vector<std::vector<cv::Point2f> > ).
 * @param diamondIds ids of the diamonds in diamondCorners. The id of each diamond is in fact of
 * type Vec4i, so each diamond has 4 ids, which are the ids of the aruco markers composing the
 * diamond.
 * @param cameraMatrix Optional camera calibration matrix.
 * @param distCoeffs Optional camera distortion coefficients.
 *
 * This function detects Diamond markers from the previous detected ArUco markers. The diamonds
 * are returned in the diamondCorners and diamondIds parameters. If camera calibration parameters
 * are provided, the diamond search is based on reprojection. If not, diamond search is based on
 * homography. Homography is faster than reprojection but can slightly reduce the detection rate.
 */
+ (void)detectCharucoDiamond:(Mat*)image markerCorners:(NSArray<Mat*>*)markerCorners markerIds:(Mat*)markerIds squareMarkerLengthRate:(float)squareMarkerLengthRate diamondCorners:(NSMutableArray<Mat*>*)diamondCorners diamondIds:(Mat*)diamondIds cameraMatrix:(Mat*)cameraMatrix distCoeffs:(Mat*)distCoeffs NS_SWIFT_NAME(detectCharucoDiamond(image:markerCorners:markerIds:squareMarkerLengthRate:diamondCorners:diamondIds:cameraMatrix:distCoeffs:));

/**
 * Detect ChArUco Diamond markers
 *
 * @param image input image necessary for corner subpixel.
 * @param markerCorners list of detected marker corners from detectMarkers function.
 * @param markerIds list of marker ids in markerCorners.
 * @param squareMarkerLengthRate rate between square and marker length:
 * squareMarkerLengthRate = squareLength/markerLength. The real units are not necessary.
 * @param diamondCorners output list of detected diamond corners (4 corners per diamond). The order
 * is the same than in marker corners: top left, top right, bottom right and bottom left. Similar
 * format than the corners returned by detectMarkers (e.g std::vector<std::vector<cv::Point2f> > ).
 * @param diamondIds ids of the diamonds in diamondCorners. The id of each diamond is in fact of
 * type Vec4i, so each diamond has 4 ids, which are the ids of the aruco markers composing the
 * diamond.
 * @param cameraMatrix Optional camera calibration matrix.
 *
 * This function detects Diamond markers from the previous detected ArUco markers. The diamonds
 * are returned in the diamondCorners and diamondIds parameters. If camera calibration parameters
 * are provided, the diamond search is based on reprojection. If not, diamond search is based on
 * homography. Homography is faster than reprojection but can slightly reduce the detection rate.
 */
+ (void)detectCharucoDiamond:(Mat*)image markerCorners:(NSArray<Mat*>*)markerCorners markerIds:(Mat*)markerIds squareMarkerLengthRate:(float)squareMarkerLengthRate diamondCorners:(NSMutableArray<Mat*>*)diamondCorners diamondIds:(Mat*)diamondIds cameraMatrix:(Mat*)cameraMatrix NS_SWIFT_NAME(detectCharucoDiamond(image:markerCorners:markerIds:squareMarkerLengthRate:diamondCorners:diamondIds:cameraMatrix:));

/**
 * Detect ChArUco Diamond markers
 *
 * @param image input image necessary for corner subpixel.
 * @param markerCorners list of detected marker corners from detectMarkers function.
 * @param markerIds list of marker ids in markerCorners.
 * @param squareMarkerLengthRate rate between square and marker length:
 * squareMarkerLengthRate = squareLength/markerLength. The real units are not necessary.
 * @param diamondCorners output list of detected diamond corners (4 corners per diamond). The order
 * is the same than in marker corners: top left, top right, bottom right and bottom left. Similar
 * format than the corners returned by detectMarkers (e.g std::vector<std::vector<cv::Point2f> > ).
 * @param diamondIds ids of the diamonds in diamondCorners. The id of each diamond is in fact of
 * type Vec4i, so each diamond has 4 ids, which are the ids of the aruco markers composing the
 * diamond.
 *
 * This function detects Diamond markers from the previous detected ArUco markers. The diamonds
 * are returned in the diamondCorners and diamondIds parameters. If camera calibration parameters
 * are provided, the diamond search is based on reprojection. If not, diamond search is based on
 * homography. Homography is faster than reprojection but can slightly reduce the detection rate.
 */
+ (void)detectCharucoDiamond:(Mat*)image markerCorners:(NSArray<Mat*>*)markerCorners markerIds:(Mat*)markerIds squareMarkerLengthRate:(float)squareMarkerLengthRate diamondCorners:(NSMutableArray<Mat*>*)diamondCorners diamondIds:(Mat*)diamondIds NS_SWIFT_NAME(detectCharucoDiamond(image:markerCorners:markerIds:squareMarkerLengthRate:diamondCorners:diamondIds:));


//
//  void cv::aruco::drawDetectedDiamonds(Mat& image, vector_Mat diamondCorners, Mat diamondIds = Mat(), Scalar borderColor = Scalar(0, 0, 255))
//
/**
 * Draw a set of detected ChArUco Diamond markers
 *
 * @param image input/output image. It must have 1 or 3 channels. The number of channels is not
 * altered.
 * @param diamondCorners positions of diamond corners in the same format returned by
 * detectCharucoDiamond(). (e.g std::vector<std::vector<cv::Point2f> > ). For N detected markers,
 * the dimensions of this array should be Nx4. The order of the corners should be clockwise.
 * @param diamondIds vector of identifiers for diamonds in diamondCorners, in the same format
 * returned by detectCharucoDiamond() (e.g. std::vector<Vec4i>).
 * Optional, if not provided, ids are not painted.
 * @param borderColor color of marker borders. Rest of colors (text color and first corner color)
 * are calculated based on this one.
 *
 * Given an array of detected diamonds, this functions draws them in the image. The marker borders
 * are painted and the markers identifiers if provided.
 * Useful for debugging purposes.
 */
+ (void)drawDetectedDiamonds:(Mat*)image diamondCorners:(NSArray<Mat*>*)diamondCorners diamondIds:(Mat*)diamondIds borderColor:(Scalar*)borderColor NS_SWIFT_NAME(drawDetectedDiamonds(image:diamondCorners:diamondIds:borderColor:));

/**
 * Draw a set of detected ChArUco Diamond markers
 *
 * @param image input/output image. It must have 1 or 3 channels. The number of channels is not
 * altered.
 * @param diamondCorners positions of diamond corners in the same format returned by
 * detectCharucoDiamond(). (e.g std::vector<std::vector<cv::Point2f> > ). For N detected markers,
 * the dimensions of this array should be Nx4. The order of the corners should be clockwise.
 * @param diamondIds vector of identifiers for diamonds in diamondCorners, in the same format
 * returned by detectCharucoDiamond() (e.g. std::vector<Vec4i>).
 * Optional, if not provided, ids are not painted.
 * are calculated based on this one.
 *
 * Given an array of detected diamonds, this functions draws them in the image. The marker borders
 * are painted and the markers identifiers if provided.
 * Useful for debugging purposes.
 */
+ (void)drawDetectedDiamonds:(Mat*)image diamondCorners:(NSArray<Mat*>*)diamondCorners diamondIds:(Mat*)diamondIds NS_SWIFT_NAME(drawDetectedDiamonds(image:diamondCorners:diamondIds:));

/**
 * Draw a set of detected ChArUco Diamond markers
 *
 * @param image input/output image. It must have 1 or 3 channels. The number of channels is not
 * altered.
 * @param diamondCorners positions of diamond corners in the same format returned by
 * detectCharucoDiamond(). (e.g std::vector<std::vector<cv::Point2f> > ). For N detected markers,
 * the dimensions of this array should be Nx4. The order of the corners should be clockwise.
 * returned by detectCharucoDiamond() (e.g. std::vector<Vec4i>).
 * Optional, if not provided, ids are not painted.
 * are calculated based on this one.
 *
 * Given an array of detected diamonds, this functions draws them in the image. The marker borders
 * are painted and the markers identifiers if provided.
 * Useful for debugging purposes.
 */
+ (void)drawDetectedDiamonds:(Mat*)image diamondCorners:(NSArray<Mat*>*)diamondCorners NS_SWIFT_NAME(drawDetectedDiamonds(image:diamondCorners:));


//
//  void cv::aruco::drawCharucoDiamond(Ptr_Dictionary dictionary, Vec4i ids, int squareLength, int markerLength, Mat& img, int marginSize = 0, int borderBits = 1)
//
/**
 * Draw a ChArUco Diamond marker
 *
 * @param dictionary dictionary of markers indicating the type of markers.
 * @param ids list of 4 ids for each ArUco marker in the ChArUco marker.
 * @param squareLength size of the chessboard squares in pixels.
 * @param markerLength size of the markers in pixels.
 * @param img output image with the marker. The size of this image will be
 * 3*squareLength + 2*marginSize,.
 * @param marginSize minimum margins (in pixels) of the marker in the output image
 * @param borderBits width of the marker borders.
 *
 * This function return the image of a ChArUco marker, ready to be printed.
 */
+ (void)drawCharucoDiamond:(Dictionary*)dictionary ids:(Int4*)ids squareLength:(int)squareLength markerLength:(int)markerLength img:(Mat*)img marginSize:(int)marginSize borderBits:(int)borderBits NS_SWIFT_NAME(drawCharucoDiamond(dictionary:ids:squareLength:markerLength:img:marginSize:borderBits:));

/**
 * Draw a ChArUco Diamond marker
 *
 * @param dictionary dictionary of markers indicating the type of markers.
 * @param ids list of 4 ids for each ArUco marker in the ChArUco marker.
 * @param squareLength size of the chessboard squares in pixels.
 * @param markerLength size of the markers in pixels.
 * @param img output image with the marker. The size of this image will be
 * 3*squareLength + 2*marginSize,.
 * @param marginSize minimum margins (in pixels) of the marker in the output image
 *
 * This function return the image of a ChArUco marker, ready to be printed.
 */
+ (void)drawCharucoDiamond:(Dictionary*)dictionary ids:(Int4*)ids squareLength:(int)squareLength markerLength:(int)markerLength img:(Mat*)img marginSize:(int)marginSize NS_SWIFT_NAME(drawCharucoDiamond(dictionary:ids:squareLength:markerLength:img:marginSize:));

/**
 * Draw a ChArUco Diamond marker
 *
 * @param dictionary dictionary of markers indicating the type of markers.
 * @param ids list of 4 ids for each ArUco marker in the ChArUco marker.
 * @param squareLength size of the chessboard squares in pixels.
 * @param markerLength size of the markers in pixels.
 * @param img output image with the marker. The size of this image will be
 * 3*squareLength + 2*marginSize,.
 *
 * This function return the image of a ChArUco marker, ready to be printed.
 */
+ (void)drawCharucoDiamond:(Dictionary*)dictionary ids:(Int4*)ids squareLength:(int)squareLength markerLength:(int)markerLength img:(Mat*)img NS_SWIFT_NAME(drawCharucoDiamond(dictionary:ids:squareLength:markerLength:img:));


//
//  bool cv::aruco::testCharucoCornersCollinear(Ptr_CharucoBoard _board, Mat _charucoIds)
//
/**
 * test whether the ChArUco markers are collinear
 *
 * @param _board layout of ChArUco board.
 * @param _charucoIds list of identifiers for each corner in charucoCorners per frame.
 * @return bool value, 1 (true) if detected corners form a line, 0 (false) if they do not.
 *       solvePnP, calibration functions will fail if the corners are collinear (true).
 *
 * The number of ids in charucoIDs should be <= the number of chessboard corners in the board.  This functions checks whether the charuco corners are on a straight line (returns true, if so), or not (false).  Axis parallel, as well as diagonal and other straight lines detected.  Degenerate cases: for number of charucoIDs <= 2, the function returns true.
 */
+ (BOOL)testCharucoCornersCollinear:(CharucoBoard*)_board _charucoIds:(Mat*)_charucoIds NS_SWIFT_NAME(testCharucoCornersCollinear(_board:_charucoIds:));



@end

NS_ASSUME_NONNULL_END


