/*
 * janosh_thread.cpp
 *
 *  Created on: Feb 2, 2014
 *      Author: elchaschab
 */

#include "database_thread.hpp"
#include "janosh.hpp"
#include "commands.hpp"
#include "exception.hpp"

namespace janosh {

DatabaseThread::DatabaseThread(const Request& req, ostream_ptr out) :
    JanoshThread("Database"),
    req_(req),
    out_(out) {
}

void DatabaseThread::run() {
  try {
    setResult(false);
    Janosh* instance = Janosh::getInstance();

    if (!req_.command_.empty()) {
      LOG_DEBUG_MSG("Execute command", req_.command_);
      Command* cmd = instance->cm_[req_.command_];

      if (!cmd) {
        throw janosh_exception() << string_info( { "Unknown command", req_.command_ });
      }

      Command::Result r;
      try {
        r = (*cmd)(req_.vecArgs_, *out_);
        setResult(true);
      } catch(janosh_exception& ex) {
        Record::db.end_transaction(false);
        throw ex;
      } catch(std::exception& ex) {
        Record::db.end_transaction(false);
        throw ex;
      }

      if (r.first == -1)
        throw janosh_exception() << msg_info(r.second);

      LOG_INFO_MSG(r.second, r.first);
    } else {
      throw janosh_exception() << msg_info("missing command");
    }
  } catch (janosh_exception& ex) {
    printException(ex);
    return;
  } catch (std::exception& ex) {
    printException(ex);
    return;
  }
}
} /* namespace janosh */
