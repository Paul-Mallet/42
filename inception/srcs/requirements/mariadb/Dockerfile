FROM debian:bookworm

# Installation de MariaDB
RUN apt-get update && apt-get upgrade -y && apt-get install -y \
    mariadb-server \
    && rm -rf /var/lib/apt/lists/*

# Copie du fichier de configuration (pour autoriser les connexions distantes)
COPY conf/50-server.cnf /etc/mysql/mariadb.conf.d/50-server.cnf

# Copie du script d'initialisation
COPY tools/setup_mariadb.sh /usr/local/bin/
RUN chmod +x /usr/local/bin/setup_mariadb.sh

# Le port par défaut de MariaDB
EXPOSE 3306

# On lance le script de setup au démarrage
ENTRYPOINT ["/usr/local/bin/setup_mariadb.sh"]