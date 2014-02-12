/*
 * Ctrl-Cut - A laser cutter CUPS driver
 * Copyright (C) 2009-2010 Amir Hassan <amir@viel-zu.org> and Marius Kintel <marius@kintel.net>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef LOGGER_H_
#define LOGGER_H_

#include <string>
#include <initializer_list>
#include <assert.h>
#include "easylogging++.h"
#include <sstream>
#include <boost/lexical_cast.hpp>

namespace janosh {
  using std::string;

  enum LogLevel {
    L_FATAL = 0,
    L_ERROR = 1,
    L_WARNING = 2,
    L_INFO = 3,
    L_DEBUG = 4,
    L_GLOBAL = 5
  };

  class Record;

  class Logger {
  private:
    static const string makeCallString(const string& caller, std::initializer_list<janosh::Record> records);
  public:
    LogLevel level;

    static void init(const LogLevel l);
    static Logger& getInstance();
    static LogLevel getLevel();

    static void trace(const string& caller, std::initializer_list<janosh::Record> records);

    template<typename Tvalue>
    static void trace(const string& caller, std::initializer_list<janosh::Record> records, Tvalue value) {
      LOG(TRACE) << makeCallString(caller, records), boost::lexical_cast<string>(value);
    }

  private:
    Logger(const LogLevel l) : level(l) {
      el::Configurations defaultConf;
      defaultConf.setToDefault();

      defaultConf.set(el::Level::Info, el::ConfigurationType::Format,
          "%datetime %msg");
      defaultConf.set(el::Level::Fatal, el::ConfigurationType::Format,
          "%datetime %level %loc %msg");
      defaultConf.set(el::Level::Debug, el::ConfigurationType::Format,
          "%datetime %level %loc %msg");

      // To set GLOBAL configurations you may use
      defaultConf.setGlobally(el::ConfigurationType::Format, "%datetime %level %msg");
      el::Loggers::reconfigureLogger("default", defaultConf);
    }

    static Logger* instance;
  };

  #define LOG_GLOBA_STR(x) if(Logger::getLevel() >= L_GLOBAL) LOG(GLOBAL) << x;
  #define LOG_DEBUG_STR(x) if(Logger::getLevel() >= L_DEBUG) LOG(DEBUG) << x;
  #define LOG_INFO_STR(x) if(Logger::getLevel() >= L_INFO) LOG(INFO) << x;
  #define LOG_WARN_STR(x) if(Logger::getLevel() >= L_WARNING) LOG(WARNING) << x;
  #define LOG_ERR_STR(x) if(Logger::getLevel() >= L_ERROR) LOG(ERROR) << x;
  #define LOG_FATAL_STR(x) if(Logger::getLevel() >= L_FATAL) LOG(FATAL) << x;
  #define LOG_GLOBAL_MSG(msg,x) if(Logger::getLevel() >= L_GLOBAL) LOG(GLOBAL) << msg << ": " << x;
  #define LOG_DEBUG_MSG(msg,x) if(Logger::getLevel() >= L_DEBUG) LOG(DEBUG) << msg << ": " << x;
  #define LOG_INFO_MSG(msg,x) if(Logger::getLevel() >= L_INFO) LOG(INFO) << msg << ": " << x;
  #define LOG_WARN_MSG(msg,x) if(Logger::getLevel() >= L_WARNING) LOG(WARNING) << msg << ": " << x;
  #define LOG_ERR_MSG(msg,x) if(Logger::getLevel() >= L_ERROR) LOG(ERROR) << msg << ": " << x;
  #define LOG_FATAL_MSG(msg,x) if(Logger::getLevel() >= L_FATAL) LOG(FATAL) << msg << ": " << x;
  #define LOG_GLOBAL(x) if(Logger::getLevel() >= L_GLOBAL) LOG(GLOBAL) << x;
  #define LOG_DEBUG(x) if(Logger::getLevel() >= L_DEBUG) LOG(DEBUG) << x;
  #define LOG_INFO(x) if(Logger::getLevel() >= L_INFO) LOG(INFO) << x;
  #define LOG_WARN(x) if(Logger::getLevel() >= L_WARNING) LOG(WARNING) << x;
  #define LOG_ERR(x) if(Logger::getLevel() >= L_ERROR) LOG(ERROR) << x;
  #define LOG_FATAL(x) if(Logger::getLevel() >= L_FATAL) LOG(FATAL) << x;

  #define JANOSH_TRACE(...) Logger::trace(string(__FUNCTION__), ##__VA_ARGS__);
}

#endif /* LOGGER_H_ */
