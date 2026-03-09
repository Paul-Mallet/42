#!/bin/sh

# On s'assure que les dossiers existent
mkdir -p /etc/nginx/ssl

# Génération du certificat si il n'existe pas déjà
if [ ! -f /etc/nginx/ssl/inception.crt ]; then
    openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
    -keyout /etc/nginx/ssl/inception.key \
    -out /etc/nginx/ssl/inception.crt \
    -subj "/C=FR/ST=IDF/L=Paris/O=42/OU=42/CN=pamallet.42.fr/UID=pamallet"
fi

# Lance Nginx au premier plan
echo "Nginx starting..."
exec nginx -g "daemon off;"