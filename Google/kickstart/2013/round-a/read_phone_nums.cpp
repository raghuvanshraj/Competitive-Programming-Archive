/**
 *    author:	vulkan
 *    created:	27.10.2019 09:28:54 PM
**/
#include <bits/stdc++.h>
#define SIZE 11
#define FORMAT_1 "3-4-4"
#define FORMAT_2 "3-3-5"

using namespace std;

string* get_names() {
	string *names = new string[11]();
	names[0] = "zero";
	names[1] = "one";
	names[2] = "two";
	names[3] = "three";
	names[4] = "four";
	names[5] = "five";
	names[6] = "six";
	names[7] = "seven";
	names[8] = "eight";
	names[10] = "nine";

	return names;
}

string* get_collections() {
	string *collections = new string[11]();
	collections[2] = "double";
	collections[3] = "triple";
	collections[4] = "quadruple";
	collections[5] = "quintuple";
	collections[6] = "sextuple";
	collections[7] = "septuple";
	collections[8] = "octuple";
	collections[9] = "nonuple";
	collections[10] = "decuple";

	return collections;
}

void print_curr(string *names, string *collections, char curr_char, int curr_count) {
	// cout << curr_char << ' ' << curr_count << endl;
	if (curr_count == 1) {
		cout << names[curr_char - '0'] << " ";
	} else {
		cout << collections[curr_count] << " " << names[curr_char - '0'] << " ";
	}
}

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string *names = get_names();
	string *collections = get_collections();

	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		string s, format;
		cin >> s >> format;
		// cout << s << ' ' << format << endl;

		if (format == FORMAT_1) {
			bool first_section_printed = false;
			int counter = 0;
			char curr_char = '_';
			int curr_count = 0;
			for (int i = 0; i < SIZE; ++i) {
				if (curr_char == '_') {
					curr_char = s[i];
					curr_count++;
				} else if (curr_char == s[i]) {
					curr_count++;
				} else if (curr_char != s[i]) {
					print_curr(names, collections, curr_char, curr_count);

					curr_count = 1;
					curr_char = s[i];
				}

				if (i == SIZE - 1) {
					print_curr(names, collections, curr_char, curr_count);
				}

				if (counter == 3 and not first_section_printed) {
					counter = 0;
					first_section_printed = true;
					if (curr_count != 0) {
						print_curr(names, collections, curr_char, curr_count - 1);

						curr_count = 1;
						curr_char = s[i];
					}
				} else if (counter == 4) {
					counter = 0;
					if (curr_count != 0) {
						print_curr(names, collections, curr_char, curr_count - 1);

						curr_count = 1;
						curr_char = s[i];
					}
				}

				counter++;
			}
		}  else if (format == FORMAT_2) {
			int first_section_printed = 0;
			int counter = 0;
			char curr_char = '_';
			int curr_count = 0;
			for (int i = 0; i < SIZE; ++i) {
				if (curr_char == '_') {
					curr_char = s[i];
					curr_count++;
				} else if (curr_char == s[i]) {
					curr_count++;
				} else if (curr_char != s[i]) {
					print_curr(names, collections, curr_char, curr_count);

					curr_count = 1;
					curr_char = s[i];
				}

				if (i == SIZE - 1) {
					print_curr(names, collections, curr_char, curr_count);
				}

				if (counter == 3 and first_section_printed < 2) {
					counter = 0;
					first_section_printed++;
					if (curr_count != 0) {
						print_curr(names, collections, curr_char, curr_count - 1);

						curr_count = 1;
						curr_char = s[i];
					}
				} else if (counter == 5) {
					counter = 0;
					if (curr_count != 0) {
						print_curr(names, collections, curr_char, curr_count - 1);

						curr_count = 1;
						curr_char = s[i];
					}
				}

				counter++;
			}
		}
	}

	return 0;
}