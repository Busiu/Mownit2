import numpy as np
import matplotlib.pyplot as plt

Iterations = np.array([1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25])

Jacobi1 = [
1.64286,
1.83673,
1.90598,
1.93071,
1.93954,
1.94269,
1.94382,
1.94422,
1.94436,
1.94442,
1.94443,
1.94444,
1.94444,
1.94444,
1.94444,
1.94444,
1.94444,
1.94444,
1.94444,
1.94444,
1.94444,
1.94444,
1.94444,
1.94444,
1.94444]

Jacobi2 = [
-0.181818,
0.104081,
0.0699677,
0.0740379,
0.0735523,
0.0736102,
0.0736033,
0.0736041,
0.0736041,
0.0736041,
0.0736041,
0.0736041,
0.0736041,
0.0736041,
0.0736041,
0.0736041,
0.0736041,
0.0736041,
0.0736041,
0.0736041,
0.0736041,
0.0736041,
0.0736041,
0.0736041,
0.0736041]

Jacobi3 = [
2.66667,
2.16667,
-5.58333,
31.7917,
-97.6458,
297.948,
-835.036,
2285.42,
-6091.73,
16003.2,
-41538,
106923,
-273446,
695908,
-1.76434e+006,
4.46001e+006,
-1.12483e+007,
2.83174e+007,
-7.11867e+007,
1.78753e+008,
-4.48456e+008,
1.12429e+009,
-2.81701e+009,
7.0551e+009,
-1.76629e+010]

Jacobi4 = [
2.45,
2.49321,
2.51826,
2.52368,
2.52483,
2.52508,
2.52513,
2.52514,
2.52514,
2.52514,
2.52514,
2.52514,
2.52514,
2.52514,
2.52514,
2.52514,
2.52514,
2.52514,
2.52514,
2.52514,
2.52514,
2.52514,
2.52514,
2.52514,
2.52514]

Jacobi5 = [
0.678267,
0.750809,
0.750572,
0.750089,
0.75001,
0.750001,
0.75,
0.75,
0.75,
0.75,
0.75,
0.75,
0.75,
0.75,
0.75,
0.75,
0.75,
0.75,
0.75,
0.75,
0.75,
0.75,
0.75,
0.75,
0.75]

GaussSeidel1 = [
1.64286,
1.83673,
1.90598,
1.93071,
1.93954,
1.94269,
1.94382,
1.94422,
1.94436,
1.94442,
1.94443,
1.94444,
1.94444,
1.94444,
1.94444,
1.94444,
1.94444,
1.94444,
1.94444,
1.94444,
1.94444,
1.94444,
1.94444,
1.94444,
1.94444]

GaussSeidel2 = [
-0.181818,
0.104081,
0.0699677,
0.0740379,
0.0735523,
0.0736102,
0.0736033,
0.0736041,
0.0736041,
0.0736041,
0.0736041,
0.0736041,
0.0736041,
0.0736041,
0.0736041,
0.0736041,
0.0736041,
0.0736041,
0.0736041,
0.0736041,
0.0736041,
0.0736041,
0.0736041,
0.0736041,
0.0736041]

GaussSeidel3 = [
2.66667,
2.16667,
-5.58333,
31.7917,
-97.6458,
297.948,
-835.036,
2285.42,
-6091.73,
16003.2,
-41538,
106923,
-273446,
695908,
-1.76434e+006,
4.46001e+006,
-1.12483e+007,
2.83174e+007,
-7.11867e+007,
1.78753e+008,
-4.48456e+008,
1.12429e+009,
-2.81701e+009,
7.0551e+009,
-1.76629e+010]

GaussSeidel4 = [
2.45,
2.49321,
2.51826,
2.52368,
2.52483,
2.52508,
2.52513,
2.52514,
2.52514,
2.52514,
2.52514,
2.52514,
2.52514,
2.52514,
2.52514,
2.52514,
2.52514,
2.52514,
2.52514,
2.52514,
2.52514,
2.52514,
2.52514,
2.52514,
2.52514]

GaussSeidel5 = [
0.678267,
0.750809,
0.750572,
0.750089,
0.75001,
0.750001,
0.75,
0.75,
0.75,
0.75,
0.75,
0.75,
0.75,
0.75,
0.75,
0.75,
0.75,
0.75,
0.75,
0.75,
0.75,
0.75,
0.75,
0.75,
0.75]

SOR1 = [
1.42857,
1.92327,
1.96266,
1.94737,
1.94405,
1.94428,
1.94444,
1.94445,
1.94445,
1.94444,
1.94444,
1.94444,
1.94444,
1.94444,
1.94444,
1.94444,
1.94444,
1.94444,
1.94444,
1.94444,
1.94444,
1.94444,
1.94444,
1.94444,
1.94444]

SOR2 = [
-0.456364,
0.339593,
-0.0572948,
0.137815,
0.0421231,
0.089037,
0.0660385,
0.0773129,
0.0717859,
0.0744954,
0.0731671,
0.0738183,
0.0734991,
0.0736555,
0.0735788,
0.0736164,
0.073598,
0.073607,
0.0736026,
0.0736048,
0.0736037,
0.0736042,
0.073604,
0.0736041,
0.073604]

SOR3 = [
3.408,
-1.09965,
6.34307,
-7.92511,
30.7912,
-130.418,
736.882,
-4375.22,
26542.3,
-161706,
986469,
-6.01961e+006,
3.67357e+007,
-2.24191e+008,
1.3682e+009,
-8.34989e+009,
5.0958e+010,
-3.10989e+011,
1.89791e+012,
-1.15827e+013,
7.06871e+013,
-4.31392e+014,
2.63272e+015,
-1.6067e+016,
9.80546e+016]

SOR4 = [
2.82495,
2.44723,
2.54214,
2.52235,
2.52555,
2.52508,
2.52515,
2.52514,
2.52514,
2.52514,
2.52514,
2.52514,
2.52514,
2.52514,
2.52514,
2.52514,
2.52514,
2.52514,
2.52514,
2.52514,
2.52514,
2.52514,
2.52514,
2.52514,
2.52514]

SOR5 = [
0.587069,
0.80251,
0.741706,
0.74988,
0.750379,
0.74992,
0.750001,
0.750003,
0.749999,
0.75,
0.75,
0.75,
0.75,
0.75,
0.75,
0.75,
0.75,
0.75,
0.75,
0.75,
0.75,
0.75,
0.75,
0.75,
0.75]

Actual1 = []
for i in range(25):
    Actual1.insert(i, 1.94444)

Actual2 = []
for i in range(25):
    Actual2.insert(i, 0.0736041)

Actual3 = []
for i in range(25):
    Actual3.insert(i, 1.66667)

Actual4 = []
for i in range(25):
    Actual4.insert(i, 2.52514)

Actual5 = []
for i in range(25):
    Actual5.insert(i, 0.75)


plt.plot(Iterations, Jacobi1, 'bD',
         Iterations, GaussSeidel1, 'gs',
         Iterations, SOR1, 'co',
         Iterations, Actual1, 'kX')
plt.savefig('Chart1.png')
plt.show()

plt.plot(Iterations, Jacobi2, 'bD',
         Iterations, GaussSeidel2, 'gs',
         Iterations, SOR2, 'co',
         Iterations, Actual2, 'kX')
plt.savefig('Chart2.png')
plt.show()

plt.plot(Iterations, Jacobi3, 'bD',
         Iterations, GaussSeidel3, 'gs',
         Iterations, SOR3, 'co',
         Iterations, Actual3, 'kX')
plt.savefig('Chart3.png')
plt.show()

plt.plot(Iterations, Jacobi4, 'bD',
         Iterations, GaussSeidel4, 'gs',
         Iterations, SOR4, 'co',
         Iterations, Actual4, 'kX')
plt.savefig('Chart4.png')
plt.show()

plt.plot(Iterations, Jacobi5, 'bD',
         Iterations, GaussSeidel5, 'gs',
         Iterations, SOR5, 'co',
         Iterations, Actual5, 'kX')
plt.savefig('Chart5.png')
plt.show()