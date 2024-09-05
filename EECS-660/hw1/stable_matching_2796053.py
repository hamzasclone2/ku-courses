import sys

class Man:
    def __init__(self, pref):
        self.isEngaged = False # starts out not engages
        self.preference = pref # the man's preference list
        self.engagedTo = -1 # not engaged to anybody

class Woman:
    def __init__(self, pref):
        self.isEngaged = False
        self.preference = pref
        self.engagedTo = -1

# the function that does all the work
def stable_matching(numMenWomen, menPreference, womenPreference):
    arrayMen = []
    arrayWomen = []
    for i in range(numMenWomen): # give each man their preferences
        arrayMen.append(Man(menPreference[i]))
        arrayWomen.append(Woman(womenPreference[i]))

    numMarried = 0
    while numMarried < numMenWomen: # while not everyone is engaged
        for inc in range(numMenWomen): # for each man
            if arrayMen[inc].isEngaged == False: #if man is not engaged
                highestPref = arrayMen[inc].preference[0] - 1 # the man's current highest preference
                arrayMen[inc].preference.pop(0) # get rid of the highest preference now
                if arrayWomen[highestPref].isEngaged == False: # if woman is free
                    arrayMen[inc].engagedTo = highestPref # man is now engaged to his highest preference
                    arrayMen[inc].isEngaged = True # man is engaged
                    arrayWomen[highestPref].engagedTo = inc # woman is now engaged to this man
                    arrayWomen[highestPref].isEngaged = True # woman is engaged
                    numMarried += 1 # one more couple is now engaged
                else: # woman is already engaged
                    fiance = arrayWomen[highestPref].engagedTo # the person the woman is currently engaged to
                    # if woman prefers fiance over current proposal
                    if arrayWomen[highestPref].preference.index(inc+1) > arrayWomen[highestPref].preference.index(fiance+1):
                        pass # do nothing
                    else: # woman prefers current proposal over fiance
                        arrayMen[inc].engagedTo = highestPref
                        arrayMen[inc].isEngaged = True
                        arrayWomen[highestPref].engagedTo = inc
                        arrayWomen[highestPref].isEngaged = True
                        arrayMen[fiance].isEngaged = False # fiance is no longer engaged
                        arrayMen[fiance].engagedTo = -1 # fiance is not engaged to anybody

    for count in range(numMenWomen): # output
        print str(count + 1) + ', ' + str(arrayMen[count].engagedTo + 1)

F = open(sys.argv[1], "r") # open the command line file

a = F.readline() # gets number of men and women
numMenWomen = int(a)
menPreference = [None] * numMenWomen
womenPreference = [None] * numMenWomen

F.readline() # skip blank line

for i in range(numMenWomen): # split input strings into an array
    menPreference[i] = []
    a = F.readline()
    a = a.strip('\t\n\r') # gets rid of any whitespace, new lines, or tabs
    menPreference[i] = a.split(",") # gets rid of commas
    menPreference[i] = [int(x) for x in menPreference[i]] # converts string arr -> int arr

F.readline() # skip blank line

for i in range(numMenWomen):
    womenPreference[i] = []
    a = F.readline()
    a = a.strip('\t\n\r')
    womenPreference[i] = a.split(",")
    womenPreference[i] = [int(x) for x in womenPreference[i]]

stable_matching(numMenWomen, menPreference, womenPreference) # call the actual function
