/*
 * fuzzuf
 * Copyright (C) 2022 Ricerca Security
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program.  If not, see http://www.gnu.org/licenses/.
 */
#define BOOST_TEST_MODULE nautilus.context
#define BOOST_TEST_DYN_LINK

#include <boost/test/unit_test.hpp>
#include <vector>
#include "fuzzuf/algorithms/nautilus/grammartec/context.hpp"
#include "fuzzuf/algorithms/nautilus/grammartec/rule.hpp"


using namespace fuzzuf::algorithms::nautilus::grammartec;

BOOST_AUTO_TEST_CASE(NautilusGrammartecContextSimple) {
  Context ctx;
  Rule r(ctx, "F", "foo{A:a}\\{bar\\}{B:b}asd{C}");
  std::vector<RuleChild> soll = {
    RuleChild("foo"),
    RuleChild("{A:a}", ctx),
    RuleChild("{bar}"),
    RuleChild("{B:b}", ctx),
    RuleChild("asd"),
    RuleChild("{C}", ctx)
  };
  BOOST_CHECK_EQUAL(std::holds_alternative<PlainRule>(r.value()), true);
  PlainRule rl = std::get<PlainRule>(r.value());
  BOOST_CHECK_EQUAL(rl.children == soll, true);
  BOOST_CHECK_EQUAL(r.Nonterms()[0] == ctx.NTID("A"), true);
  BOOST_CHECK_EQUAL(r.Nonterms()[1] == ctx.NTID("B"), true);
  BOOST_CHECK_EQUAL(r.Nonterms()[2] == ctx.NTID("C"), true);
  
}
