import threading

class DiningPhilosophers:
    def __init__(self):
        # A lock for each of the 5 forks
        self.fork_locks = [threading.Lock() for _ in range(5)]
        # A semaphore to limit the number of concurrent diners to 4
        self.limit_diners = threading.Semaphore(4)

    # call the functions directly to execute, for example, eat()
    def wantsToEat(self,
                   philosopher: int,
                   pickLeftFork: 'Callable[[], None]',
                   pickRightFork: 'Callable[[], None]',
                   eat: 'Callable[[], None]',
                   putLeftFork: 'Callable[[], None]',
                   putRightFork: 'Callable[[], None]') -> None:
        
        # Calculate fork IDs based on philosopher ID
        left_fork_id = philosopher
        right_fork_id = (philosopher + 1) % 5
        
        # Acquire the semaphore to ensure at most 4 philosophers try to eat
        with self.limit_diners:
            # Safely acquire both forks
            with self.fork_locks[left_fork_id]:
                with self.fork_locks[right_fork_id]:
                    # Execute actions
                    pickLeftFork()
                    pickRightFork()
                    eat()
                    putLeftFork()
                    putRightFork()
