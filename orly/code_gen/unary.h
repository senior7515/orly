/* <orly/code_gen/unary.h>

   TODO

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

#pragma once

#include <orly/code_gen/inline.h>

namespace Orly {

  namespace CodeGen {

    class TUnary : public TInline {
      NO_COPY(TUnary);
      public:

      typedef std::shared_ptr<const TUnary> TPtr;

      //TODO: effect
      enum TOp {Acos, AddressOf, Asin, Atan, Cast, Ceiling, Cos, Floor, IsEmpty, IsKnown, IsUnknown, Known, LengthOf, Log,
                Log2, Log10, Negative, Not, Read, ReverseOf, SequenceOf, Sin, Tan, TimeDiffObj, TimePntObj, ToLower, ToUpper, UnwrapMutable };

      TUnary(const L0::TPackage *package, const Type::TType &ret_type, TOp op, const TInline::TPtr &expr);

      void WriteExpr(TCppPrinter &out) const;

      /* Dependency graph */
      virtual void AppendDependsOn(std::unordered_set<TInline::TPtr> &dependency_set) const override {
        assert(this);
        dependency_set.insert(Expr);
        Expr->AppendDependsOn(dependency_set);
      }

      private:
      void Call(TCppPrinter &out, const char *func) const;
      void Postfix(TCppPrinter &out, const char *func) const;

      TOp Op;
      TInline::TPtr Expr;

    }; // TUnary


  } // CodeGen

} // Orly

namespace std {

  template <>
  struct hash<Orly::CodeGen::TUnary::TOp> {

    typedef size_t result_type;
    typedef Orly::CodeGen::TUnary::TOp argument_type;

    result_type operator()(const argument_type &that) const {
      assert(&that);
      return static_cast<result_type>(that);
    }

  };  // hash<Orly::CodeGen::TUnary::TOp>

}  // std
