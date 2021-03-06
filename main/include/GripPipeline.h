#pragma once
#include "vision/VisionPipeline.h"

#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/features2d.hpp>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <vector>
#include <string>
#include <math.h>

namespace grip {

/**
* GripPipeline class.
* 
* An OpenCV pipeline generated by GRIP.
*/
class GripPipeline : public frc::VisionPipeline {
	private:
		cv::Mat resizeImageOutput;
		cv::Mat hslThresholdOutput;
		cv::Mat cvErode0Output;
		cv::Mat cvDilate0Output;
		std::vector<std::vector<cv::Point> > findContoursOutput;
		std::vector<std::vector<cv::Point> > filterContoursOutput;
		cv::Mat cvErode1Output;
		cv::Mat cvDilate1Output;
		cv::Mat maskOutput;
		void resizeImage(cv::Mat &, double , double , int , cv::Mat &);
		void hslThreshold(cv::Mat &, double [], double [], double [], cv::Mat &);
		void findContours(cv::Mat &, bool , std::vector<std::vector<cv::Point> > &);
		void filterContours(std::vector<std::vector<cv::Point> > &, double , double , double , double , double , double , double [], double , double , double , double , std::vector<std::vector<cv::Point> > &);
		void cvErode(cv::Mat &, cv::Mat &, cv::Point &, double , int , cv::Scalar &, cv::Mat &);
		void cvDilate(cv::Mat &, cv::Mat &, cv::Point &, double , int , cv::Scalar &, cv::Mat &);
		void mask(cv::Mat &, cv::Mat &, cv::Mat &);

	public:
		GripPipeline();
		void Process(cv::Mat& source0) override;
		cv::Mat* GetResizeImageOutput();
		cv::Mat* GetHslThresholdOutput();
		cv::Mat* GetCvErode0Output();
		cv::Mat* GetCvDilate0Output();
		std::vector<std::vector<cv::Point> >* GetFindContoursOutput();
		std::vector<std::vector<cv::Point> >* GetFilterContoursOutput();
		cv::Mat* GetCvErode1Output();
		cv::Mat* GetCvDilate1Output();
		cv::Mat* GetMaskOutput();
};


} // end namespace grip


