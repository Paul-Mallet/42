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

nb_philos(also forks) ttdie(ms) tteat(ms) ttsleep(ms) nbtimes/philo_eat

threads exec at same time (env 10ms interval)
when fork -> duplicate env, syst ressources, global vars...
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

1. thread -> 

2. race condition
	-> when 2 threads access to same address mem(var)
	-> read / increment / write in Assembler level %eax = cpu register
	-> if time consumming operations(high n iterations...)
3. mutex -> 

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

400 200 200 -> not enough time to take fork or doing action, so will die
410 200 200 -> enough time(can minimize ms lost between actions)

start timer when parsing ok, substract timers to check if will be still alive

usleep -> waiter