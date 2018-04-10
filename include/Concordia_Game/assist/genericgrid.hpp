/* File: genericgrid.hpp
 * Author: Klotz Tom
 */


 //Write commentary ! task
#ifndef GENERICGRID_HPP
#define GENERICGRID_HPP

#include <cmath>

class GenericGrid{
protected:
  int w;
  int h;
  int unitySize;

  int xCells;
  int yCells;

public:
    GenericGrid();
	GenericGrid(int w, int h, int unitySize);
};

#endif
