#ifndef _CLIENTNETWORK_HPP_
# define _CLIENTNETWORK_HPP_

# include <iostream>

# include "IConnectSocket.hpp"
# include "APacket.hpp"

# include "HandshakeResult.hpp"
# include "KillConfirm.hpp"
# include "ScreenShot.hpp"
# include "ScreenShotRequest.hpp"
# include "KillRequest.hpp"
# include "ICircularBuffer.hpp"
# include "ISslCtx.hpp"

#include <boost/asio.hpp> //ToRemove boost

class ClientNetwork
{
public:
	ClientNetwork();
	~ClientNetwork();

	bool connect(int port, const std::string& host, const std::string &id);
	bool isConnected() const;

	ClientNetwork &operator<<(const APacket &packet);
	ClientNetwork &operator>>(APacket &packet);

private:
    std::unique_ptr<IConnectSocket> _socket;
    std::shared_ptr<ISslCtx> _context;
    bool _connect;
    boost::asio::io_service _ios;
};

#endif
