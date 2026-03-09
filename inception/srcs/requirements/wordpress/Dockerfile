FROM debian:bookworm

RUN apt update && apt install -y \
    php8.2-fpm \
    php8.2-mysql \
    curl \
    mariadb-client

# On copie notre configuration personnalisée
COPY conf/www.conf /etc/php/8.2/fpm/pool.d/www.conf

# Installation de WP-CLI (l'outil indispensable pour automatiser l'install de WP)
RUN curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar \
    && chmod +x wp-cli.phar \
    && mv wp-cli.phar /usr/local/bin/wp

COPY tools/setup_wordpress.sh /usr/local/bin/
RUN chmod +x /usr/local/bin/setup_wordpress.sh

WORKDIR /var/www/wordpress

# Documentation du port FastCGI
EXPOSE 9000

ENTRYPOINT ["/usr/local/bin/setup_wordpress.sh"]