/* <orly/expr/set.test.cc>

   Unit test for <orly/expr/set.h>.

   Copyright 2010-2014 OrlyAtomics, Inc.

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

     http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License. */

#include <orly/expr/test_kit.h>

FIXTURE(Set) {
  /* empty {int} -> {int} */
  EXPECT_EQ(empty_set->GetType(), set_type);
  /* {int, int} -> {int} */
  EXPECT_EQ(set0->GetType(), set_type);
}