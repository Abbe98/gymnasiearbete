import timeit
from math import radians, sin, cos, sqrt, asin

# haversine(y1, x1, y2, x2)
def haversine():
    lat1 = 58.7530
    lon1 = 17.0115
    lat2 = 58.7515
    lon2 = 16.9857

    r = 6372.8 # earth radius in kilometers

    d_lat = radians(lat2 - lat1)
    d_lon = radians(lon2 - lon1)
    lat1 = radians(lat1)
    lat2 = radians(lat2)

    a = sin(d_lat / 2) ** 2 + cos(lat1) * cos(lat2) * sin(d_lon / 2) ** 2
    c = 2 * asin(sqrt(a))

    result = r * c

print(timeit.timeit(haversine, number=10000000))
