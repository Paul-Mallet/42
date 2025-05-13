Way to solve Philosophers

* 1 philo, 1 fork
* eat, think, sleep, can't do 2 actions in while
* eat -> sleep -> think, stop when 1 philo die
* when start eating, timer reset
* timer continue until eating again, if reach the ttdie, philo die 
* every philo needs to eat & should never die
* philo don't know if another philo is about to die
* 2 structs t_data + t_philo, many vars inside
* odd % 2 = 0(right fork) / even % 2 = 1(left) numbers of philos
* check if not died at every step
* mutex monitor to see all actions of philos

parsing like push_swap
	-> int
	-> no negative value
	-> handle 0 too

nb_philos(also forks = mutexes) ttdie(ms) tteat(ms) ttsleep(ms) nbtimes/philo_eat

threads exec at same time (env 10ms interval)
when fork(mutex) -> duplicate env, syst ressources, global vars...
when thread -> share all ressources, cause n thread / 1 process
share memories -> can modif same vars = race conditions

while philos(n from param)

fsanitize -> detect data race, compile with objs + bin
philo visualizer -> schema of prints return

OS context switch and temp change thread access to data which is shared

1. mutex(fork)
	-> 1rst to be init, to avoid thread attempt to use other uninit mutexes
	-> 1 mutex = 1 fork / philo
	-> 

2. thread
	-> create as many as philos there are, then join them
	-> 1 thread = 1 philo
	-> 

3. race condition
	-> when 2 threads access to same address mem(var)
	-> read / increment / write in Assembler level %eax = cpu register
	-> if time consumming operations(high n iterations...)
	-> need mutex to lock / unlock and avoid this case

4. deadlock
	-> mutex not unlock, process 1 wait for resource 2, process 2 wait for resource 1 etc.

5. lock order inversion
	-> t1 acquires mutex A, tries to acquire mutex B
	-> t2 acquires mutex B, tries to acquire mutex A

### Subject Exemples ###

400 200 200 7-> not enough time to take fork or doing action, so will die
410 200 200 7-> enough time(can minimize ms lost between actions)

start timer when parsing ok, substract timers to check if will be still alive

usleep -> waiter when finish to eat?

loop threads_create() + loop threads_join()

### Race Condition ###



### Methods to avoid Race Condition ###



### Deadlocks Occuring case ###

4 conditions :
- mutual exclusion (no fork can be simultaneously used by multiple philos)
- resource holding (the philos hold 1 fork while waiting for the 2nd)
- non-preemption (no philo can take 1 fork from another)
- circular wait (each philo may be waiting on the philo to their left)

### Many Methods to avoid Deadlocks ###

---
1. Resource Hierarchy (Total Ordering, based on philo's ID, philos always pick up min fork 1rst, which breaks circular wait condition)
---
ex: 
P0 needs forks 0 and 1: Takes fork 0 first, then fork 1
P1 needs forks 1 and 2: Takes fork 1 first, then fork 2 if P0 take both 1rst, will wait
P2 needs forks 2 and 3: Takes fork 2 first, then fork 3
P3 needs forks 3 and 4: Takes fork 3 first, then fork 4 if P2 take both 1rst, will wait
PN-1 needs forks N-1 and 0: Takes fork 0 first, then fork N-1 !!!

2. Mutex + Condition Variables(single mutex to protect state of all forks, condition vars to have philos wait when resources aren't available, wake up waiting philos when forks available)
3. Monitor-based Solution(encapsulate shared states in monitor, provide sync methods for taking and releasing forks, condition vars for waiting)
4. Chandy/Misra Solution(forks assigned to philos, philos comm through message to req forks, clean / dirty fork states determine transfer prio)
5. Atomic Operations(atomic compare-and-swap operations to try to acquire both forks simult, if failed release any acquired forks and try again)
6. Dining Philosophers with a Waiter(semaphore or mutex lock : only allow N-1 philos to try to eat simult)

### Structs Logic based on Deadlocks Resource Hierarchy Method ###

typedef struct s_philo
{
    int             id;                   // Philosopher ID (0 to num_philos-1)
    int             meals_eaten;          // Counter for meals eaten
    long long       last_meal_time;       // Timestamp of last meal(time_to_think, time_to_eat, time_to_sleep?)
    pthread_t       thread;               // Thread ID
    t_data          *data;                // Pointer to shared data
} t_philo;

typedef struct s_data
{
    int             num_philos;
    int             time_to_die;
    int             time_to_eat;
    int             time_to_sleep;
    int             must_eat_count;       // Optional(5th arg): number of times each philosopher must eat
    int             simulation_stop;      // Flag to stop simulation(simulation_is_over())
    long long       start_time;           // Simulation start timestamp
    pthread_mutex_t *forks;               // Array of fork mutexes
    pthread_mutex_t write_mutex;          // For synchronized console output
    pthread_mutex_t meal_mutex;           // For updating meal timestamps safely
} t_data;

### Routines Logic ###

5 steps in routine(infinite loop while)
check after each action if philo deaded with if
kind of method :
1. think(print) ~ not necessary to check? instant action?
2. take 2 available forks in certain order(min - max, lock * 2)
3. eat(print + check if dead)
4. drop 2 available forks in certain order(unlock * 2)
5. sleep(print + check if dead)

### Timestamps for event tracking ###

gettimeofday() -> to get the current time
result in philo->last_meal_time(where set it?, start, mid, end of the loop? outside?)
check all philos in a loop
	time_elapsed = current_time - philos[i].last_meal_time
	if time_elapsed > tt_die, then print death_msg(philos[i] to get philo ID) + end_simulation

### Actions and Monitoring frequencyControl ###

1 usleep() / action(tt_sleep, tt_eat, tt_think) + 1 usleep(check_interval) for the monitoring thread(routine main loop) to check philo deaths
usleep(tt_doing) -> check philo statuses after a given time in ms(user's inputs) pause to avoid consume too many CPU resources
improve fairness if certain philos unable to eat due to bad timing, no need for complex priority

### Load Balancing due to tight(low) timing constraints ###

- risk of philos dying

### Forks Logic ###

case to eat
- if 1 philo = 1 fork = can't eat = die
- avoid deadlocks with Resource Hierarchy Method
- asymmetry to break deadlock -> synchro strat

1rst philo will not necessary takes forks first
concurrent system -> OS decides which thread(philo) runs 1rst
all philo threads compete simultaneously for forks
=> ANY philo could be 1rst
