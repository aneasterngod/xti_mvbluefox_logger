# Dongshin Kim, 2018-05-13 11:25

# the following two lines shouldn't be pushed
set(CMAKE_PREFIX_PATH 	/home/dongshin/Shares/share/OpenCV
						/home/dongshin/Shares/lib/mvbluefox2/cmake
						/home/dongshin/Shares/lib/xti300/cmake
						CACHE PATH "the root directory of opencv driver")





set(xsens_INC_DIR /home/dongshin/Shares/include
    CACHE PATH "the root include directory that contains mvIMPACT header files" )
set(xsens_LIB_DIR /home/dongshin/Shares/lib
	CACHE PATH "the root lib directory that contains mvIMPACT libraries" )
set(mvIMPACT_INC_DIR /opt/mvIMPACT_Acquire
    CACHE PATH "the root include directory that contains mvIMPACT header files" )
set(mvIMPACT_LIB_DIR /opt/mvIMPACT_Acquire/lib/x86_64
	CACHE PATH "the root lib directory that contains mvIMPACT libraries" )

find_package(xti300 REQUIRED)
find_package(mvbluefox2 REQUIRED)
find_package(OpenCV REQUIRED)

include_directories (
	${xti_mvbluefox_logger_SOURCE_DIR}/src
	${xti_mvbluefox_logger_SOURCE_DIR}/include
	${MVBLUEFOX2_INCLUDE_DIR}
	${XTI300_INCLUDE_DIR}
	${OpenCV_INCLUDE_DIRS}
	${xsens_INC_DIR}
	${mvIMPACT_INC_DIR}
)

link_directories (
	${xti_mvbluefox_logger_BINARY_DIR}/src
	${MVBLUEFOX2_LIB_DIR} 
	${XTI300_LIB_DIR}
	${xsens_LIB_DIR}
	${mvIMPACT_LIB_DIR}
)

add_executable (logger 
	logger_io.cpp
	logger.cpp		
)

# since xstypes is not static, so have to be included
target_link_libraries(logger
	mvbluefox2
	xti300
	xstypes
	xcommunication
	pthread
	mvBlueFOX
	mvPropHandling
	mvDeviceManager
	${OpenCV_LIBS}
)

