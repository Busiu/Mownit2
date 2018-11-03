import plotly.plotly as py
import plotly.graph_objs as go

# Add data
frequency = []
for i in range(64):
    frequency.insert(i, (i+1) / 64)

spectrum = [
18.766,
2.98133,
4.48258,
30.9751,
9.226,
3.77078,
2.08648,
1.04518,
2.77109,
0.430739,
0.3387,
1.22648,
1.22039,
1.27966,
0.350481,
0.857313,
1.31818,
2.26668,
0.896766,
0.912927,
0.786658,
0.950971,
2.57581,
0.294185,
0.967208,
0.658729,
0.71321,
0.591174,
0.352196,
0.933485,
1.4192,
0.976558,
0.682209,
0.976558,
1.4192,
0.933485,
0.352196,
0.591174,
0.71321,
0.658729,
0.967208,
0.294185,
2.57581,
0.950971,
0.786658,
0.912927,
0.896766,
2.26668,
1.31818,
0.857313,
0.350481,
1.27966,
1.22039,
1.22648,
0.3387,
0.430739,
2.77109,
1.04518,
2.08648,
3.77078,
9.226,
30.9751,
4.48258,
2.98133
]

# Create and style traces
trace = go.Scatter(
    x = frequency,
    y = spectrum,
    name = 'Spectrum',
    line = dict(
        color = ('rgb(30, 210, 30)'),
        width = 1)
)

data = [trace]

py.iplot(data, filename='styled-line')