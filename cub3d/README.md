# Pêch'App - Real World Project_00

## 📝 Overview

The **pech-app** project is the result of a collaboration between students from 42 and **ESPMer** Le Havre (a group of 10+ students finalizing their maritime studies). The goal was to bridge the gap between complex legal texts and recreational fishers through a modern mobile interface.

This project focuses on providing a seamless **UI/UX** experience for users on-the-go, ensuring that critical information regarding protected areas is accessible in just a few taps. We chose **Figma** to achieve it.

Developed with **React Native** and **Expo**, the application serves as a digital guide through species from the Mediterranean Sea, centralizing regional regulations, biological fish sheets, and localized fishing restrictions using **Google Map API**. By providing clear, real-time information, the app helps preserve marine biodiversity while ensuring fishers stay compliant with the latest laws.

Because of the data restriction instaured by ESPMer and my job as a UI/UX designer and Frontend Developer during the project, I've decided to only share the **Frontend part** of it.

## 🔍 Regulation & Biodiversity

The application integrates real-world legal data provided by maritime authorities (ESPMer - Le Havre). It currently features:

1. **Species Database**: Over **20 different species** recorded with detailed descriptions, size limits, and biological data.
2. **Porquerolles Regulations**: Management of 9 specific fishing zones (A to R), including seasonal closures and strict "No-Take" zones (F, H, R).
3. **Marine Reserves**: Specific logic for the Cerbère-Banyuls Natural Reserve, handling the 10-catch daily limit and sunrise/sunset fishing windows.

---

## 🎨 UI/UX Design & Features
A complete Figma mockup was realized to define a clean and accessible interface. The following core features were implemented:

### Global Navigation

* Unified Searchbar:
   * Dynamic filtering of the legislation page.
   * Interactive History: Quick access to recent fish searches, categories, and fishing methods.
   * Direct Link: Bridge between fish sheets and their corresponding legal status via a "Legislation" button.

### App Navigation

* /home: Features a horizontal scroll bar displaying the **latest ESPMer legislation updates** and a history of recently viewed fish and laws.

* /fishes: A 2-column grid layout displaying 20 detailed fish cards in a smooth scroll container.

* /legislations: A vertical list of large-format legislation cards for easy reading in the field.

* /settings:
   * **Visual Themes**: Radio buttons with live previews of the interface.
   * **Accessibility**: Choice between standard Poppins font and a specialized Dyslexic-friendly font.

###  Accessibility & Settings

The project places a high priority on inclusivity. Within the /settings page, users can toggle:
* **Dark/Light Mode**: Optimized for high-glare environments (sunny beaches).
* **OpenDyslexic Font**: To assist users with reading difficulties in deciphering complex legal texts.

## 📥 Installation

Ensure you have nvm (Node Version Manager) installed to manage the environment easily.

1. Clone the repository:

```bash
   git clone https://github.com/votre-user/pech-app-mobile.git
   cd pech-app-mobile
```

2. Setup Node.js Environment:

```bash
   nvm install 23.3.0
   nvm use 23.3.0
```

3. Install Dependencies:

```bash
   npm install
```

## 🚀 Usage & Execution

**Important** : As this is an Internal and Private scoped project, I only show screenshots in this readme as examples.

Here was the workflow to build and execute the project :

1. Launching the Backend Server on a remote host (Scalingo, Heroku, Nginx...)

2. Launching the Frontend Server

To start the Expo Metro Bundler:

```bash
   npm run start
```

3. Testing on Physical Devices
To see the UI/UX in action with real-time updates:

* Download the Expo Go app on your phone (iOS/Android).
* Ensure your phone and computer are on the same Wi-Fi network.
* Scan the QR Code displayed in your terminal (after running the frontend service).