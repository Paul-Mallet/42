# Born2BeRoot - Project_03

## 📝 Overview
**Born2beRoot** is a System Administration project that involves setting up a secure server using **VirtualBox** and **Debian**. The goal is to implement strict security rules, manage partitions with **LVM**, configure a **Sudo** policy, and create a monitoring script using **daemons** in bakground.

This project is a deep dive into how an operating system works "under the hood" and how to secure a network environment. Because many tools and packages may have been chose for this project, I've explained why I preferred each one in the Design Choices & Comparisons section below.

---

## 🛠️ Installation & Setup

### 🧰 Prerequisites
* Download the [**Debian ISO**](https://www.debian.org/distrib/) (Netinst version recommended for a lightweight CLI).
* Install [**VirtualBox**](https://www.virtualbox.org/wiki/Downloads).

## ⚙️ System Specifications

You will need to create a new VM, by click on the top-center blue button once VirtualBox is launched.

### Virtual Machine Name & Operating System
* **Name:** what-you-want
* **Folder:** where your VM will be saved (care it can take many space in your disk !)
* **ISO Image:** Debian ISO you've just installed
* **Edition:** don't touch it
* **Type:** Linux
* **Version:** Debian 12 Bookworm (64-bit)

### Hardware
* **Base Memory:** don't touch it (2048 MB)
* **Processors:** depending on how many you have, I recommend 2

### Virtual Hard Disk
* **Create a Virtual Hard Disk Now**
* **Disk Size:** 20 GB (as I've done Bonus Part, we'll need to install WordPress on it)

### Summary

Check that Pre-allocate Full Size at the bottom is : false,
then click on finish.

### Settings

Storage -> Controller: IDE <empty> -> Attributes -> Click on the small blue disk icon -> Naviguate to your location of the ISO file on your computer and select it.

After choosing Debian ISO image that we dowloaded in the beginning, you should have the debian-XX.X.X-amd64-netinst.iso (XX depends on your current version) path visible on hover of your Controller IDE.

You can now start the VM ! And if you want to learn more about how to setup it, I recommand you this guide : [Vikingu-del - Born2BeRoot Guide](https://github.com/Vikingu-del/Born2beRoot?tab=readme-ov-file)

---

## 🏗️ Design Choices & Comparisons

This section explains the technical decisions made during the server setup and provides a comparison between the available technologies as required by the subject.

### 🐧 Choice of Operating System: Debian
For this project, I chose **Debian 12** over Rocky Linux.

**Pros of Debian:**
* **Stability:** Known for its rigorous testing and "stable" releases.
* **Apt Package Manager:** Extremely user-friendly and features a massive repository of software.
* **Lightweight:** The "Netinst" version allows for a minimal installation, perfect for a secure server.
* **Documentation:** Extensive community support and documentation, which is ideal for learning system administration.

**Cons of Debian:**
* **Dated Packages:** To maintain stability, software versions in the stable branch are often older than those in other distributions.

---

### 🔍 Technical Comparisons

#### 1. Debian vs. Rocky Linux
| Feature | Debian | Rocky Linux |
| :--- | :--- | :--- |
| **Origin** | Independent/Community-led | Successor to CentOS (Red Hat downstream) |
| **Manager** | `apt` (.deb) | `dnf/yum` (.rpm) |
| **Philosophy** | Universal OS, focuses on Free Software | Enterprise-grade, binary compatible with RHEL |
| **Learning Curve** | Generally perceived as more accessible | More complex (Enterprise standards) |

#### 2. AppArmor vs. SELinux (Mandatory Access Control)
I used **AppArmor** (default on Debian).
* **AppArmor:** Focuses on paths and is profile-based. It is much easier to configure for beginners as it uses simple text files to define what a program can access.
* **SELinux:** Focuses on labels and roles. It is significantly more powerful and granular but has a very steep learning curve and complex policy management.

#### 3. UFW vs. Firewalld (Firewalls)
I used **UFW** (Uncomplicated Firewall).
* **UFW:** Designed to be simple and easy to use via CLI. Perfect for managing basic port rules (like 4242, 80, 443).
* **Firewalld:** More advanced, uses "zones" and "services". It is more flexible for complex network environments but overkill for a single-server setup like this.

#### 4. VirtualBox vs. UTM (Virtualization)
I used **VirtualBox**.
* **VirtualBox:** A cross-platform hypervisor (Windows, Linux, Intel Mac). It offers a robust GUI and highly compatible virtual hardware drivers (Guest Additions).
* **UTM:** Based on QEMU, primarily used on Apple Silicon (M1/M2/M3) Macs. It is faster on ARM architecture but lacks some of the legacy features and ease of use found in VirtualBox for X86 systems.

---

### 🛠️ Main Design Choices

#### 📦 Partitioning (LVM & LUKS)
I implemented **LVM (Logical Volume Manager)** inside an **encrypted LUKS partition**.
* **Why?** LVM allows for dynamic resizing of partitions without reformatting the disk. Chosing a multi-partition scheme (`/home`, `/var`, `/tmp`, etc.) prevents a single partition from filling up and crashing the entire system (security through isolation).

#### 🛡️ Security Policies
* **Sudo:** Strict logging of all commands and a limited number of password attempts to prevent brute-force attacks.
* **Password Policy:** Enforced complexity and mandatory rotation every 30 days to ensure user account integrity.
* **SSH:** Restricted to port 4242 and disabled root login to minimize the attack surface.

#### 👥 User Management
* Creation of a specific user (`pamallet42`) and a group (`user42`).
* The root user is strictly separated from the administrative user.

#### 🌐 Services Installed (Bonus Included)
* **SSH:** For secure remote management.
* **MariaDB:** SQL Database for WordPress.
* **Lighttpd/Nginx:** High-performance web server.
* **vsftpd:** Secure FTP access for file management.
* **WordPress:** CMS to demonstrate a functional web stack.