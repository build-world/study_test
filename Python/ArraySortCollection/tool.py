#
def OrderCheck(array,order):
#order def
	if order == "asc" or order == "ASC": order = 1
	elif order == "desc" or order == "DESC": order = -1
	length = len(array)
	cur = 0
	if order == 1:
		while cur < length - 1:
			if array[cur] > array[cur + 1]: return False
			cur += 1
	elif order == -1:
		while cur < length -1:
			if array[cur] < array[cur + 1]: return False
			cur += 1
	return True
#end OrderCheck