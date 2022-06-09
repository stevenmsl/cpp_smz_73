#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <unordered_map>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol73;

/*
Input:
[
  [1,1,1],
  [1,0,1],
  [1,1,1]
]
Output:
[
  [1,0,1],
  [0,0,0],
  [1,0,1]
]
*/

tuple<vector<vector<int>>, vector<vector<int>>>
testFixture1()
{
  auto input = vector<vector<int>>{
      {1, 1, 1},
      {1, 0, 1},
      {1, 1, 1}};
  auto output = vector<vector<int>>{
      {1, 0, 1},
      {0, 0, 0},
      {1, 0, 1}};
  return make_tuple(input, output);
}

/*
Input:
[
  [0,1,2,0],
  [3,4,5,2],
  [1,3,1,5]
]
Output:
[
  [0,0,0,0],
  [0,4,5,0],
  [0,3,1,0]
]
*/
tuple<vector<vector<int>>, vector<vector<int>>>
testFixture2()
{
  auto input = vector<vector<int>>{
      {0, 1, 2, 0},
      {3, 4, 5, 2},
      {1, 3, 1, 5}};
  auto output = vector<vector<int>>{
      {0, 0, 0, 0},
      {0, 4, 5, 0},
      {0, 3, 1, 0}};
  return make_tuple(input, output);
}

void test1()
{
  auto f = testFixture1();
  auto matirx = get<0>(f);
  cout << "Expect to see: " << Util::toString(get<1>(f)) << endl;
  Solution sol;
  sol.setZeroes(matirx);
  cout << Util::toString(matirx) << endl;
}

void test2()
{
  auto f = testFixture2();
  auto matirx = get<0>(f);
  cout << "Expect to see: " << Util::toString(get<1>(f)) << endl;
  Solution sol;
  sol.setZeroes(matirx);
  cout << Util::toString(matirx) << endl;
}

main()
{
  test1();
  test2();
  return 0;
}