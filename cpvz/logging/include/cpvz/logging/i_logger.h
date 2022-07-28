#ifndef CPVZ_I_LOGGER_H
#define CPVZ_I_LOGGER_H

#define CPVZ_LOG_TRACE(...)    cpvz::logging::ILogger::getInstance()
#define CPVZ_LOG_DEBUG(...)    cpvz::logging::ILogger::getInstance()
#define CPVZ_LOG_INFO(...)     cpvz::logging::ILogger::getInstance()
#define CPVZ_LOG_WARNING(...)  cpvz::logging::ILogger::getInstance()
#define CPVZ_LOG_ERROR(...)    cpvz::logging::ILogger::getInstance()
#define CPVZ_LOG_CRITICAL(...) cpvz::logging::ILogger::getInstance()

namespace cpvz::logging {

/**
 * @brief An interface for logging
 */
class ILogger {
public:
    virtual ~ILogger() = default;

    static ILogger& getInstance();

    // TODO: Remove this, once logging is properly implemented
    template<typename T>
    ILogger& operator<<([[maybe_unused]] T param) {
        return *this;
    }
};

// TODO: Remove this, once logging is properly implemented
ILogger& cpvz::logging::ILogger::getInstance() {
    static ILogger logger;
    return logger;
}

}  // namespace cpvz::logging

#endif //CPVZ_I_LOGGER_H
