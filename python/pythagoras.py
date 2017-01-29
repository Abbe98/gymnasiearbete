import timeit
from math import cos, sqrt, pi

# pythagoras(lat1, lon1, lat2, lon2)
def pythagoras():
    y1 = 58.7530
    x1 = 17.0115
    y2 = 58.7515
    x2 = 16.9857
    # cos() and the dist operation is requried to make up for the decending lon at the poles

    x = (x2 - x1) ** 2
    y = ((y2 - y1) * cos(y1)) ** 2
    
    dist = ((2 * pi * 3961.3) / 360) * sqrt(x + y)
    return dist

print(timeit.timeit(pythagoras, number=10000000))
