#include <thread>
#include <functional>
#include <iostream>
#include <condition_variable>

#include <mutex>

class A {
public:
  A() : lock_(nullptr) {
    std::function<void(void)> func = std::bind(&A::release, this);
    std::thread(func).detach();
  }
  void release() {
    while (1) {
      using namespace std::chrono_literals;
      std::cout << "thread running\n";
      std::this_thread::sleep_for(1s);
      std::lock_guard<std::mutex> lk(mutex_);
      if (lock_ != nullptr)
        lock_->cv.notify_one();
    }
  }
  void init_lock() {
    lock_ = new lock;
  }
  struct lock{
    std::condition_variable cv;
  };
  std::mutex mutex_;
  lock *lock_;
};

int main() {
  using namespace std::chrono_literals;
  A a;
  std::this_thread::sleep_for(1s);
  std::cout << "before wait\n";
  a.init_lock();
  std::unique_lock<std::mutex> lk(a.mutex_);
  a.lock_->cv.wait(lk);
  std::cout << "main thread\n";
}