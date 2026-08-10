from threading import Barrier, Semaphore

class H2O:
    def __init__(self):
        # Allow up to 2 hydrogen threads and 1 oxygen thread per molecule
        self.h_sem = Semaphore(2)
        self.o_sem = Semaphore(1)
        # Synchronize all 3 threads so they pass the barrier together
        self.barrier = Barrier(3)

    def hydrogen(self, releaseHydrogen: 'Callable[[], None]') -> None:
        self.h_sem.acquire()
        self.barrier.wait()
        
        # releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen()
        
        self.h_sem.release()

    def oxygen(self, releaseOxygen: 'Callable[[], None]') -> None:
        self.o_sem.acquire()
        self.barrier.wait()
        
        # releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen()
        
        self.o_sem.release()
