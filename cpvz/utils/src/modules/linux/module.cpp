#include "module.h"

#include <cpvz/logging/i_logger.hpp>

namespace cpvz::utils {

ResultCode LoadSymbol(void*& ptr, const std::string& symbolName) noexcept {
    CPVZ_LOG_TRACE() << __PRETTY_FUNCTION__;
    //TODO: Implement
    (void)ptr;
    (void)symbolName;
    return ResultCode::NotImplemented;
}

}  // namespace cpvz::utils