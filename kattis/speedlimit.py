while 1:
    stops = int(input())
    prevTime=0
    ans = 0
    if stops == -1:
        break
    for i in range(stops):
        info = input().split()
        speed = int(info[0])
        time = int(info[1])
        ans += int(speed)*(int(time)-prevTime)
        prevTime = int(time)
    print('{} miles'.format(ans))
