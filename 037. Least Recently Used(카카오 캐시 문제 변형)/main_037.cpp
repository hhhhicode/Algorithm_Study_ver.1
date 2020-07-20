// Cache miss가 발생하면 모든 작업이 뒤로 밀리고 새로운 작업은 맨 앞에 위치한다.
// Cache hit이 발생하면 해당 작업은 맨 앞에 위치하고 나머지는 뒤로 밀리게 된다.

#include <iostream>
#include <assert.h>
class Cache {
private:
	int* cache;
	int size;
public:
	Cache(const int& S) : size(S), cache(new int[S]()) {
		assert(0 <= S);
	}

	void runProgram(const int& N) {
		for (int i = 0; i < N; i++) {
			int proc;
			std::cin >> proc;
			int searched_proc_index = searchMemory(proc);
			if (searched_proc_index == -1) {
				cacheMiss(proc);
			}
			else {
				cacheHit(searched_proc_index, proc);
			}
		}
	}

	int searchMemory(int proc) {
		for (int i = 0; i < size; i++) {
			if (cache[i] == proc)
				return i;
		}
		return -1;
	}

	void cacheMiss(int& proc) {
		// 하나씩 뒤로 밀고 맨 앞에 넣는다
		for (int i = (size - 1) - 1; 0 <= i; --i) {
			cache[i + 1] = cache[i];
		}
		cache[0] = proc;
	}

	void cacheHit(int & searched_proc_index, int& proc) {
		// index 앞의 proc은 뒤로 밀고 proc을 맨 앞에 넣는다.
		for (int i = searched_proc_index - 1; 0 <= i; --i) {
			cache[i + 1] = cache[i];
		}
		cache[0] = proc;
	}

	void printCache() {
		for (int i = 0; i < size; ++i) {
			std::cout << cache[i] << ' ';
		}
	}
};

int main() {
	using namespace std;

	int S, N;
	cin >> S >> N;

	Cache algo_037(S);
	algo_037.runProgram(N);
	algo_037.printCache();

	return 0;
}