
# get data from file and converts to a list of lists of integers
def get_data() -> list:
    with open("cn.in") as file:
        data = file.readlines()

    for i in range(len(data)):
        data[i] = data[i].split(" ")
        for j in range(len(data[i])):
            data[i][j] = int(data[i][j])

    return data


# parse data to facilitate manipulation
def parse_data(data: list) -> dict:
    networks = {}
    network_number = 1      # this will be each network's index
    i = 0
    while data[i][0] != 0:  # stops with file delimiter '0'

        num_clients = data[i][0]
        fee = data[i][1]
        table = [[0 for _ in range(num_clients)] for __ in range(num_clients)]

        # put zeros as placeholders to match indexes
        for i, j in zip(range(i + 1, i + num_clients + 1), range(num_clients)):
            for k in range(len(data[i])):
                table[j][k + j] = data[i][k]

        # this will rotate the "matrix" 90 degrees anti-clockwise
        # for i in range(i + 1, i + num_clients + 1):
        #     for j, k in zip(range(len(data[i])), range(len(data[i])-1, -1, -1)):
        #         table[k].append(data[i][j])

        # save data from each network into a dictionary
        networks.update(
            {network_number: {
                "num_clients": num_clients,
                "fee": fee,
                "table": table,
                }
            }
        )
        i += 1
        network_number += 1

    return networks


def solution(networks: dict):

    for key, value in networks.items():     # for each network
        output = ""

        num_clients = value['num_clients']
        fee = value['fee']
        table = value['table']
        pot_init_cap = num_clients * fee    # potential initial capital

        output += f"Cable Net #{key}\n{pot_init_cap}\n"

        total_linking_cost = 0
        disconnected = 0        # n. of clients not connected of network
        graph = {}

        # map the graph
        for i in range(len(table)):
            for j in range(len(table[i])):
                cost = table[i][j]
                if cost > 0:
                    if not graph.get(i):
                        graph.update({i: {}})
                    graph[i].update({j+1: cost})
        # print(graph)



        # formula for loss in the potential initial capital
        loss = total_linking_cost + (fee * disconnected)

        # save to the output string, then to output file
        output += f"{loss}\n\n"
        save_output(output)


def save_output(output):
    with open("cn.out", mode="a") as file:
        file.write(output)


def main():
    data = get_data()
    networks = parse_data(data)
    # print(networks)
    solution(networks)


if __name__ == '__main__':
    main()