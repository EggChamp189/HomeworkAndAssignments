//
//  util.cpp
//
//  Implementation of Timing Tests
//  You SHOULD modify this file.
//
//  Copyright 2019 David Kopec
//
//  Permission is hereby granted, free of charge, to any person
//  obtaining a copy of this software and associated documentation files
//  (the "Software"), to deal in the Software without restriction,
//  including without limitation the rights to use, copy, modify, merge,
//  publish, distribute, sublicense, and/or sell copies of the Software,
//  and to permit persons to whom the Software is furnished to do so,
//  subject to the following conditions:
//
//  The above copyright notice and this permission notice
//  shall be included in all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
//  OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
//  THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR
//  OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
//  ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
//  OTHER DEALINGS IN THE SOFTWARE.

#include "util.h"

#include <algorithm>
#include <iostream>
#include <random>

#include "search.h"

using namespace std;

namespace csi281 {

  // Returns a new int array of *length* and filled
  // with numbers between *min* and *max*
  // Suggest using the facilities in STL <random>
    // used setup from the uniform_int_distribution cpprefrence.com page
  int *randomIntArray(const int length, const int min, const int max) {
    // YOUR CODE HERE
    // used example from https://en.cppreference.com/w/cpp/numeric/random/uniform_int_distribution.html
    random_device rd;   // a seed source for the random number engine
    mt19937 gen(rd());  // mersenne_twister_engine seeded with rd()
    uniform_int_distribution<> distrib(min, max);
    int *arrayToMake = new int[length];

    for (int i = 0; i < length; i++) {
      *(arrayToMake + i) = distrib(gen);
    }

    sort(arrayToMake, (arrayToMake + length));

    return arrayToMake;
  }

  // Finds the speed of linear versus binary search
  // in a random int array of *length* size
  // by running *numTests* and averaging them
  // Returns a pair indicating the average time it took
  // to do linear search and binary search in nanoseconds
  // Linear search should be first in the pair, and binary search
  // should be second
  //
  // Suggest using the facilities in STL <chrono>
  // For example, you can start a timer using
  // using namespace std::chrono;
  // auto start = duration_cast< nanoseconds >(system_clock::now().time_since_epoch()).count();
  // and stop a timer using
  // auto end = duration_cast< nanoseconds >(system_clock::now().time_since_epoch()).count();
  // start, end will be results in nanoseconds
  pair<nanoseconds, nanoseconds> arraySearchSpeed(const int length, const int numTests) {
    int *testArray = randomIntArray(length, 0, length);
    int *testKeys = randomIntArray(numTests, 0, length);

    using namespace std::chrono;

    // Do numTests linear searches and find the average time
    // Put the result in a variable linearSearchSpeed

    // YOUR CODE HERE
    // got this more precise idea from this article: https://www.geeksforgeeks.org/c/measure-execution-time-with-high-precision-in-c-c/
    auto start = duration_cast<nanoseconds>(system_clock::now().time_since_epoch()).count();

    for (int i = 0; i < numTests; i++) {
      linearSearch
      (testArray, 
          length, 
          *(testKeys + i));
    }

    auto end = duration_cast<nanoseconds>(system_clock::now().time_since_epoch()).count();
    //double time_taken = duration_cast<nanoseconds>(end - start).count();
    nanoseconds linearSearchSpeed = (nanoseconds)((end - start) / numTests);

    // Do numTests binary searches and find the average time
    // Put the result in a variable binarySearchSpeed

    // YOUR CODE HERE

    auto start2 = duration_cast<nanoseconds>(system_clock::now().time_since_epoch()).count();

    for (int i = 0; i < numTests; i++) {
      binarySearch(testArray, length, *(testKeys + i));
    }

    auto end2 = duration_cast<nanoseconds>(system_clock::now().time_since_epoch()).count();
    // double time_taken = duration_cast<nanoseconds>(end - start).count();
    nanoseconds binarySearchSpeed = (nanoseconds)((end2 - start2) / numTests);

    delete testArray;
    delete testKeys;

    return pair<nanoseconds, nanoseconds>(linearSearchSpeed, binarySearchSpeed);
  }
}  // namespace csi281
