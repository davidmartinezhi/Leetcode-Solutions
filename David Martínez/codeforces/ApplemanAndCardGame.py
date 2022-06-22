import string

#variables
coins = 0

n, k = input().split()
n = int(n)
k = int(k)

cards = input()

letters = {}


#map letter frequencies
for c in cards:
    if c in letters:
        letters[c] += 1
    else:
        letters[c] = 1

#traverse letters frequencies
while(k > 0):
    currCoins = 0
    maxCard = 0
    maxCardsIdx = 0

    #get biggest frequency
    for key, v in letters.items():
        if(v > maxCard):
            maxCard = v
            maxCardsChar = key

    #add coin
    if(maxCard > k):
        coins += (k*k)
        k=0
    elif(maxCard < k):
        coins += (maxCard*maxCard)
        k -= maxCard
        letters[maxCardsChar] = 0
    else:
        coins += (k*k)
        k=0        

print(coins)    





#