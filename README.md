
Description
========================================


Procedure for building code using CMake
========================================
You can either create an in-source build, or an out-of-source build. 

An out-of-source build keeps clean separation between source and build, but requires more overhead to switch between source and build directories if necesary.

An in-source build is perhaps more intuitive, but has the disadvantage of polluting your source directories with auto-generated files.

To create an out-of-source build:

	[xti_mvbluefox_logger]$ mkdir build

	[xti_mvbluefox_logger]$ cd build

	[xti_mvbluefox_logger/build]$ cmake ..

	[xti_mvbluefox_logger/build]$ make

Note that the last two commands are executed inside the build directory.

Afterwards, your tree structure should look like this:

	[xti_mvbluefox_logger]$ tree -L 2

	.
	|-- CMakeLists.txt
	|-- README.md
	|-- build
	|   |-- CMakeCache.txt
	|   |-- CMakeFiles
	|   |-- Makefile
	|   |-- cmake_install.cmake
	|   |-- src
	|-- src
	  |-- CMakeLists.txt
	  |-- xti_mvbluefox_logger

and you can execute the program in the logger.cpp/build/src directory as follows:

	[xti_mvbluefox_logger/build/src]$ ./logger

To create an in-source build,

	[xti_mvbluefox_logger]$ cmake .

	[xti_mvbluefox_logger]$ make

This will create the executables in the xti_mvbluefox_logger/src directory.

For more information on using CMake, check out 

	http://www.cmake.org/cmake/help/cmake_tutorial.html

Dongshin Kim, 2018-05-13 11:25
	# xti_mvbluefox_logger
