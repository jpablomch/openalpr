#ifndef OPENALPR_LOGGING_VIDEOBUFFER_H
#define OPENALPR_LOGGING_VIDEOBUFFER_H
#include "videobuffer.h"

//#include <log4cplus/logger.h>
//#include <log4cplus/loggingmacros.h>
#include <glog/logging.h>

class LoggingVideoDispatcher : public VideoDispatcher
{
  public:
//    LoggingVideoDispatcher(std::string mjpeg_url, int fps, log4cplus::Logger logger) :
    LoggingVideoDispatcher(std::string mjpeg_url, int fps) :
      VideoDispatcher(mjpeg_url, fps)
      {
//	this->logger = logger;
      }
    
  virtual void log_info(std::string message)
  {
//    LOG4CPLUS_INFO(logger, message);
    LOG(INFO) << message;
  }
  virtual void log_error(std::string error)
  {
//    LOG4CPLUS_WARN(logger, error );
    LOG(WARNING) << error ;
  }
    
  private:
//    log4cplus::Logger logger;
};


class LoggingVideoBuffer : public VideoBuffer
{
  public:
//    LoggingVideoBuffer(log4cplus::Logger logger) : VideoBuffer()
//    {
//      this->logger = logger;
//    }
    LoggingVideoBuffer() : VideoBuffer()
    {

    }
  
  protected:
    
    virtual VideoDispatcher* createDispatcher(std::string mjpeg_url, int fps)
    {
//      return new LoggingVideoDispatcher(mjpeg_url, fps, logger);
      return new LoggingVideoDispatcher(mjpeg_url, fps);
    }
  
  private:
//    log4cplus::Logger logger;
};

#endif // OPENALPR_LOGGING_VIDEOBUFFER_H