#include <iostream>
using namespace std;

int main() {
    int score = 200;
    int *ptr_score = &score;

    printf("1. value of score is %d\n",score);
    printf("2. value of pointer is %p\n",ptr_score);

    int &another_score = score;
    another_score = 800;

    printf("3. value of score is %d\n",another_score);
    printf("4. value of score is %d\n",score);
    //another_score is a reference to score. This means another_score is not a separate variable; it's just another name for score.
    std::cout << &score << " and " << &another_score;
    std::cout << " even the address of both score and another_score is same";
    return 0;
}