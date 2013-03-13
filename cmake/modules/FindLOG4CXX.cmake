#
# Try to find Log4Cxx library and include path.
# Once done this will define
#
# LOG4CXX_FOUND
# LOG4CXX_INCLUDE_PATH
# LOG4CXX_LIBRARY
#
# You can set LOG4CXX_ROOT_DIR to give a non standard location (it must have
# include and lib subdirectories)
# 

IF(WIN32)
	# TODO !
ELSE(WIN32)
	FIND_PATH( LOG4CXX_INCLUDE_PATH log4cxx/logger.h
		/usr/include
		/usr/local/include
		/sw/include
        /opt/local/include
		${LOG4CXX_ROOT_DIR}/include
		DOC "The directory where log4cxx/logger.h resides")

	# Prefer the static library.
	FIND_LIBRARY( LOG4CXX_LIBRARY
		NAMES liblog4cxx liblog4cxx.a
		PATHS
		/usr/lib64
		/usr/lib
		/usr/local/lib64
		/usr/local/lib
		/sw/lib
		/opt/local/lib
		${LOG4CXX_ROOT_DIR}/lib
		DOC "The log4cxx library")
ENDIF(WIN32)

SET(LOG4CXX_FOUND "NO")
IF(LOG4CXX_INCLUDE_PATH AND LOG4CXX_LIBRARY)
	SET(LOG4CXX_FOUND "YES")
    message(STATUS "Found LOG4CXX")
ENDIF()