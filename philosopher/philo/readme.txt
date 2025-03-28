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

nb_philos(also forks) ttdie(ms) tteat ttsleep nbtimes/philo_eat