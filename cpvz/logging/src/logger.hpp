#ifndef CPVZ_LOGGER_HPP
#define CPVZ_LOGGER_HPP

#include <cpvz/logging/i_logger.hpp>

#include <boost/log/sources/severity_logger.hpp>

namespace cpvz::logging {

class Logger : public ILogger {
public:
    Logger();
private:
    boost::log::sources::severity_logger_mt<LogLevel> m_loggerImpl;
};

}  // namespace cpvz::logging

#endif  // CPVZ_LOGGER_HPP
