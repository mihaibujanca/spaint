/**
 * tvgutil: ExecutableFinder.h
 * Copyright (c) Torr Vision Group, University of Oxford, 2015. All rights reserved.
 */

#ifndef H_TVGUTIL_EXECUTABLEFINDER
#define H_TVGUTIL_EXECUTABLEFINDER

#include <boost/filesystem.hpp>

namespace tvgutil {

/**
 * \brief Finds the path to the current executable.
 *
 * \return  The path to the current executable.
 */
extern boost::filesystem::path find_executable();

}

#endif
