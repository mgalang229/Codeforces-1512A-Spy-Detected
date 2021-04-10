#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		vector<int> a(n);
		int size = INT_MIN;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			size = max(size, a[i]);
		}
		// create a 'counter' vector to count the number of occurrences
		// of the elements in vector 'a'
		vector<int> counter(size + 1, 0);
		for (int i = 0; i < n; i++) {
			counter[a[i]]++;
		}
		// find the element in vector 'a' that has the highest number of
		// occurrence, and knowing that, we will be able to find the different element
		int majority = INT_MIN;
		for (int i = 0; i < (int) counter.size(); i++) {
			majority = max(majority, counter[i]);
		}
		int num = 0;
		for (int i = 0; i < (int) counter.size(); i++) {
			if (counter[i] != 0 && counter[i] != majority) {
				// if the occurrence of an element is not equal to 0
				// and also not equal to the majority, then store the
				// element in the 'num' variable, this is the element
				// that is different from the rest
				num = i;
				break;
			}
		}
		int index = -1;
		for (int i = 0; i < n; i++) {
			if (a[i] == num) {
				// if the current element in vector 'a', matches the
				// value of 'num', then print the index plus 1
				// also, don't forget to break the loop
				index = i + 1;
				break;
			}
		}
		cout << index << '\n';
	}
	return 0;
}
