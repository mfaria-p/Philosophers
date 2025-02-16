# Philosophers

## Overview

The **Dining Philosophers Problem** is a classic concurrency problem introduced by Edsger Dijkstra in 1965. It illustrates the challenges of resource sharing and synchronization in a multi-threaded environment. The problem models a scenario where a group of philosophers sit at a round table, each needing two forks to eat but sharing them with their neighbors. If not properly synchronized, this can lead to deadlocks and starvation, making it an excellent case study in concurrent programming.

With this project, I needed to provide a thread-safe simulation of the problem using **POSIX threads (pthreads)** and **mutex locks**, ensuring that all philosophers get a fair chance to eat while avoiding synchronization pitfalls.

## The Dining Philosophers Problem

A group of `X` philosophers sits around a circular table, with `X` forks placed between them. Each philosopher cycles between three states:

1. **Thinking** - The philosopher is not interacting with the forks.
2. **Eating** - The philosopher must acquire both the left and right forks to eat.
3. **Sleeping** - After eating, the philosopher rests before returning to thinking.

### Rules:

- A fork can only be used by one philosopher at a time.
- A philosopher can eat only if they acquire both adjacent forks.
- Forks must be released after eating.
- Improper synchronization can lead to deadlocks (where philosophers wait indefinitely for forks) or starvation (where some philosophers never get to eat).

This project implements **mutex-based synchronization** to prevent such issues, ensuring efficient and fair resource allocation.

## Key Concepts

- **Multithreading:** Uses POSIX threads (pthreads) to create and manage multiple philosophers.
- **Synchronization:** Implements mutex locks to prevent race conditions.
- **Deadlock Prevention:** Ensures philosophers don’t get stuck waiting for forks indefinitely.
- **Thread Safety:** Properly manages shared resources between threads.

## Project Structure

```
philosophers/
├── inc/
│   ├── philo.h            # Header file containing structures and function prototypes
├── srcs/
│   ├── init_all.c         # Functions to initialize the program, philosophers, and forks
│   ├── monitor_routine.c  # Functions to monitor the state of philosophers
│   ├── philo_routine.c    # Functions defining the routine of each philosopher
│   ├── threads.c          # Functions to create and manage threads
│   ├── time.c             # Utility functions for time management
│   ├── utils.c            # Miscellaneous utility functions
├── main.c                 # Entry point of the program, handling argument validation and initialization
├── Makefile               # Build script to compile the project
```

## Compilation

To build the project, run:

```sh
make
```

To clean the build files, run:

```sh
make clean
```

To remove the executable, run:

```sh
make fclean
```

To rebuild the project, run:

```sh
make re
```

## Execution

Run the program with the following command:

```sh
./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [number_of_times_each_philosopher_must_eat]
```

### Parameters:

- `<number_of_philosophers>`: The number of philosophers and forks.
- `<time_to_die>`: Time in milliseconds before a philosopher dies if they don’t start eating.
- `<time_to_eat>`: Time in milliseconds it takes for a philosopher to eat.
- `<time_to_sleep>`: Time in milliseconds a philosopher spends sleeping.
- `[number_of_times_each_philosopher_must_eat]` (optional): Specifies how many times each philosopher must eat before the simulation ends.

### Example:

```sh
./philo 5 800 200 200
```

This starts the simulation with 5 philosophers, where:

- Each has 800 milliseconds to start eating before dying.
- Eating takes 200 milliseconds.
- Sleeping takes 200 milliseconds.

## Conclusion

This project provides hands-on experience with concurrent programming, emphasizing the importance of thread synchronization and deadlock prevention. By simulating the Dining Philosophers problem, I gained a deeper understanding of multithreading and multiprocessing concepts.

