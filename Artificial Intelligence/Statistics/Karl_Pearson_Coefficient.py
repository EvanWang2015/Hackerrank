#print all the moves here
def Karl_Pearson_Coefficient(phy, his):
    x1_mean = sum(phy)/float(len(phy))
    
    x2_mean = float(sum(his))/len(his)
    import math
    numerator = numpy.dot(phy-x1_mean, his-x2_mean)
    phy =phy-x1_mean
    his = his-x2_mean
    his = [math.pow(i,2) for i in his]
    phy = [math.pow(i,2) for i in phy]
    denominator =math.sqrt(numpy.sum(his) * numpy.sum(phy))
    res = numerator/denominator
    print("%.3f" % res)
    #print(denominator)