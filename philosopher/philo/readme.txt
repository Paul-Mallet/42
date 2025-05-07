Way to solve Philosophers

* 1 philo, 1 fork
* eat, think, sleep, can't do 2 actions in while
* eat -> sleep -> think, stop when 1 philo die
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

p_thread monitor
	-> create + join independantly from philos
	-> access to value
	-> boolean as finished

while philos(n from param)

fsanitize -> detect data race, compile with objs + bin
philo visualizer -> schema of prints return

OS context switch and temp change thread access to data which is shared

1. mutex(fork)
-> 1rst to be init, to avoid thread attempt to use other uninit mutexes
-> 

2. thread
-> 

3. race condition
	-> when 2 threads access to same address mem(var)
	-> read / increment / write in Assembler level %eax = cpu register
	-> if time consumming operations(high n iterations...)

4. deadlock -> mutex not unlock, process 1 wait for resource 2, process 2 wait for resource 1 etc.

5. lock order inversion
-> t1 acquires mutex A, tries to acquire mutex B
-> t2 acquires mutex B, tries to acquire mutex A

odd / even philos = threads
	odd = pair = take right fork 1rst
		ex: 4 philos -> 1(1) | 1(1) | 1(1) | 1(1)
	even = impair = take left fork 1rst
		ex: 5 philos -> 1(1) | 1(1) | 1(1) | 1(1) | 1(1)

1 philo take 1rst fork on left, then right, eat, drop right, so another philo can take this drop one

400 200 200 7-> not enough time to take fork or doing action, so will die
410 200 200 7-> enough time(can minimize ms lost between actions)

start timer when parsing ok, substract timers to check if will be still alive

usleep -> waiter when finish to eat?

loop threads_create() + loop threads_join()

typedef struct s_philo {
    int             	id;            // id philo
    pthread_t       	thread;        // 1 thread = 1 philo
    int             	meals_eaten;   // num of meal eaten
    long            	last_meal_time;// time of last meal
    struct s_program 	*data;     // ref vers data
} t_philo;

typedef struct s_data {
    t_philo         *philos;       // arr philosophes
    pthread_mutex_t *forks;        // arr de forks
    pthread_mutex_t write_lock;    // mutex to print(checker)
    pthread_mutex_t dead_lock;     // mutex to verif dead(checker)
    int             dead_flag;     // fin de simulation
    int             time_to_die;
    int             time_to_eat;
    int             time_to_sleep;
	int				num_meals_to_eat;
} t_data;

5 steps in routine(infinite loop while)
check after each action if philo deaded with if
Penser(print) → Prendre deux fourchettes(lock * 2) → Manger(print) → Rendre les fourchettes(unlock * 2 + ) → Dormir(print)

### Forks taken ordering ###

case to eat
- if 1 philo = 1 fork = peut pas manger?
- avoid deadlocks with odd / even(philo id -> know who's it, start from 0) forks taken in 1rst
	ex: philo 0 -> even = take fork 0, then 1
		philo 1 -> odd = take fork 2, then 1
		philo 2 -> even = take fork 2, then 3...
	take_fork() -> arr of forks[philo->id + 1]
- semaphore alternative = limit num of philos to eat in same time

even -> right 1rst || odd -> left 1rst
fork[0(left), 1(right - left), 2(right - left), 3(right - left)...]
= asymmetry to break deadlock -> synchro strat

1rst philo takes forks
concurrent system -> OS decides which thread(philo) runs 1rst
all philo threads compete simult for forks
=> ANY philo could be 1rst

##############################