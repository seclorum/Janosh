/*
 * CheesyServer.cpp
 *
 *  Created on: Jan 6, 2014
 *      Author: elchaschab
 */

#include <iostream>
#include <sstream>
#include <functional>
#include <thread>
#include "TcpServer.hpp"
#include <assert.h>
#include "format.hpp"
#include "exception.hpp"
#include "logger.hpp"

namespace janosh {

using boost::asio::ip::tcp;
using std::string;
using std::vector;
using std::stringstream;
using std::function;

TcpServer::TcpServer(int port) : io_service(), socket(NULL), acceptor(io_service){
    tcp::resolver resolver(io_service);
    tcp::resolver::query query("0.0.0.0", std::to_string(port));
    boost::asio::ip::tcp::endpoint endpoint = *resolver.resolve(query);

    acceptor.open(endpoint.protocol());
    acceptor.set_option(boost::asio::ip::tcp::acceptor::reuse_address(true));
    acceptor.bind(endpoint);
}

TcpServer::~TcpServer() {
	this->close();
}

void TcpServer::close() {
	if(socket != NULL)
		socket->close();
}

void splitAndPushBack(string& s, vector<string>& vec) {
  std::size_t i;
  std::size_t lasti = 0;
  string arg;

  while((i = s.find(",", lasti)) != string::npos) {
    arg = s.substr(lasti, i);
    if(!arg.empty())
      vec.push_back(arg);
    lasti = i + 1;
  }

  arg = s.substr(lasti, s.size());
  if(!arg.empty())
    vec.push_back(arg);
}

void TcpServer::run(function<int(Format,string,vector<string>, vector<string>, vector<string>, bool)> f) {
	acceptor.listen();
	boost::asio::ip::tcp::socket* s = new boost::asio::ip::tcp::socket(io_service);
	acceptor.accept(*s);
  std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
  try {
    socket = s;
    Format format;
    string command;
    vector<string> vecArgs;
    vector<string> vecTriggers;
    vector<string> vecTargets;
    bool verbose;

    std::string peerAddr = socket->remote_endpoint().address().to_string();

    LOG_DEBUG_MSG("accepted", peerAddr);
    string line;
    boost::asio::streambuf response;
    boost::asio::read_until(*socket, response, "\n");
    std::istream response_stream(&response);

    std::getline(response_stream, line);

    LOG_DEBUG_MSG("format", line);
    if (line == "BASH") {
      format = janosh::Bash;
    } else if (line == "JSON") {
      format = janosh::Json;
    } else if (line == "RAW") {
      format = janosh::Raw;
    } else
      throw janosh_exception() << string_info( { "Illegal formats line", line });

    std::getline(response_stream, command);
    LOG_DEBUG_MSG("command", command);

    std::getline(response_stream, line);
    LOG_DEBUG_MSG("args", line);

    splitAndPushBack(line, vecArgs);

    std::getline(response_stream, line);
    LOG_DEBUG_MSG("triggers", line);

    splitAndPushBack(line, vecTriggers);

    std::getline(response_stream, line);
    LOG_DEBUG_MSG("targets", line);

    splitAndPushBack(line, vecTargets);

    std::getline(response_stream, line);
    LOG_DEBUG_MSG("verbose", line);

    if (line == "TRUE")
      verbose = true;
    else if (line == "FALSE")
      verbose = false;
    else
      throw janosh_exception() << string_info( { "Illegal verbose line", line });

    boost::asio::streambuf request2;
    std::ostream request_stream2(&request2);
    std::cout.rdbuf(request_stream2.rdbuf());

    int rc = f(format, command, vecArgs, vecTriggers, vecTargets, verbose);

    boost::asio::streambuf request;
    std::ostream request_stream(&request);
    request_stream << std::to_string(rc) << '\n';
    LOG_DEBUG_MSG("sending", request.size());
    boost::asio::write(*socket, request);
    LOG_DEBUG_MSG("sending", request2.size());
    boost::asio::write(*socket, request2);
    socket->close();
  } catch (std::exception& ex) {
  }
  //std::cout.rdbuf(coutbuf);
}
} /* namespace janosh */
