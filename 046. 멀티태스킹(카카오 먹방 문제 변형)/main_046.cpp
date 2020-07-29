#include <iostream>
#include <vector>

class Task {
private:
	std::vector<int> task_list;
	int N;

public:
	Task() {};
	Task(const int& N) {
		this->N = N;
		task_list.resize(N);
		for (auto& t : task_list) {
			std::cin >> t;
		}
		
	}
	int getN() {
		return N;
	}
	const std::vector<int> getTaskList() const{
		return task_list;
	}
	std::vector<int>& setTaskList() {
		return task_list;
	}
};

class Work {
private:
	Task task;
	int K;

public:
	Work(Task& task, int K) {
		this->task = task;
		this->K = K;
	}
	void printTask() {
		for (const auto& t : task.getTaskList()) {
			std::cout << t << ' ';
		}
		std::cout << std::endl;
	}

	void taskWorking() {
		int off = K;
		int idx = -1;
		while (true) {
			// 0 <= idx <= N-1
			idx++;
			if (idx == task.getN()) {
				idx = 0;
			}
			if (task.getTaskList()[idx] == 0) {
				if (checkTaskZero()) {
					std::cout << -1;
					return;
				}
				continue;
			}
			else {
				if (off == 0) {
					std::cout << idx + 1;
					return;
				}
				task.setTaskList()[idx]--;
				off--;
			}

		}
	}
	bool checkTaskZero() {
		for (int i = 0; i < task.getTaskList().size(); i++) {
			if (task.getTaskList()[i] != 0)
				return false;
		}
		return true;
	}
};

int main() {
	using namespace std;
	//FILE* stream;	freopen_s(&stream, "input.txt", "rt", stdin);

	int N, K;

	cin >> N;
	Task t(N);

	cin >> K;
	Work(t, K).taskWorking();

	return 0;
}