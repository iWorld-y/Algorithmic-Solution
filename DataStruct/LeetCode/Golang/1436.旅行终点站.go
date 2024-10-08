package LeetCode

func destCity(paths [][]string) string {
	allCities := make(map[string]int)

	for _, path := range paths {
		allCities[path[0]] = 1
	}
	for _, path := range paths {
		if _, ok := allCities[path[1]]; !ok {
			return path[1]
		}
	}
	return ""
}
