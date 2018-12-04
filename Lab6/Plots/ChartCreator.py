import numpy as np
import matplotlib.pyplot as plt

Iterations = np.array([3, 6, 9, 12, 15, 18, 21, 24, 27, 30])

LinearRect = [
200,
175,
166.667,
162.5,
160,
158.333,
157.143,
156.25,
155.556,
155
]
LinearTrap = [
150,
150,
150,
150,
150,
150,
150,
150,
150,
150
]
LinearSimp = [
150,
150,
150,
150,
150,
150,
150,
150,
150,
150
]
QuadraticRect = [
2165.93,
1738.15,
1605.84,
1541.62,
1503.7,
1478.68,
1460.94,
1447.7,
1437.44,
1429.26
]
QuadraticTrap = [
1449.26,
1379.81,
1366.95,
1362.45,
1360.37,
1359.24,
1358.56,
1358.11,
1357.81,
1357.59
]
QuadraticSimp = [
1356.67,
1356.67,
1356.67,
1356.67,
1356.67,
1356.67,
1356.67,
1356.67,
1356.67,
1356.67
]
CubicRect = [
1366.67,
891.667,
751.852,
685.417,
646.667,
621.296,
603.401,
590.104,
579.835,
571.667
]
CubicTrap = [
666.667,
541.667,
518.519,
510.417,
506.667,
504.63,
503.401,
502.604,
502.058,
501.667
]
CubicSimp = [
500,
500,
500,
500,
500,
500,
500,
500,
500,
500
]
ExponentialRect = [
76134.2,
45257.1,
36482.5,
32462.9,
30177.1,
28707.3,
27684.3,
26931.8,
26355.5,
25899.9
]
ExponentialTrap = [
39425.1,
26902.5,
24246.2,
23285.6,
22835.2,
22589.1,
22440.1,
22343.2,
22276.7,
22229
]
ExponentialSimp = [
22728.3,
22079.9,
22036.7,
22029.1,
22027,
22026.2,
22025.9,
22025.7,
22025.6,
22025.6
]
SinusoidalRect = [
-1.20146,
0.9389,
1.34362,
1.50472,
1.58911,
1.64041,
1.67466,
1.69905,
1.71726,
1.73134
]
SinusoidalTrap = [
-0.294758,
1.39225,
1.64586,
1.73139,
1.77045,
1.79153,
1.80419,
1.81239,
1.818,
1.82201
]
SinusoidalSimp = [
1.95459,
1.84444,
1.84008,
1.83939,
1.8392,
1.83913,
1.8391,
1.83909,
1.83908,
1.83908,
]
MonteCarloPi = [
2.92,
3.06,
3.08,
3.1,
3.12,
3.2,
3.22286,
3.215,
3.2,
3.14,
3.14182,
3.13,
3.11077,
3.10857,
3.10933,
3.105,
3.09412,
3.1,
3.11789,
3.128,
3.12762,
3.12182,
3.11826,
3.13,
3.1184,
3.11846,
3.11259,
3.11429,
3.11448,
3.11867,
3.11613,
3.115,
3.12,
3.12471,
3.12914,
3.13111,
3.13189,
3.13263,
3.12821,
3.13,
3.12488,
3.11714,
3.11442,
3.11091,
3.11111,
3.10696,
3.10383,
3.10333,
3.10612,
3.1048,
3.10667,
3.10923,
3.1117,
3.11111,
3.11709,
3.11643,
3.11018,
3.11103,
3.10983,
3.11267,
3.11213,
3.11484,
3.11746,
3.11437,
3.11508,
3.11636,
3.11224,
3.11176,
3.11014,
3.11143,
3.11549,
3.11611,
3.11507,
3.11568,
3.10987,
3.10947,
3.11377,
3.11333,
3.11544,
3.12,
3.11901,
3.11854,
3.11711,
3.11381,
3.11576,
3.11674,
3.11586,
3.11818,
3.11955,
3.11956,
3.11736,
3.11565,
3.11828,
3.12,
3.12168,
3.11875,
3.12,
3.12327,
3.12485,
3.126
]

LinearActual = []
for i in range(10):
    LinearActual.insert(i, 150)

QuadraticActual = []
for i in range(10):
    QuadraticActual.insert(i, 1356.67)

CubicActual = []
for i in range(10):
    CubicActual.insert(i, 500)

ExponentialActual = []
for i in range(10):
    ExponentialActual.insert(i, 22025.465795)

SinusoidalActual = []
for i in range(10):
    SinusoidalActual.insert(i, 1.8391)

PiActual = []
for i in range(100):
    PiActual.insert(i, 3.1416)

Zad3Iterations = []
for i in range(100):
    Zad3Iterations.insert(i, (i+1)*100)

LinearMont = [
167.28,
156.632,
153.797,
150.687,
151.526,
152.213,
150.652,
150.241,
149.243,
149.652
]
QuadraticMont = [
1585.49,
1420.62,
1390.89,
1357.35,
1360.99,
1384.61,
1362.24,
1362.18,
1342.77,
1349.03
]
CubicMont = [
627.29,
519.371,
504.726,
493.659,
489.396,
523.834,
507.534,
512.928,
494.061,
500.617
]
ExponentialMont = [
23887.8,
22377.8,
22117.3,
21949.7,
21879.3,
23296.6,
22722.2,
22909,
22157.3,
22539.6
]
SinusoidalMont = [
1.99095,
1.77205,
1.63164,
1.73003,
1.82058,
1.92953,
1.8943,
1.91276,
1.84116,
1.85549
]
Zad4Iterations = []
for i in range(10):
    Zad4Iterations.insert(i, (i+1)*100)

plt.plot(Iterations, LinearRect, 'bD',
         Iterations, LinearTrap, 'gs',
         Iterations, LinearSimp, 'co',
         Iterations, LinearActual, 'kX')
plt.savefig('Linear.png')
plt.show()

plt.plot(Iterations, QuadraticRect, 'bD',
         Iterations, QuadraticTrap, 'gs',
         Iterations, QuadraticSimp, 'co',
         Iterations, QuadraticActual, 'kX')
plt.savefig('Quadratic.png')
plt.show()

plt.plot(Iterations, CubicRect, 'bD',
         Iterations, CubicTrap, 'gs',
         Iterations, CubicSimp, 'co',
         Iterations, CubicActual, 'kX')
plt.savefig('Cubic.png')
plt.show()

plt.plot(Iterations, ExponentialRect, 'bD',
         Iterations, ExponentialTrap, 'gs',
         Iterations, ExponentialSimp, 'co',
         Iterations, ExponentialActual, 'kX')
plt.savefig('Exponential.png')
plt.show()

plt.plot(Iterations, SinusoidalRect, 'bD',
         Iterations, SinusoidalTrap, 'gs',
         Iterations, SinusoidalSimp, 'co',
         Iterations, SinusoidalActual, 'kX')
plt.savefig('Sinusoidal.png')
plt.show()

plt.plot(Zad3Iterations, MonteCarloPi, 'bD',
         Zad3Iterations, PiActual, 'gs')
plt.savefig('MCPi.png')
plt.show()

plt.plot(Zad4Iterations, LinearMont, 'bD',
         Zad4Iterations, LinearActual, 'kX')
plt.savefig('MCLinear.png')
plt.show()

plt.plot(Zad4Iterations, QuadraticMont, 'bD',
         Zad4Iterations, QuadraticActual, 'kX')
plt.savefig('MCQuadratic.png')
plt.show()

plt.plot(Zad4Iterations, CubicMont, 'bD',
         Zad4Iterations, CubicActual, 'kX')
plt.savefig('MCCubic.png')
plt.show()

plt.plot(Zad4Iterations, ExponentialMont, 'bD',
         Zad4Iterations, ExponentialActual, 'kX')
plt.savefig('MCExponential.png')
plt.show()

plt.plot(Zad4Iterations, SinusoidalMont, 'bD',
         Zad4Iterations, SinusoidalActual, 'kX')
plt.savefig('MCSinusoidal.png')
plt.show()

