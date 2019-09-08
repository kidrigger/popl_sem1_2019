#!/usr/bin/env python3

"""
Inheritance.cpp
Author: Anish Bhobe
For Principles of Programming Languages, Sem I, 2019-20
BITS Pilani, K. K. Birla Goa Campus
Date: 09 Sept 2019
"""

class vec3:
    def __init__(self, x, y, z):
        self.x = x
        self.y = y
        self.z = z

class ray:
    def __init__(self, o, d):
        self.origin = o
        self.direction = d

class sphere:
    def __init__(self, cen, rad):
        self.center = cen
        self.radius = rad
    
    def hit(self, r):
        print('sphere', self.center.x, self.center.y, self.center.z, self.radius)
        return True

class triangle:
    def __init__(self, a, b, c):
        self.A = a
        self.B = b
        self.C = c

    def hit(self, r):
        print('triangle', self.A.x, self.A.y, self.A.z, self.B.x, self.B.y, self.B.z, self.C.z, self.C.y, self.C.z)
        return True

def hit(s, r):
    return s.hit(r)

if __name__ == "__main__":
    s = sphere(vec3(0,0,0), 1)
    r = ray(vec3(0,0,0), vec3(1,1,1))
    hit(s, r)
