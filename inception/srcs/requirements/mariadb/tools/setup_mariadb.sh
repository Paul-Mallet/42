#!/bin/bash

# On s'assure que le dossier de runtime existe pour le socket
mkdir -p /run/mysqld
chown -R mysql:mysql /run/mysqld

# Si la base de données n'existe pas encore (premier lancement)
if [ ! -d "/var/lib/mysql/$SQL_DATABASE" ]; then

    # Initialisation de la base de données
    mysql_install_db --user=mysql --datadir=/var/lib/mysql

    # On lance MariaDB temporairement pour configurer les users
    # mysqld_safe permet de lancer le daemon en arrière-plan
    mysqld_safe --datadir=/var/lib/mysql &

    # On attend que MariaDB soit prête
    until mysqladmin ping >/dev/null 2>&1; do
        sleep 1
    done

    # Configuration des utilisateurs
    # On utilise les variables du .env ($SQL_DATABASE, $SQL_USER, etc.)
    mysql -e "CREATE DATABASE IF NOT EXISTS \`${SQL_DATABASE}\`;"
    mysql -e "CREATE USER IF NOT EXISTS \`${SQL_USER}\`@'%' IDENTIFIED BY '${SQL_PASSWORD}';"
    mysql -e "GRANT ALL PRIVILEGES ON \`${SQL_DATABASE}\`.* TO \`${SQL_USER}\`@'%';"
    mysql -e "ALTER USER 'root'@'localhost' IDENTIFIED BY '${SQL_ROOT_PASSWORD}';"
    mysql -e "FLUSH PRIVILEGES;"

    # On éteint l'instance temporaire
    mysqladmin -u root -p${SQL_ROOT_PASSWORD} shutdown
fi

# On relance MariaDB au premier plan (daemon off) pour que le container reste actif
exec mysqld_safe --datadir=/var/lib/mysql