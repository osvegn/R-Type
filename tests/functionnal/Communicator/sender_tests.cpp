/*
** EPITECH PROJECT, 2022
** Project
** File description:
** sender_tests
*/

#include <cstring>
#include "Communicator/Sender.hpp"

using namespace communicator_lib;

int main(int ac, char **av)
{
    Sender send = Sender(4040);
    Client client;

    if (ac != 4)
        return -1;
    client = Client(av[1], std::atoi(av[2]));
    send.sendDataToAClient(client, av[3], sizeof(av[3]) * std::strlen(av[3]));
    send.sendDataToMultipleClients(std::vector<Client>{client}, av[3], sizeof(av[3]) * std::strlen(av[3]));
    return 0;
}