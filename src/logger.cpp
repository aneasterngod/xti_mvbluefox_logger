#include "logger_common.h"
#include "logger_io.h"

ofstream imginfo;
ofstream imuinfo;

void siginthandler(int param)
{
    cout << "Program exit normally." << endl;
    imginfo.close();
    imuinfo.close();
    exit(1);
}

int main(int argc, char **argv)
{
    signal(SIGINT, siginthandler);
    logger_io lg;
    if (argc == 5)
    {
        int ex = atoi(argv[4]);
        lg.init(argv[1], argv[2], ex);
    }
    else
    {
        cout << "Argument0: /dev/ttUSB0" << endl;
        cout << "Argument1: camera SN" << endl;
        cout << "Argument2: saving directory(log)" << endl;
        cout << "Argument3: Exposure" << endl;
        lg.init("/dev/ttyUSB0", "26802554", 7000);
    }

    string saveprefix = "/home/dongshin/code-repository/log";
    system("rm -rf /home/dongshin/code-repository/log/*");
    if (argc == 4)
        saveprefix = argv[3];
    int cnt = -1;
    string imagefileinfo = "image.txt";
    string imudata = "imu.txt";

    if (saveprefix.back() == '/')
    {
        imagefileinfo = saveprefix + imagefileinfo;
        imudata = saveprefix + imudata;
    }
    else
    {
        imagefileinfo = saveprefix + "/" + imagefileinfo;
        imudata = saveprefix + "/" + imudata;
    }

    imginfo.open(imagefileinfo, ios::app);
    imuinfo.open(imudata, ios::app);

    if (!imginfo.is_open())
    {
        cout << "Open error" << endl;
        imginfo.close();
        exit(1);
    }
    if (!imuinfo.is_open())
    {
        cout << "Open error" << endl;
        imuinfo.close();
        exit(1);
    }

    imginfo.precision(10);
    imuinfo.precision(10);
    int firstchk = 0;
    while (1)
    {
        // store
        char ctmp[100];
        sprintf(ctmp, "image_%03d.jpg", cnt);
        string imagefilename = ctmp;
        if (saveprefix.back() == '/')
        {
            imagefilename = saveprefix + imagefilename;
        }
        else
        { 
            imagefilename = saveprefix + "/"  + imagefilename;
        }

        if (lg.m_bluefox2.m_data.size() > 0)
        {
            if(cnt != -1 && !lg.m_bluefox2.m_data.front().m_img.empty()){
                if(firstchk<1){
                    firstchk++;
                    cnt--;
                }else{
                    cv::imshow("test", lg.m_bluefox2.m_data.front().m_img);
                    cv::waitKey(3);
                    cv::imwrite(imagefilename, lg.m_bluefox2.m_data.front().m_img);
                    imginfo << lg.m_bluefox2.m_data.front().m_timestamp << " " << imagefilename << endl;
                }
                lg.m_bluefox2.m_data.pop_front();
            }
            cnt++;
        }
        if (lg.m_xti.m_data.size() > 0)
        {
            imuinfo << lg.m_xti.m_data.front().m_timestamp << " " << lg.m_xti.m_data.front().m_acceleration_x << " " << lg.m_xti.m_data.front().m_acceleration_y << " " << lg.m_xti.m_data.front().m_acceleration_z << " " << lg.m_xti.m_data.front().m_rotation_x << " " << lg.m_xti.m_data.front().m_rotation_y << " " << lg.m_xti.m_data.front().m_rotation_z << endl;
            lg.m_xti.m_data.pop_front();
        }
    }
    return 0;
}
