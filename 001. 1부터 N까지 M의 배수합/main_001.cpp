//�� �Է¼��� ù �ٿ� �ڿ��� N�� M�� ���ʴ�� �Էµ˴ϴ�.(3 <= M < N <= 1000)
//�� ��¼��� ù �ٿ� M�� ������� ����Ѵ�.

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
