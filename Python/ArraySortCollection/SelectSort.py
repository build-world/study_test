#SelectSort Module
def SelectSort_imp(array):
#improve basic SelectSrot
	length = len(array)
	i = 0
	while i < length - 1:
		lownum = array[i]
		lowcur = i
		j = i + 1
		while j < length:
			if array[j] < lownum:
				lownum = array[j]
				lowcur = j
			j += 1
		if lowcur != i:
			temp = array[lowcur]
			array[lowcur] = array[i]
			array[i] = temp
		i += 1
	return
#end
