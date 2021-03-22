def chinese2digits1(S: str):
    chinese2num = {'零': 0, '一': 1, '二': 2, '两': 2, '三': 3, '四': 4, '五': 5, '六': 6, '七': 7, '八': 8, '九': 9, '十': 10,
                   '百': 100, '千': 1000, '万': 10000, '亿': 100000000}
    if not str:
        return 0
    d = 1
    total = 0
    for i in range(len(S) - 1, 0, -1):
        num = chinese2num[S[i]]
        if num >= 10:
            if d < num:
                d = num
            else:
                d = num * d
        else:
            total += d * num
    if S[0] == '十':
        total += d * 10
    else:
        num = chinese2num[S[0]]
        total += d * num
    return total


print(chinese2digits1('十三万三千一百五十'))

