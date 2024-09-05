import sys
import math

def d(p1, p2):
    (x1, x2, y1, y2) = (p2[0], p1[0], p2[1], p1[1])
    (xcalc, ycalc) = (x2 - x1, y2 - y1)
    (xcalc2, ycalc2) = (math.pow(xcalc, 2), math.pow(ycalc, 2))
    calc = (xcalc2 + ycalc2)
    return math.sqrt(calc)

def Closest_Pair_Rec(Px, Py):
    if len(Px) <= 3:
        if len(Px) == 2:
            return (Px[0], Px[1])

        minm = d(Px[0], Px[1])
        (p1, p2) = (Px[0], Px[1])
        first = 0
        for i in Px:
            second = 0
            for j in i:
                if first != 0 and second != 1:
                    delta = d(Px[first], Px[second])
                    if delta < minm:
                        minm = delta
                        (p1, p2) = (Px[first], Px[second])
                second += 1
            first += 1
        return (p1, p2)

    mid_x = Px[len(Px)//2][0]

    Qx = Px[:len(Px)//2]
    Rx = Px[len(Px)//2:]
    Qy = []
    Ry = []
    for point in Py:
        if point[0] <= mid_x:
            Qy.append(point)
        else:
            Ry.append(point)

    (q0, q1) = Closest_Pair_Rec(Qx, Qy)
    (r0, r1) = Closest_Pair_Rec(Rx, Ry)

    dist_q = d(q0, q1)
    dist_r = d(r0, r1)

    delta = min(dist_q, dist_r)
    Sy = []
    for point in Py:
        if mid_x - delta <= point[0] <= mid_x + delta:
            Sy.append(point)

    min_s = delta
    c = 0
    for i in Sy:
        end = min(c + 15, len(Sy))
        for j in range(c + 1, end):
            cur_s = d(Sy[c], Sy[j])
            if cur_s < min_s:
                best_s = (Sy[c], Sy[j])
                min_s = cur_s
        c += 1

    if min_s < delta:
        return best_s
    elif dist_q < dist_r:
        return (q0, q1)
    else:
        return (r0, r1)

def Closest_pair(P):
    Px = sorted(P, key = lambda x: x[0])
    Py = sorted(P, key = lambda x: x[1])
    (p0, p1) = Closest_Pair_Rec(Px, Py)
    print(p0[0], end = " ")
    print(p0[1], end = "\r\n")
    print(p1[0], end = " ")
    print(p1[1], end = "\r\n")


def main():
    F = open(sys.argv[1], "r")
    a = F.readlines()
    P = []
    for line in a:
        line = line.strip('\r\n')
        line = line.split(' ')
        P.append(line)

    for i in range(len(P)):
        P[i] = [float(x) for x in P[i]]

    Closest_pair(P)

main()
