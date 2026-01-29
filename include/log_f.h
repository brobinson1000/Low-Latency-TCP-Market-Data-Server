#pragma once

#include <string_view>
#include <source_location>

void log_f(
    std::string_view message,
    std::source_location location = std::source_location::current()
);

