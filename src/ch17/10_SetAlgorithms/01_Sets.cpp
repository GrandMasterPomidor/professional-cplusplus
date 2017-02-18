#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> vec1 = {5, 6, 7, 8};
  vector<int> vec2 = {8, 9, 10};
  vector<int> result;

  // set algorithms work on sorted ranges
  sort(begin(vec1), end(vec1));
  sort(begin(vec2), end(vec2));

  cout << "Set 1: ";
  for (const auto& i : vec1) {
    cout << i << " ";
  }
  cout << endl;
  cout << "Set 2: ";
  for (const auto& i : vec2) {
    cout << i << " ";
  }
  cout << endl;

  if (includes(cbegin(vec1), cend(vec1), cbegin(vec2), cend(vec2))) {
    cout << "The second set is a subset of the first." << endl;
  }
  if (includes(cbegin(vec2), cend(vec2), cbegin(vec1), cend(vec1))) {
    cout << "The first set is a subset of the second" << endl;
  }

  result.resize(vec1.size() + vec2.size());
  auto newEnd = set_union(cbegin(vec1), cend(vec1), cbegin(vec2), cend(vec2), begin(result));
  cout << "The union is: ";
  for_each(begin(result), newEnd, [](int i) { cout << i << " "; });
  cout << endl;

  newEnd = set_intersection(cbegin(vec1), cend(vec1), cbegin(vec2), cend(vec2), begin(result));
  cout << "The intersection is: ";
  for_each(begin(result), newEnd, [](int i) { cout << i << " "; });
  cout << endl;

  newEnd = set_difference(cbegin(vec1), cend(vec1), cbegin(vec2), cend(vec2), begin(result));
  cout << "The difference between set 1 and set 2 is: ";
  for_each(begin(result), newEnd, [](int i) { cout << i << " "; });
  cout << endl;

  newEnd = set_symmetric_difference(cbegin(vec1), cend(vec1), cbegin(vec2), cend(vec2), begin(result));
  cout << "The symmetric difference is: ";
  for_each(begin(result), newEnd, [](int i) { cout << i << " "; });
  cout << endl;

  return 0;
}
