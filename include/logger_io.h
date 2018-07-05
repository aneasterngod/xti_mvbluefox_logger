#include "logger_common.h"


class logger_io{
public:
    logger_io();
    ~logger_io();
    void init(const char* usbdev, const char* sn, const int ex);
public:
    xti_io m_xti;
    mvbluefox2_io m_bluefox2;
}; 