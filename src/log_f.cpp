#include "log_f.h"
#include <iostream>

void log_f(
    std::string_view message,
    const std::source_location location
) {
    std::clog
        << "File: " << location.file_name()
        << " | Function: " << location.function_name()
        << " | Line: " << location.line()
        << " | " << message
        << '\n';
}

