#include "logger_io.h"

logger_io::logger_io(){

}

logger_io::~logger_io(){

}

void logger_io::init(const char* usbdev, const char* sn, const int ex){    
    if(m_xti.init(usbdev)){
        m_xti.startCapture();
    }
    else{
        cout << "Error imu" << endl;
    }
    if(m_bluefox2.init(sn)){
        m_bluefox2.setExposure(ex);
        m_bluefox2.startCapture();
    }
    else{
        cout << "Error cam" << endl;
    }
}