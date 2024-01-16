import sys
from pprint import pprint


def prims(G):
    added = set() # just store index of vertex
    added.add(0) # 0 is default root
    A = []
    while len(added) < len(G): # keep going while more edges exist
        minimum = float('inf') # find min edge where one vertex is in 'added'
        min_r = min_c = -1
        for r in range(len(G)):
            if r in added:
                for c in range(len(G)):
                    if minimum > G[r][c] and G[r][c] != 0 and (r not in added or c not in added):
                        minimum = G[r][c]
                        min_r = r
                        min_c = c
        A.append((min_r,min_c))
        added.add(min_r)
        added.add(min_c)
    return A


def main():
    if len(sys.argv) == 1:
        weights = [[0] * 4 for _ in range(4)]
        for r in range(4):
            for c in range(4):
                if (r == 0 and c == 1) or (c == 0 and r == 1):
                    weights[r][c] = 4
                    weights[c][r] = 4
                if (r == 0 and c == 2) or (c == 0 and r == 2):
                    weights[r][c] = 2
                    weights[c][r] = 2
                if (r == 1 and c == 2) or (c == 2 and r == 1):
                    weights[r][c] = 8
                    weights[c][r] = 8
                if (r == 3 and c == 1) or (r == 1 and c == 3):
                    weights[r][c] = 4
                    weights[c][r] = 4
    else:
        weights = []
        filename = sys.argv[1]
        print(f"reading from file {filename}")
        with open(filename, 'r') as f:
            for row in f.readlines():
                r = [int(x) for x in row.split()]
                weights.append(r)
        pprint(f'{weights=}')
    print('answer: ', prims(weights))
if __name__ == "__main__":
    main()