#!/bin/bash

# Attendre un peu que MariaDB soit prête
sleep 10

if [ ! -f /var/www/wordpress/wp-config.php ]; then
    # Téléchargement de WordPress
    wp core download --allow-root

    # Création du fichier wp-config.php
    wp config create --allow-root \
        --dbname=$SQL_DATABASE \
        --dbuser=$SQL_USER \
        --dbpass=$SQL_PASSWORD \
        --dbhost=mariadb:3306

    # Installation de WordPress
    wp core install --allow-root \
        --url=$DOMAIN_NAME \
        --title="Inception" \
        --admin_user=$WP_ADMIN_USER \
        --admin_password=$WP_ADMIN_PASSWORD \
        --admin_email="admin@42.fr"

    # Création d'un utilisateur secondaire (obligatoire dans le sujet)
    wp user create --allow-root $WP_USER "user@42.fr" \
        --user_pass=$WP_USER_PASSWORD \
        --role=author
fi

# Création du dossier pour PHP-FPM et lancement
mkdir -p /run/php
exec php-fpm8.2 -F