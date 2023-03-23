#include <libhal-__target__/output_pin.hpp>
#include <libhal-armcortex/dwt_counter.hpp>
#include <libhal-soft/inert_drivers/inert_output_pin.hpp>
#include <libhal-util/serial.hpp>
#include <libhal-util/steady_clock.hpp>

hal::status application()
{
  using namespace hal::literals;
  // TODO(libhal-target): Set the correct frequency and output pin driver
  hal::cortex_m::dwt_counter clock(1.0_MHz);
  auto led = HAL_CHECK(hal::inert_output_pin::create(false));

  while (true) {
    using namespace std::chrono_literals;
    HAL_CHECK(led.level(false));
    HAL_CHECK(hal::delay(clock, 200ms));
    HAL_CHECK(led.level(true));
    HAL_CHECK(hal::delay(clock, 200ms));
  }
}
