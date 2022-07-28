#ifndef CPVZ_I_MODULE_H
#define CPVZ_I_MODULE_H

#include <cpvz/utils/result_code.h>

#include <functional>
#include <filesystem>
#include <memory>

namespace cpvz::utils {

template<typename T>
concept FunctionType = std::is_function_v<T>;

/**
 * @brief An interface to the runtime-loaded shared library
 */
class IModule {
public:
    virtual ~IModule() = default;

    /**
     * @tparam Signature Signature of a function that should be loaded
     * @param function Where to store the loaded function
     * @param functionName Name of a function
     * @return ResultCode::Success on success, error code otherwise
     */
    template<FunctionType Signature>
    ResultCode LoadFunction(std::function<Signature>& function, const std::string& functionName) noexcept {
        void* ptr = nullptr;
        auto result = LoadSymbol(ptr, functionName);
        function = ptr;
        return result;
    }

protected:
    virtual ResultCode LoadSymbol(void*& ptr, const std::string& symbolName) noexcept = 0;
};

using IModulePtr = std::shared_ptr<IModule>;

ResultCode LoadModule(IModulePtr& module, const std::filesystem::path& modulePath) noexcept;

}  // namespace cpvz::utils

#endif //CPVZ_I_MODULE_H
