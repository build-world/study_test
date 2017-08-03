#
import SelectSort
import tool 
array = [7, 9, 6, 1, 5, 3, 2, 4, 8, 0]
print "source array", array, "length=", len(array)
SelectSort.SelectSort_imp(array)
ret = tool.OrderCheck(array,"asc")
print "Sorted array", array, "length=", len(array)
if ret == True: print "Order True"
elif ret == False: print "Order False"