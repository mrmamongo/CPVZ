#ifndef CPVZ_I_LOGGER_HPP
#define CPVZ_I_LOGGER_HPP

#include <ostream>

#define CPVZ_LOG_TRACE(...)    cpvz::logging::ILogger::GetInstance()
#define CPVZ_LOG_DEBUG(...)    cpvz::logging::ILogger::GetInstance()
#define CPVZ_LOG_INFO(...)     cpvz::logging::ILogger::GetInstance()
#define CPVZ_LOG_WARNING(...)  cpvz::logging::ILogger::GetInstance()
#define CPVZ_LOG_ERROR(...)    cpvz::logging::ILogger::GetInstance()
#define CPVZ_LOG_CRITICAL(...) cpvz::logging::ILogger::GetInstance()

namespace cpvz::logging {

enum class LogLevel : std::uint32_t {
    Trace,
    Debug,
    Info,
    Warning,
    Error,
    Fatal
};

std::ostream& operator<<(std::ostream& out, LogLevel level);



/**
 * @brief An interface for logging
 * @detail Is actually a wrapper around boost::logger
 */
class ILogger {
public:
    virtual ~ILogger() = default;

    /**
     * @brief Get an instance of logger
     * @return A reference to a global unique logger instance
     */
    static ILogger& GetInstance();

    template<typename ...Args>
    void Log(LogLevel logLevel, const std::string& module, Args&& ...args) {
        //(/**/ << ... << args) << std::endl;
    }

    template<typename T>
    ILogger& LogPart(T arg) {
        //Do something
        return *this;
    }
};

}  // namespace cpvz::logging

#endif//CPVZ_I_LOGGER_HPP
