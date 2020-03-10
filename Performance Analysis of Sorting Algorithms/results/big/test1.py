from pwn import *
from termcolor import colored

def test_mergesort():
    program_name = '../../executables/MERGE'
    sort_average = []
    for i in range(1,7):
        t='='*6+' TEST'+str(i)+' '+'='*6
        print colored(t,'red')
        test_average = []
        data_set = '../../dataset/big/data'+str(i)+'.txt'
        for j in range(4):
            p = process([program_name, data_set])
            output = p.recv()
            p.close()
            print colored(output.strip(),'yellow')
            time = output.split('= ')[1].strip()
            test_average.append(time)
        print '> test results =',colored(test_average,'green')
        sort_average.append((float(test_average[0])+float(test_average[1])+float(test_average[2])+float(test_average[3]))/4)
    average = (sort_average[0]+sort_average[1]+sort_average[2]+sort_average[3]+sort_average[4]+sort_average[5])/6
    print sort_average,'=>',average
    return average

def test_heapsort():
    program_name = '../../executables/HEAP'
    sort_average = []
    for i in range(1,7):
        t='='*6+' TEST'+str(i)+' '+'='*6
        print colored(t,'red')
        test_average = []
        data_set = '../../dataset/big/data'+str(i)+'.txt'
        for j in range(4):
            p = process([program_name, data_set])
            output = p.recv()
            p.close()
            print colored(output.strip(),'yellow')
            time = output.split('= ')[1].strip()
            test_average.append(time)
        print '> test results =',colored(test_average,'green')
        sort_average.append((float(test_average[0])+float(test_average[1])+float(test_average[2])+float(test_average[3]))/4)
    average = (sort_average[0]+sort_average[1]+sort_average[2]+sort_average[3]+sort_average[4]+sort_average[5])/6
    print sort_average,'=>',average
    return average

def test_quicksort():
    program_name = '../../executables/QUICK'
    sort_average = []
    for i in range(1,7):
        t='='*6+' TEST'+str(i)+' '+'='*6
        print colored(t,'red')
        test_average = []
        data_set = '../../dataset/big/data'+str(i)+'.txt'
        for j in range(4):
            p = process([program_name, data_set])
            output = p.recv()
            p.close()
            print colored(output.strip(),'yellow')
            time = output.split('= ')[1].strip()
            test_average.append(time)
        print '> test results =',colored(test_average,'green')
        sort_average.append((float(test_average[0])+float(test_average[1])+float(test_average[2])+float(test_average[3]))/4)
    average = (sort_average[0]+sort_average[1]+sort_average[2]+sort_average[3]+sort_average[4]+sort_average[5])/6
    print sort_average,'=>',average
    return average

def test_radixsort(): # test 3 not working
    program_name = '../../executables/RADIX'
    sort_average = []
    for i in range(1,7):
        t='='*6+' TEST'+str(i)+' '+'='*6
        print colored(t,'red')
        test_average = []
        data_set = '../../dataset/big/data'+str(i)+'.txt'
        for j in range(4):
            p = process([program_name, data_set])
            output = p.recv()
            p.close()
            print colored(output.strip(),'yellow')
            time = output.split('= ')[1].strip()
            test_average.append(time)
        print '> test results =',colored(test_average,'green')
        sort_average.append((float(test_average[0])+float(test_average[1])+float(test_average[2])+float(test_average[3]))/4)
    average = (sort_average[0]+sort_average[1]+sort_average[2]+sort_average[3]+sort_average[4]+sort_average[5])/6
    print sort_average,'=>',average
    return average

if __name__ == '__main__':
    if len(sys.argv) == 1:
        results = []
        results.append(test_heapsort())
        results.append(test_mergesort())
        results.append(test_radixsort())
        results.append(test_quicksort())
        print results
        results = set(results)
        resuls = list(results)
        print results
    elif 'radix' in sys.argv:
        test_radixsort()
    elif 'quick' in sys.argv:
        test_quicksort()
    elif 'heap' in sys.argv:
        test_heapsort()
    elif 'merge' in sys.argv:
        test_mergesort()
    else:
        exit