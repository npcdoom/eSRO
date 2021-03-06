/*********************************************************************************
 *
 * This file is part of eSRO.
 *
 * eSRO is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as
 * published by the Free Software Foundation, either version 3 of the
 * License, or (at your option) any later version.
 *
 * eSRO is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Copyright ⓒ 2013  Rafael Dominguez (npcdoom)
 *
 *********************************************************************************/

#ifndef __MASTER_SERVER_STATE_SHARD_HPP__
#define __MASTER_SERVER_STATE_SHARD_HPP__

#include <server_connection_state.hpp>

class Server;
class Connection;

class StateShard : public srv::ConnectionState
{
public:

    StateShard (Connection *conn, Server *srv);

    virtual ~StateShard ();

    virtual void Close ();

private:

    int OnConfig (IPacket &packet);

    int OnAccountNotify (IPacket &packet);

    int OnShardNotify (IPacket &packet);

private:

    Server *m_server;
};

#endif //__MASTER_SERVER_STATE_SHARD_HPP__
