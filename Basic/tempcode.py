from string import ascii_uppercase
x = [104,372,110,436,262,173,354,393,351,297,241,86,262,359,256,441,124,154,165,165,219,288,42]


a = "0"+ascii_uppercase + "0123456789_"

for i in x:
    print(a[pow(i, -1, 41)], end="")