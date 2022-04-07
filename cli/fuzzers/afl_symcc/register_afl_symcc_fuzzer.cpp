/*
 * fuzzuf
 * Copyright (C) 2021 Ricerca Security
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
#include "fuzzuf/cli/fuzzer/afl_symcc/build_from_args.hpp"
#include "fuzzuf/cli/fuzzer_builder_register.hpp"
#include "fuzzuf/executor/afl_executor_interface.hpp"
#include <boost/program_options.hpp>

namespace fuzzuf::cli::fuzzer::afl_symcc {

static FuzzerBuilderRegister global_afl_register("afl_symcc", BuildFromArgs);

} // namespace fuzzuf::cli::fuzzer::afl_symcc