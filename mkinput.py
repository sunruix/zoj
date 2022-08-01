#!/home/sunrui/anaconda3/bin/python
import random

class graph:
    def __init__(self, n, m, start=0):
        self.n = n;
        self.m = m;
        self.start = start;
        self.end = start + n - 1;
        self.edges = [];
        for i in range(0, m):
            self.edges.append((random.randint(self.start, self.end), random.randint(self.start, self.end)))

    def set_edges_weight(self, max_weight, min_weight=0):
        self.edges_weight = []
        for e in self.edges:
            self.edges_weight.append(random.randint(min_weight, max_weight))

    def print(self):
        if not self.edges_weight:
            for e in self.edges:
                print(e[0], e[1])
        else:
            for i in range(len(self.edges)):
                print(self.edges[i][0], self.edges[i][1], self.edges_weight[i]);

class mintree:
    def __init__(self, n, start=0):
        self.n = n;
        self.start = start;
        self.end = start + n - 1;
        self.nodes = []
        self.edges = []

        f = random.randint(self.start, self.end)
        self.nodes.append(f)
        while len(self.edges) != n - 1:
            f = random.randint(self.start, self.end)
            t = random.randint(self.start, self.end)
            if (f in self.nodes and t not in self.nodes):
                self.edges.append((f, t))
                self.nodes.append(t)

    def print(self):
        for e in self.edges:
            print(e[0], e[1])

def pick(g, m, k):
    l = []
    for i in range(0, m):
        s = str(random.randint(g.start, g.end))
        for j in range(0, k - 1):
            s += ' ' + str(random.randint(g.start, g.end))
        l.append(s)
    return l

def randstr(n, char_set = 'abcdefghijklmnopqrstuvsxyz'):
    s = ''
    for i in range(n):
        s += random.sample(char_set, k = 1)[0]
    return s

'''
n = 50
print(n)
for i in range(n):
    p = random.randint(1, 10)
    l = random.randint(1, 100)
    d = random.randint(1, 50) + l
    print(p, l, d)
    '''
n = 100000
print(n)
cmds = ['Push', 'Pop', 'PeekMedian']
for i in range(n):
    ci = random.randint(0, 2)
    if ci == 0:
        print(cmds[ci], random.randint(1, 100000))
    else:
        print(cmds[ci])
