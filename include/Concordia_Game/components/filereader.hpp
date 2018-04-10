/* File: filereader.hpp
 * Author: Klotz Tom
 */

#ifndef FILEREADER_HPP
#define FILEREADER_HPP

#include <string>

//Save date , prepared field
class FileReader {
public:
   /*
    * Defines how the file reader will read the file and how the
    * information will be used on entities.
    */
  virtual void readFile(std::string fileName) = 0;
};

#endif
