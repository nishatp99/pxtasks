import numpy as np
import random
import math
import matplotlib.pyplot as plt
import time
class Particle:
    def __init__(self, side):
        self.side = side
        self.origin = np.array([side/2, side/2])
        self.direction = np.array([0, 1])
        self.pos = self.origin

class Brownian:
    def __init__(self):
        side = 10
        self.p = Particle(side)

    def motion(self):
        forward = self.p.pos + self.p.direction
        if (0 <= forward[0] < self.p.side) and (0 <= forward[1] < self.p.side):
            self.p.pos = forward
        else:
            theta = random.random() * (math.pi)
            c = math.cos(theta)
            s = math.sin(theta)
            rotmat = np.array([[c, -s], [s, c]])
            self.p.direction = np.dot(self.p.direction, rotmat)

    def get_coordinates(self):
        plt.xlim(0, self.p.side)
        plt.ylim(0, self.p.side)
        plt.xlabel("Side")
        plt.ylabel("Side")
        for _ in range(100):
            plt.plot(self.p.pos[0], self.p.pos[1], marker = 'o', color = 'red')
            self.motion()

        plt.show()

b = Brownian()
b.get_coordinates()