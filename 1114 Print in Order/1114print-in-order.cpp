#include <mutex>
#include <condition_variable>

class Foo {
private:
    mutex mtx;
    condition_variable cv;
    int step;

public:
    Foo() {
        step = 1;
    }

    void first(function<void()> printFirst) {
        unique_lock<mutex> lock(mtx);

        // print "first"
        printFirst();

        step = 2;
        cv.notify_all();
    }

    void second(function<void()> printSecond) {
        unique_lock<mutex> lock(mtx);

        cv.wait(lock, [this] { return step == 2; });

        // print "second"
        printSecond();

        step = 3;
        cv.notify_all();
    }

    void third(function<void()> printThird) {
        unique_lock<mutex> lock(mtx);

        cv.wait(lock, [this] { return step == 3; });

        // print "third"
        printThird();
    }
};