#include "GridTemplateTemplate.h"
#include <iostream>
#include <vector>
using namespace std;

int main() {
  Grid<int, vector> myGrid;
  myGrid.setElementAt(1, 2, 3);
  cout << myGrid.getElementAt(1, 2) << endl;

  Grid<int, vector> myGrid2(myGrid);

  return 0;
}
