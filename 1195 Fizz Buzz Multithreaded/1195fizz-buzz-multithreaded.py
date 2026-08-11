import threading

class FizzBuzz:
    def __init__(self, n: int):
        self.n = n
        self.current = 1
        
        # Initialize locks for each state
        self.fizz_lock = threading.Lock()
        self.buzz_lock = threading.Lock()
        self.fizzbuzz_lock = threading.Lock()
        self.num_lock = threading.Lock()
        
        # Acquire all specialized locks initially so they block
        self.fizz_lock.acquire()
        self.buzz_lock.acquire()
        self.fizzbuzz_lock.acquire()
        # The number lock remains released because 1 is a number

    # printFizz() outputs "fizz"
    def fizz(self, printFizz: 'Callable[[], None]') -> None:
        while True:
            self.fizz_lock.acquire()
            if self.current > self.n:
                break
            printFizz()
            self.current += 1
            self._release_next_lock()

    # printBuzz() outputs "buzz"
    def buzz(self, printBuzz: 'Callable[[], None]') -> None:
        while True:
            self.buzz_lock.acquire()
            if self.current > self.n:
                break
            printBuzz()
            self.current += 1
            self._release_next_lock()

    # printFizzBuzz() outputs "fizzbuzz"
    def fizzbuzz(self, printFizzBuzz: 'Callable[[], None]') -> None:
        while True:
            self.fizzbuzz_lock.acquire()
            if self.current > self.n:
                break
            printFizzBuzz()
            self.current += 1
            self._release_next_lock()

    # printNumber(x) outputs "x", where x is an integer.
    def number(self, printNumber: 'Callable[[int], None]') -> None:
        while True:
            self.num_lock.acquire()
            if self.current > self.n:
                break
            printNumber(self.current)
            self.current += 1
            self._release_next_lock()

    def _release_next_lock(self) -> None:
        """Helper to determine which thread should execute next or release all to terminate."""
        if self.current > self.n:
            # Release all locks so stuck threads can exit their while loops
            if self.fizz_lock.locked(): self.fizz_lock.release()
            if self.buzz_lock.locked(): self.buzz_lock.release()
            if self.fizzbuzz_lock.locked(): self.fizzbuzz_lock.release()
            if self.num_lock.locked(): self.num_lock.release()
            return

        # Check conditions for the next number in sequence
        if self.current % 3 == 0 and self.current % 5 == 0:
            self.fizzbuzz_lock.release()
        elif self.current % 3 == 0:
            self.fizz_lock.release()
        elif self.current % 5 == 0:
            self.buzz_lock.release()
        else:
            self.num_lock.release()
