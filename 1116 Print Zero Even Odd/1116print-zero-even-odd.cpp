#include <functional>
#include <mutex>
#include <condition_variable>

using namespace std;

class ZeroEvenOdd {
private:
    int n;
    int curr;
    int state; // 0: zero's turn, 1: odd's turn, 2: even's turn
    mutex mtx;
    condition_variable cv;

public:
    ZeroEvenOdd(int n) {
        this->n = n;
        this->curr = 1;
        this->state = 0; // Start with 'zero' thread
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        for (int i = 0; i < n; ++i) {
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, [this]() { return state == 0; });

            printNumber(0);

            if (curr % 2 == 1) {
                state = 1; // Signal odd thread
            } else {
                state = 2; // Signal even thread
            }
            cv.notify_all();
        }
    }

    void even(function<void(int)> printNumber) {
        for (int i = 2; i <= n; i += 2) {
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, [this]() { return state == 2; });

            printNumber(curr);
            curr++;

            state = 0; // Signal zero thread
            cv.notify_all();
        }
    }

    void odd(function<void(int)> printNumber) {
        for (int i = 1; i <= n; i += 2) {
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, [this]() { return state == 1; });

            printNumber(curr);
            curr++;

            state = 0; // Signal zero thread
            cv.notify_all();
        }
    }
};
