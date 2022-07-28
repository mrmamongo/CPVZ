#include "logger.hpp"

#include <boost/log/core.hpp>
#include <boost/log/utility/setup.hpp>

#include <iomanip>

namespace cpvz::logging {

constexpr size_t MaxModuleLength = 10;

BOOST_LOG_ATTRIBUTE_KEYWORD(log_level, "LogLevel", LogLevel)
BOOST_LOG_ATTRIBUTE_KEYWORD(module_name, "ModuleName", std::string)

boost::log::formatting_ostream& operator<<(boost::log::formatting_ostream& out, boost::log::to_log_manip<LogLevel, tag::log_level> const& manip)
{
    switch (manip.get()) {
        case LogLevel::Trace:   out << "Trace  "; break;
        case LogLevel::Debug:   out << "Debug  "; break;
        case LogLevel::Info:    out << "Info   "; break;
        case LogLevel::Warning: out << "Warning"; break;
        case LogLevel::Error:   out << "Error  "; break;
        case LogLevel::Fatal:   out << "Fatal  "; break;
        default:                out << "Unknown"; break;
    }
    return out;
}

boost::log::formatting_ostream& operator<<(boost::log::formatting_ostream& out, boost::log::to_log_manip<std::string, tag::module_name> const& manip)
{
    std::string moduleName = manip.get();
    if (moduleName.length() > MaxModuleLength) {
        moduleName.erase(MaxModuleLength, moduleName.length() - MaxModuleLength + 1);
    }
    out << std::setw(MaxModuleLength) << std::setfill(' ') << moduleName;
    return out;
}

Logger::Logger() {
    boost::log::add_common_attributes();

    boost::log::add_file_log(
            boost::log::keywords::file_name = "cpvz_%N.log",
            boost::log::keywords::rotation_size = 10 * 1024 * 1024, // 10 MiB
            boost::log::keywords::time_based_rotation = boost::log::sinks::file::rotation_at_time_point(0, 0, 0),
            boost::log::keywords::format = "[%LogLevel%][%TimeStamp%][%ModuleName%]: %Message%");

    boost::log::add_console_log(
            std::clog,
            boost::log::keywords::format = "[%LogLevel%][%TimeStamp%][%ModuleName%]: %Message%");
}

ILogger& ILogger::GetInstance() {
    static Logger logger;
    return logger;


}

}  // namespace cpvz::logging
