/* <orly/synth/postfix_is_known_expr.cc>

   Implements <orly/synth/postfix_is_known_expr.h>.

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

#include <orly/synth/postfix_is_known_expr.h>

#include <base/assert_true.h>
#include <orly/expr/known.h>
#include <orly/pos_range.h>
#include <orly/orly.package.cst.h>
#include <orly/synth/get_pos_range.h>
#include <orly/synth/new_expr.h>
#include <orly/synth/new_type.h>

using namespace Orly;
using namespace Orly::Synth;

TPostfixIsKnownExpr::TPostfixIsKnownExpr(const TExprFactory *expr_factory, const Package::Syntax::TPostfixIsKnownExpr *postfix_is_known_expr)
    : PostfixIsKnownExpr(Base::AssertTrue(postfix_is_known_expr)), Lhs(nullptr), Rhs(nullptr) {
  assert(expr_factory);
  try {
    Lhs = expr_factory->NewExpr(PostfixIsKnownExpr->GetLhs());
    Rhs = expr_factory->NewExpr(PostfixIsKnownExpr->GetRhs());
  } catch (...) {
    delete Lhs;
    delete Rhs;
    throw;
  }
}

TPostfixIsKnownExpr::~TPostfixIsKnownExpr() {
  assert(this);
  delete Lhs;
  delete Rhs;
}

Expr::TExpr::TPtr TPostfixIsKnownExpr::Build() const {
  assert(this);
  return Expr::TIsKnownExpr::New(Lhs->Build(), Rhs->Build(), GetPosRange(PostfixIsKnownExpr));
}

void TPostfixIsKnownExpr::ForEachInnerScope(const std::function<void (TScope *cb)> &cb) {
  assert(this);
  assert(&cb);
  assert(cb);
  Lhs->ForEachInnerScope(cb);
  Rhs->ForEachInnerScope(cb);
}

void TPostfixIsKnownExpr::ForEachRef(const std::function<void (TAnyRef &cb)> &cb) {
  assert(this);
  assert(&cb);
  assert(cb);
  Lhs->ForEachRef(cb);
  Rhs->ForEachRef(cb);
}
