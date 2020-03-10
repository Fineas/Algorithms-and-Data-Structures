import random

# =================================================
# DATA SET 1 (10mil random numbers in range 0 - )
# =================================================
def gen1():
    f = open('data1.txt','a')

    for i in range(10000000):
        rnd = random.randint(0, 100000)
        f.write(str(rnd)+' ')

    f.flush()
    f.close()

# =================================================
# DATA SET 2 (10mil random numbers in range 0 - 9)
# =================================================
def gen2():
    f = open('data2.txt','a')  

    for i in range(10000000):
        rnd = i % 10
        f.write(str(rnd)+' ')

    f.flush()
    f.close()

# =================================================
# DATA SET 3 (10mil numbers ascending them descending)
# =================================================
def gen3():
    f = open('data3.txt','a')  
    dec = 500000
    for i in range(10000000):
        if i >= (10000000/2):
            rnd = dec
            dec = dec - 1
        else:
            rnd = i
        f.write(str(rnd)+' ')

    f.flush()
    f.close()

# =================================================
# DATA SET 4 (10mil decreasing order numbers)
# =================================================
def gen4():
    f = open('data4.txt','a')  
    for i in range(10000000,0,-1):
        f.write(str(i)+' ')

    f.flush()
    f.close()

# =================================================
# DATA SET 5 (10mil alternating order min, max, min+1, max-1 ...)
# =================================================
def gen5():
    f = open('data5.txt','a')  
    for i,j in zip(range(0,5000000),range(5000000,0,-1)):
        f.write(str(i)+' ')
        f.write(str(j)+' ')

    f.flush()
    f.close()

# =================================================
# DATA SET 6 (10mil sorted )
# =================================================
def gen6():
    f = open('data6.txt','a')  
    for i in range(0,10000000): 
        f.write(str(i)+' ')

    f.flush()
    f.close()


# =================================================
# MAIN
if __name__ == '__main__':

    print '[*] Test 1'
    #gen1()
    print '[*] Test 2'
    #gen2()
    print '[*] Test 3'
    #gen3()
    print '[*] Test 4'
    #gen4()
    print '[*] Test 5'
    #gen5()
    print '[*] Test 6'
    #gen6()


