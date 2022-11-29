from socket import *
from time import ctime
import time

def init():
    global goodIp, badIp, goodUser, badUser
    goodIp, badIp, goodUser, badUser = set(), set(), set(), set()

    global NTime, NNum
    NTime, NNum = 5, 20

    global badTimeList
    badTimeList = [60, 300, 600]

    global badCntMax
    badCntMax = 3

    global maxHistoryLen
    maxHistoryLen = 50


class user(object):
    def __init__(self, str):
        self.userName = str
        self.isOk = 1                    # today is ok? if badNum > badCntMax, isOk = 0
        self.badNum = 0                  # plenty cnt today
        self.history = []                # last maxHistoryLen visit history
        self.badStartTime = -1           # plent start time for now, if not -1
        self.badLength = -1              #plent time length for now

def getDx(a):
    x = sum(a, 0) / len(a)
    ans = 0.0
    for i in a:
        ans += (x - i) * (x - i)
    return ans / len(a)

def timeToss(s):
    return int(s[11: 13]) * 3600 + int(s[14: 16]) * 60 + int(s[17: 19])


total = dict()

def solve(data):
    g = data.strip().split(',')

    #flag wheither is information for badUser, badIp, goodIp, goodUser
    id, bookId, userIp, userName, pageId, createTime, flag, = g[0], g[1], g[2], g[3], g[4], g[5], g[6]
    createTime = timeToss(createTime)

    #update good_bad_list
    flag = int(flag)
    if flag != -1:
        if flag == 0:
            if userName != '':
                badUser.add(userName)
            if userIp != '':
                badUser.add(userIp)
        if flag == 1:
            if userName != '':
                goodUser.add(userName)
            if userIp != '':
                goodIp.add(userIp)
    #check if is a new one
    if not (userName in total):
        total[userName] = user(userName)

    #check if is in good_bad_list
    if userName in goodUser:
        return [id, 1]
    if userName in badUser:
        return [id, 0]
    if userIp in goodIp:
        return [id, 1]
    if userIp in badIp:
        return [id, 0]

    #check if today is ok
    if total[userName].isOk == 0:
        return [id, 0]

    #check if now in badTime
    p = total[userName]
    ts = timeToss(createTime)
    if p.badStartTime != -1 and ts >= p.badStartTime and ts <= p.badStartTime + p.badLength:
        return [id, 0]

    #if userName is not empty
    if userName != '':
        #keep last maxHistoryLen visit history
        total[userName].history.insert(0, g[0: 6])
        while len(total[userName].history) > maxHistoryLen:
             total[userName].history.pop()

        # check if to ofen
        cnt = 0
        for i in total[userName].history:
            if i[5] <= ts - NTime:
                break
            cnt += 1

        #for one day badCntMax num plent
        if cnt >= NNum:
            if total[userName].badNum < badCntMax:
                total[userName].badStartTime = ts
                total[userName].badLength = badTimeList[total[userName].badNum]
                total[userName].badNum += 1
            else:
                total[userName].isOk = 0
            return [id, 0]

    #for test
    print 'over'



def startServer():
    HOST = ''
    PORT = 21568
    BUFSIZ = 1024
    ADDR = (HOST, PORT)

    tcpSerSock = socket(AF_INET, SOCK_STREAM)
    tcpSerSock.bind(ADDR)
    tcpSerSock.listen(5)

    #while True:
    print 'waiting for connection...'
    tcpCliSock, ad = tcpSerSock.accept()
    print '...connected from:', ad

    while True:
        data = tcpCliSock.recv(BUFSIZ)
        if not data:
            break
        solve(data)
        tcpCliSock.send('[%s] %s' % (ctime(), data))

    tcpCliSock.close()
    tcpSerSock.close()

init()

# print NTime
# a = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
# print a
# a.insert(0, 5)
# print a
# a.pop()
# print a
#
# flag = '-1'
# print int(flag) + 4

s = set([1, 2])
s.add(4)
print 1 in s
solve('9,11108051,10.183.34.63,10903007,00000135,2014-07-04 12:00:07,-1')
#startServer()