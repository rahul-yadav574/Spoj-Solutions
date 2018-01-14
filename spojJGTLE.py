for i in xrange(input()):
    a,b,c = map(int,raw_input().split())
    print "Case "+str(i+1)+": "+str((a*(b*(b+1))*(c*(c+1)))/4)
