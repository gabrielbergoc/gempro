
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

        table = [[0 for _ in range(num_clients + 1)] for __ in range(num_clients + 1)]
        for i, j in zip(range(i + 1, i + num_clients + 1), range(num_clients)):
            for k in range(len(data[i])):
                table[j][k + j + 1] = data[i][k]

        for x in range(len(table)):
            for y in range(len(table)):
                table[y][x] = table[x][y]

        # print_matrix(table)
        
        # modifies table of costs and returns a matrix of the shortest paths
        paths = shortest_path(table)
        
        # print_matrix(table)
        # print_matrix(paths)

        # save data from each network into a dictionary
        networks.update({
            network_number: {
                "num_clients": num_clients,
                "fee": fee,
                "table": table,
                "paths": paths,

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
        paths = value['paths']
        
        pot_init_cap = num_clients * fee    # potential initial capital

        output += f"Cable Net #{key}\n{pot_init_cap}\n"

        total_linking_cost = 0
        disconnected = 0        # n. of clients not connected of network

        for i in range(1, num_clients + 1):
            cost = table[0][i]  # look only for paths connected to central
            next_ = paths[0][i]  # next node of shortest path

            if cost < fee:
                
                # while there's a path between central and client
                while next_ != i:
                    
                    # subtract intermediate costs in order to not compute the
                    # same path more than once
                    cost -= table[0][next_]
                    
                    # look for next node of the path
                    next_ = paths[next_][i]

                total_linking_cost += cost
            
            # if it costs more than subscription fee to link a client to the
            # network, don't connect this client
            else:
                disconnected += 1

        # formula for loss in the potential initial capital
        loss = total_linking_cost + (fee * disconnected)

        # save to the output string, then to output file
        output += f"{loss}\n\n"
        save_output(output)


# Roy-Floyd-Warshall algorithm to find shortest paths in a graph
# https://en.wikipedia.org/wiki/Floyd%E2%80%93Warshall_algorithm
def shortest_path(dist: list):
    lenght = len(dist)

    next_ = [[0 for _ in range(lenght)] for __ in range(lenght)]
    for m in range(lenght):
        for n in range(lenght):
            if m == n:
                next_[m][n] = 0
            else:
                next_[m][n] = n

    for k in range(lenght):
        for i in range(lenght):
            for j in range(lenght):
                if dist[i][j] > dist[i][k] + dist[k][j]:
                    dist[i][j] = dist[i][k] + dist[k][j]
                    next_[i][j] = next_[i][k]

    return next_


# to better view the matrices
def print_matrix(matrix):
    print("\t", end="")
    for n in range(len(matrix)):
        print(f"{n}\t", end="")
    print("\n")
    for x in range(len(matrix)):
        print(f"{x}\t", end="")
        for y in range(len(matrix)):
            print(f"{matrix[x][y]}\t", end="")
        print("\n")
    print("\n")


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