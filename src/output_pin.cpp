// Copyright 2023 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <libhal-__platform__/output_pin.hpp>

namespace hal::__platform__ {

hal::result<output_pin> output_pin::create()
{
  // Fill this out
  return output_pin();
}

hal::status output_pin::driver_configure(
  [[maybe_unused]] const settings& p_settings)
{
  // Fill this out
  return hal::success();
}

hal::result<hal::output_pin::set_level_t> output_pin::driver_level(
  [[maybe_unused]] bool p_high)
{
  // Fill this out
  return set_level_t{};
}

hal::result<hal::output_pin::level_t> output_pin::driver_level()
{
  // Fill this out
  return hal::output_pin::level_t{ .state = true };
}
}  // namespace hal::__platform__
