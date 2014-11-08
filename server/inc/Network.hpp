#ifndef _NETWORK_HPP_
# define _NETWORK_HPP_

#include <map>
#include <string>
#include <memory>
#include <set>

#include "ALog.hpp"
#include "IListenSocket.hpp"
#include "Spider.hpp"

class Network {
public:
  Network(uint16_t port, const std::string &addr = "0.0.0.0");
  virtual ~Network() = default;

  void		poll_clients();
  void      run();
  void      stop();
  void		broadcast(const std::vector<uint8_t> &buffer);

  void      registerSpider(const std::shared_ptr<Spider>& spider);
  void      unregisterSpider(const std::shared_ptr<Spider>& spider);

private:
  void		queueAccept(void);

  void		onAccept(const std::shared_ptr<IConnectSocket>& newSock);
  void		onWrite(const std::shared_ptr<Spider>& spider, size_t size);

  std::unique_ptr<IListenSocket>	_acceptor;
  std::set<std::shared_ptr<Spider>> _clients;
};

#endif
