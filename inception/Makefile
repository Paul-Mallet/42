DOCKER_COMPOSE = docker compose -f srcs/docker-compose.yml
DATA_PATH = /home/pamallet/data

all: setup
	$(DOCKER_COMPOSE) up --build -d

setup:
	@sudo mkdir -p $(DATA_PATH)/mariadb
	@sudo mkdir -p $(DATA_PATH)/wordpress
	@sudo chmod -R 777 $(DATA_PATH)

down:
	$(DOCKER_COMPOSE) down

clean: down
	@docker system prune -a

fclean: clean
	@sudo rm -rf $(DATA_PATH)
	@docker volume rm $$(docker volume ls -q)

re: fclean all

.PHONY: all setup down clean fclean re