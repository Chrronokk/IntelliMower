#
def SavePath(pathList):

    f = open("path_list", 'w')

    for point in pathList:
        f.write("%s" % float(point.x) )
        f.write(' ')
        f.write("%s\n" % float(point.y) )

    f.close()
