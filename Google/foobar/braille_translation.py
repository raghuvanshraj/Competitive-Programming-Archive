def solution(s):
	d = {
		' ': '000000',
		'letter_cap': '000001',
		'a': '100000',
		'b': '110000',
		'c': '100100',
		'd': '100110',
		'e': '100010',
		'f': '110100',
		'g': '110110',
		'h': '110010',
		'i': '010100',
		'j': '010110',
		'k': '101000',
		'l': '111000',
		'm': '101100',
		'n': '101110',
		'o': '101010',
		'p': '111100',
		'q': '111110',
		'r': '111010',
		's': '011100',
		't': '011110',
		'u': '101001',
		'v': '111001',
		'w': '010111',
		'x': '101101',
		'y': '101111',
		'z': '101011'
	}
	ans = ''
	n = len(s)
	for i in range(0,n):
		if s[i].isupper():
			ans = ans + d['letter_cap']
		ans = ans + d[s[i].lower()]

	return ans

if __name__ == '__main__':
	s = raw_input()
	ans = solution(s)
	print(ans)