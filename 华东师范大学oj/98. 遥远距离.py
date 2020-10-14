n = int(input())
Tmax = int(input())
Tmin = Tmax
for i in range(1, n):
    t = int(input())
    if t>Tmax:
        Tmax = t
    if t<Tmin:
        Tmin = t
print(Tmax-Tmin)
