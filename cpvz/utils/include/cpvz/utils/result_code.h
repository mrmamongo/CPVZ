#ifndef CPVZ_RESULT_CODE_H
#define CPVZ_RESULT_CODE_H

#include <cstdint>
#include <limits>

namespace cpvz::utils {

enum class ResultCode : std::uint32_t {
    Success,

    FileNotFound,

    NotImplemented,

    UnknownError = std::numeric_limits<std::uint32_t>::max()
};

}  // namespace cpvz::utils

#endif//CPVZ_RESULT_CODE_H
