#include "logger_common.h"


class logger_io{
public:
    logger_io();
    ~logger_io();
    void init(const char* usbdev, const char* sn);
public:
    xti_io m_xti;
    mvbluefox2_io m_bluefox2;
}; 