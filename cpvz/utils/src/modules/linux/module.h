#ifndef CPVZ_MODULE_H
#define CPVZ_MODULE_H

#include <cpvz/utils/i_module.h>

#include <unordered_map>

namespace cpvz::utils {

class Module : public IModule {
public:
    ResultCode LoadSymbol(void*& ptr, const std::string& symbolName) noexcept override;
};

}  // namespace cpvz::utils::modules

#endif//CPVZ_MODULE_H
