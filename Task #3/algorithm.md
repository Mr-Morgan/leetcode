https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

1. O(n)

	На каждой итерации "увеличиваем" подстроку если новый символ не содержится в подстроке, и записываем его индекс в строке.
	Если размер теукщей подстроки больше максимальной перезаписываем его.
	Если содержится, то "откидываем" все символы по повторяющийся включительно (тот, что в строке встречается раньше - имеет меньший индекс), перезаписываем индекс "последнего встреченного символа". 
	Продолжаем увеличивать подстроку (возвращаемся в начало алгоритма).
	По окончании цикла возвращаем максимальный размер подстроки.
	

	