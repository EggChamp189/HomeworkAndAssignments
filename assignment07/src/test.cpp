//
//  test.cpp
//
//  Tests to prove your code works.
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

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>
#define SECTION(name) DOCTEST_SUBCASE(name)
#undef TEST_CASE
#define TEST_CASE(name, tags) DOCTEST_TEST_CASE(tags " " name)
using doctest::Approx;

#include <string>

#include "Queue.h"
#include "Stack.h"

using namespace std;
using namespace csi281;

TEST_CASE("Queue Tests", "[queue]") {
  SECTION("Queue w/ int tests") {
    Queue<int> q1 = Queue<int>();
    // Ensure that push(), pop(), and peek()
    // work properly in concert with getCount()
    // and remove()
    // YOUR CODE HERE
    // first check if empty
    CHECK(q1.getCount() == 0);

    // check pushing
    q1.push(1);
    q1.push(2);
    q1.push(3);

    // check numbers are in the correct spots
    CHECK(q1.getCount() == 3);
    CHECK(q1.peek() == 1);

    // check popping
    int thePopped = q1.pop();
    CHECK(thePopped == 1);
    CHECK(q1.getCount() == 2);
    CHECK(q1.peek() == 2);

    // remove all 2
    q1.remove(2);
    CHECK(q1.getCount() == 1);
    CHECK(q1.peek() == 3);

    // pop the final one
    thePopped = q1.pop();
    CHECK(thePopped == 3);
    CHECK(q1.getCount() == 0);

    // queue should now break
    CHECK_THROWS_AS(q1.pop(), std::out_of_range);
    CHECK_THROWS_AS(q1.peek(), std::out_of_range);
  }

  SECTION("Queue w/ string tests") {
    Queue<string> q2 = Queue<string>();
    // Ensure that push(), pop(), and peek()
    // work properly in concert with getCount()
    // and remove()
    // YOUR CODE HERE
    // first check if empty
    CHECK(q2.getCount() == 0);
    // push!!!!!
    q2.push("joe");
    q2.push("obama"); // no one know's obama's last name...
    q2.push("barack");

    // check the new thingy
    CHECK(q2.getCount() == 3);
    CHECK(q2.peek() == "joe");

    // test pop
    string thePopped = q2.pop();
    CHECK(thePopped == "joe");
    CHECK(q2.peek() == "obama");

    // DESTROY ALL OBAMNA
    q2.remove("obama");
    CHECK(q2.getCount() == 1);
    CHECK(q2.peek() == "barack");

    // finish destroying yhe queue
    q2.pop();
    CHECK(q2.getCount() == 0);
  }
}

TEST_CASE("Stack Tests", "[stack]") {
  SECTION("Stack w/ int tests") {
    Stack<int> s1 = Stack<int>();
    // Ensure that push(), pop(), and peek()
    // work properly in concert with getCount()
    // and remove()
    // YOUR CODE HERE
    // // first check if empty
    CHECK(s1.getCount() == 0);

    // check pushing
    s1.push(3);
    s1.push(2);
    s1.push(1);

    // check numbers are in the correct spots
    CHECK(s1.getCount() == 3);
    CHECK(s1.peek() == 1);

    // check popping
    int thePopped = s1.pop();
    CHECK(thePopped == 1);
    CHECK(s1.getCount() == 2);
    CHECK(s1.peek() == 2);

    // remove all 2
    s1.remove(2);
    CHECK(s1.getCount() == 1);
    CHECK(s1.peek() == 3);

    // pop the final one
    thePopped = s1.pop();
    CHECK(thePopped == 3);
    CHECK(s1.getCount() == 0);

    // queue should now break
    CHECK_THROWS_AS(s1.pop(), std::out_of_range);
    CHECK_THROWS_AS(s1.peek(), std::out_of_range);
  }

  SECTION("Stack w/ string tests") {
    Stack<string> s2 = Stack<string>();
    // Ensure that push(), pop(), and peek()
    // work properly in concert with getCount()
    // and remove()
    // YOUR CODE HERE
    // first check if empty
    CHECK(s2.getCount() == 0);
    // push!!!!!
    s2.push("barack");
    s2.push("obama");  // no one know's obama's last name...
    s2.push("joe");

    // check the new thingy
    CHECK(s2.getCount() == 3);
    CHECK(s2.peek() == "joe");

    // test pop
    string thePopped = s2.pop();
    CHECK(thePopped == "joe");
    CHECK(s2.peek() == "obama");

    // DESTROY ALL OBAMNA
    s2.remove("obama");
    CHECK(s2.getCount() == 1);
    CHECK(s2.peek() == "barack");

    // finish destroying yhe queue
    s2.pop();
    CHECK(s2.getCount() == 0);
  }
}
