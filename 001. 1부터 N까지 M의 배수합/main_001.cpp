//▣ 입력설명 첫 줄에 자연수 N과 M이 차례대로 입력됩니다.(3 <= M < N <= 1000)
//▣ 출력설명 첫 줄에 M의 배수합을 출력한다.

#include <iostream>

template <typename T>
auto const result(const T N, const T M) {
    int result = 0;
    for (unsigned i = M; i <= N; i += M) {
        if (i <= N)
            result += i;
        else
            break;
    }
    return result;
}

int main()
{
    using namespace std;
    cout << sizeof(wchar_t) << endl;
    int N, M;
    std::cin >> N >> M;
    std::cout << result(N, M) << std::endl;

    return 0;
}
