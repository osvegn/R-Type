/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Sender
*/

/// @file libs/Communicator/Sender.cpp

#include "Sender.hpp"
#include <boost/asio.hpp>
#include <boost/array.hpp>
#include <boost/bind/bind.hpp>
#include <iostream>

using namespace communicator_lib;
using namespace boost::asio::ip;

Sender::Sender()
{
}

void Sender::sendDataToAClient(Client &client, void *data)
{
    boost::asio::io_service io_service;
    udp::socket socket(io_service);
    udp::endpoint socket_endpoint = udp::endpoint(boost::asio::ip::address::from_string(client.getAddress()), client.getPort());
    boost::system::error_code error;

    socket.open(udp::v4());
    auto sent = socket.send_to(boost::asio::buffer(data, 100000), socket_endpoint, 0, error);
    socket.close();
    std::cerr << "Message send. " << sent << "bytes transfered." << std::endl;
}

void Sender::sendDataToMultipleClients(std::vector<Client> clients, void *data)
{
    (void) clients;
    (void) data;
}

Sender::~Sender()
{
}
