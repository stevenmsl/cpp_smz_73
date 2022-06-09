#include "solution.h"
#include "util.h"
#include <unordered_set>
#include <numeric>
#include <iterator>
#include <unordered_map>
#include <deque>
#include <string>
#include <sstream>
#include <algorithm>
#include <stack>
#include <functional>
using namespace sol73;
using namespace std;

/*takeaways
  - to achieve the space complexity of O(1), we borrow
    the first row and first col to record which
    row and col should be set to zeroes from scanning
    the smaller matrix that excludes the first row
    and the first col from the original matrix

  - we need to remember if we need to set additional
    1's to zero in the first row and first col before
    using them as a placeholder

*/

void Solution::setZeroes(vector<vector<int>> &matrix)
{
  int m = matrix.size(), n = matrix[0].size();
  auto frow = false, fcol = false;
  /* we will need this to see if additional
     1's need to be set to zero
  */
  for (auto j = 0; j < n; j++)
    if (matrix[0][j] == 0)
    {
      frow = true;
      break;
    }
  for (auto i = 0; i < m; i++)
    if (matrix[i][0] == 0)
    {
      fcol = true;
      break;
    }

  /* scan the smaller matrix and record if
     we need to set ith row and jth col to
     zeros.
  */
  for (auto i = 1; i < m; i++)
    for (auto j = 1; j < n; j++)
      if (matrix[i][j] == 0)
        /* note the corresponding
           location in the first row
           and the first col has been
           set to zeros accordingly
           due to matrix[i][j] is zero
        */
        matrix[0][j] = matrix[i][0] = 0;

  /* set the ith row and jth col to zeros */
  for (auto i = 1; i < m; i++)
    for (auto j = 1; j < n; j++)
      if (matrix[0][j] == 0 || matrix[i][0] == 0)
        matrix[i][j] = 0;

  /* see if there are more to set to zero in
     the first row or first col
  */

  if (frow)
    for (auto j = 0; j < n; j++)
      matrix[0][j] = 0;

  if (fcol)
    for (auto i = 0; i < m; i++)
      matrix[i][0] = 0;
}
