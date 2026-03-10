# 👽 Inception

## 📝 Description

**Inception** is a System Administration project that aims to broaden our knowledge of virtualization and containerization using **Docker**. The goal is to set up a small infrastructure of different services under specific rules.

The project involves creating a multi-container architecture where each service (Nginx, MariaDB, and WordPress) runs in its own dedicated container. All services must be built from a **Debian Bullseye/Buster** base image and orchestrated using **Docker Compose**.

### Key Features
* **Nginx**: The only entry point for the infrastructure, configured with TLS (port 443).
* **WordPress + php-fpm**: The content management system.
* **MariaDB**: The database for WordPress.
* **Volumes**: Persistent storage for the database and website files.
* **Network**: A private virtual network for secure inter-container communication.

---

## 🚀 Instructions

### Prerequisites
* **Virtual Box** installed.
* A Linux-based system (Debian is recommended for the host VM).
* 2GB RAM, 2 vcores, 5GB(depends on Mariadb/WordPress size) storage, 
* **sudo**, **git**, **vim**, **make** as VM basic packages.
* **Docker** & **Docker compose** installed via the [debian repo installation](https://docs.docker.com/engine/install/debian/#install-using-the-repository).

### Installation & Execution

1.  **Clone the repository:**
    ```bash
    git clone [https://github.com/Paul-Mallet/inception.git](https://github.com/Paul-Mallet/inception.git) && cd inception
    ```

2.  **Setup Environment Variables:**
    Create a `.env` file in the `srcs/` directory with the following variables:
    ```env
    # ------------------------------------------------------------------------------
    # CONFIGURATION MARIADB (Base de données)
    # ------------------------------------------------------------------------------
    SQL_DATABASE=inception_db
    SQL_USER=[your_intra_login]
    SQL_PASSWORD=[...]
    SQL_ROOT_PASSWORD=[...]
    
    # ------------------------------------------------------------------------------
    # CONFIGURATION WORDPRESS
    # ------------------------------------------------------------------------------
    DOMAIN_NAME=pamallet.42.fr
    
    # Administrateur (Interdiction d'utiliser 'admin' ou 'administrator' !)
    WP_ADMIN_USER=[...]
    WP_ADMIN_PASSWORD=[...]
    WP_ADMIN_EMAIL=[...]
    
    # Utilisateur standard (Obligatoire pour le sujet)
    WP_USER=[...]
    WP_USER_PASSWORD=[...]
    WP_USER_EMAIL=[...]
    ```

3.  **Update your Hosts file:**
    To access the site via the domain name, add this line to the bottom of your `/etc/hosts` (Linux/Mac) or `C:\Windows\System32\drivers\etc\hosts` (Windows) file:
    ```text
    127.0.0.1 [your_intra_login].42.fr
    ```

4.  **Run the project:**
    ```bash
    make
    ```
    *This will create the necessary data directories, build the images, and start the containers in detached mode.*

### Useful Commands
* `make down`: Stops the containers.
* `make clean`: Stops containers and removes images/networks.
* `make fclean`: Full cleanup, including volumes (data deletion).
* `make re`: Force a full rebuild.

---

## 🏗️ Project Design & Technical Choices

This project relies on **Docker Compose** to orchestrate the infrastructure. Each service has its own `Dockerfile` to ensure custom configuration and security (no pre-made images from DockerHub are allowed).

### Comparison & Analysis

| Concept | Comparison |
| :--- | :--- |
| **VM vs Docker** | A **VM** virtualizes hardware (including a full Kernel), making it heavy and slow. **Docker** virtualizes the OS, sharing the host Kernel, making it lightweight, fast, and portable. |
| **Secrets vs Env Variables** | **Env Variables** are easy to use but can be leaked via logs or `docker inspect`. **Secrets** (Docker Secrets) are encrypted at rest and only mounted in-memory in the container, providing much higher security. |
| **Docker Network vs Host** | **Host Network** removes isolation between the container and the host. **Docker Network** (Bridge) creates an isolated private tunnel, allowing containers to talk to each other without exposing all ports to the outside world. |
| **Docker Volumes vs Bind Mounts** | **Bind Mounts** depend on the host's directory structure (sensitive to paths). **Docker Volumes** are managed by Docker itself, offering better performance and decoupling from the host's OS. |

---

## 📚 Resources

### Documentation & Articles
* [Usefull Blog about Containerization](https://blog.stephane-robert.info/docs/conteneurisation/)
* [Official Docker Documentation](https://docs.docker.com/)
* [Docker Compose Specification](https://docs.docker.com/compose/)
* [Nginx Configuration Guide](https://nginx.org/en/docs/)
* [WordPress CLI (wp-cli) Documentation](https://make.wordpress.org/cli/handbook/guides/installing/)

### AI Usage Disclosure
Artificial Intelligence (specifically Gemini/LLM) was used for the following tasks:
* **Troubleshooting**: Resolving permission issues with `docker.sock` and Linux group management.
* **Scripting**: Generating initial templates for the `Makefile` and `docker-compose.yml`.
* **Learning**: Explaining the concepts of VM, basic setup and Port Forwarding with NAT within a VirtualBox environment.
* **Documentation**: Assisting in the drafting of this README.md to ensure compliance with the subject requirements.
