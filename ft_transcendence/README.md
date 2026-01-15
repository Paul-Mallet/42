# ft_transcendence - Final_Project

## 📝 Overview

**ft_transcendence** is the final project of the 42 common core. The goal is to build a high-end, single-page web application (SPA) that allows users to play Pong and Billiards games in real-time.

This project is a massive integration of diverse skills: **Full-stack development** with a microservices architecture, **Cybersecurity** (WAF, Vault, 2FA), **Game Development** (3D with Babylon.js, AI), and **DevOps** (Docker, Nginx). It provides a complete user experience with tournament system, AI opponent, and advanced statistics.

## 🎨 Visual Identity

We decided to break away from standard minimalist designs and adopted a **Rick and Morty multiversal theme**. This choice influenced every part of the user experience:

<p align="center">
  <img src="https://static.thcdn.com/images/v2/wp-content/uploads/sites/499/2018/09/24160403/rick-and-morty.jpeg?width=700"
 width="800" alt="Rick and Morty Portal Aesthetic">
</p>

Visuals:

The color palette uses the iconic "Portal Green" and "Council of Ricks Blue" to only mentionned those references.

* **Warning Red** : #B23521;  ![ ](https://img.shields.io/badge/-B23521?style=flat-square&color=B23521)
* **Infos Yellow** : #F3F58F;  ![ ](https://img.shields.io/badge/-F3F58F?style=flat-square&color=F3F58F)
* **Hologram Green** : #80FF00;  ![ ](https://img.shields.io/badge/-80FF00?style=flat-square&color=80FF00)
* **Computer Blue Light** : #00FFF7;  ![ ](https://img.shields.io/badge/-00FFF7?style=flat-square&color=00FFF7)
* **Hologram Blue** : #007AFF;  ![ ](https://img.shields.io/badge/-007AFF?style=flat-square&color=007AFF)

Immersive Elements:

* The Loading screens feature portal animations.
* The AI Opponent is represented as a "Meeseeks," programmed to help you practice... or not.
* User Avatars and default profiles are based on various characters from the Citadel of Ricks.

## 🛠 Technical Stack

* **Frontend** : Vite, HTML5, CSS3, TypeScript, React
* **Backend** : Node.js, Fastify (Microservices architecture)
* **Real-time** : WebSockets
* **3D Graphics** : Babylon.js (Particle rendering techniques)
* **Godot Engine** : Used for the second game (Billiards), exported to WebAssembly (WASM) and WebGL
* **Database** : SQLite3 (Chosen for portability and its "serverless" file-based nature, ideal for containerized microservices)
* **Security** : HashiCorp Vault (Secrets management), Nginx (Reverse Proxy), WAF/ModSecurity, CORS, argon2
* **Infrastructure** : Docker & Docker Compose

## 📥 Instructions (Installation)

### Prerequisites

1. Docker and Docker Compose installed
2. A Google Cloud Console account (for OAuth 2.0 credentials)
3. An .env file at the root (*see .env.example)

### Step-by-Step Run

1. Clone the project:

```bash
   git clone https://github.com/Paul-Mallet/42.git
   cd ft_transcendence
```

2. Setup Secrets: Configure your environment variables in the .env file (API keys, Vault tokens).

3. Build and Launch:

```bash
   docker-compose up --build
```

4. Access the app: Open https://localhost (Nginx handles the HTTPS/WAF layer).

## 👥 Team Information & Contributions

<table data-path-to-node="16"><thead><tr><td><span data-path-to-node="16,0,0,0">Member</span></td><td><span data-path-to-node="16,0,1,0">Role</span></td><td><span data-path-to-node="16,0,2,0">Responsibilities</span></td></tr></thead><tbody><tr><td><span data-path-to-node="16,1,0,0"><b data-path-to-node="16,1,0,0" data-index-in-node="0">ttaquet</b></span></td><td><span data-path-to-node="16,1,1,0">Tech Lead / DevOps</span></td><td><span data-path-to-node="16,1,2,0">Microservices, Docker, Vault, WAF.</span></td></tr><tr><td><span data-path-to-node="16,2,0,0"><b data-path-to-node="16,2,0,0" data-index-in-node="0">(me)</b></span></td><td><span data-path-to-node="16,2,1,0">Lead Frontend</span></td><td><span data-path-to-node="16,2,2,0">React architecture, i18n, Accessibility.</span></td></tr><tr><td><span data-path-to-node="16,3,0,0"><b data-path-to-node="16,3,0,0" data-index-in-node="0">bchedru, agilles & nvadenne</b></span></td><td><span data-path-to-node="16,3,1,0">Games Developer</span></td><td><span data-path-to-node="16,3,2,0">Babylon.js, AI Opponent, Pong logic.</span></td></tr><tr><td><span data-path-to-node="16,4,0,0"><b data-path-to-node="16,4,0,0" data-index-in-node="0">ttaquet & (me)</b></span></td><td><span data-path-to-node="16,4,1,0">Lead Backend</span></td><td><span data-path-to-node="16,4,2,0">OAuth, 2FA, Tournament system, Microservices, SQLite.</span></td></tr></tbody></table>

## 🗂 Project Management

* **Work Distribution** : Tasks were divided into "feature-owner" modules. Each member was responsible for the implementation (Frontend + Backend) of their assigned module. Few times by also implementing end-to-end (both client and server side) features.

* **Organization Tools** :
   * GitHub Issues/Projects: For Kanban task tracking.
   * Discord: For daily syncs and instant communication.

* **Workflow** : We used a "Feature Branch" strategy on Git, with Pull Requests required for any merge into the main branch.

## 📊 Database Tables

We use a relational structure with SQLite3 to maintain data integrity across our microservices.

* **User-Profile**:
   * **users** : id, name, email, password, species, planet, dimension, avatar, status, two_factor_secret, two_factor, googleId
   * **tokens** : id, username, token, created_at, expires_at, FOREIGN KEY(username)
   * **friend_requests** : user_id, friend_id, PRIMARY KEY (user_id, friend_id), FOREIGN KEY(user_id), FOREIGN KEY(friend_id)
   * **accepted_friends** : user_id, friend_id, status, FOREIGN KEY(user_id), FOREIGN KEY(friend_id), PRIMARY KEY(user_id, friend_id)

* **Game**:
   * **users_stats** : id, games, wins, losses, versus, versus_wins, versus_losses, versusIa, versusIa_wins, versusIa_losses, tournament, tournament_wins, tournament_losses, billiard, billiard_wins, billiard_losses.
   * **match_history** : id, left_team_A, avatar_left_team_A, left_team_B, avatar_left_team_B, right_team_A, avatar_right_team_A, right_team_B, avatar_right_team_B, mode, left_team_score, right_team_score, winnerId, date

## 🧩 Modules Breakdown

The subject contains a MANDATORY part which brings 30 initial points. To pass the evaluation tests, we needed at least 100 points, we get 10 bonuses points which gives us an extra 110/100 points.

There was 2 Modules categories :
* Major (= 10 pts)
* Minor (= 5 pts)

We were enterily free (after completed the MANDATORY part) to choose whatever we wanted.

**Justification** : The number of points visible in the array is higher than our final note and its normal ! We tried to implement more modules to have a reserve in case of errors at the evaluation time.

Here is which modules we chose and how they where divided :

<table data-path-to-node="26">
   <thead>
      <tr>
         <td>
            <span data-path-to-node="26,0,0,0">Module</span>
         </td>
         <td>
            <span data-path-to-node="26,0,1,0">Feature Name</span>
         </td>
         <td>
            <span data-path-to-node="26,0,1,0">Tech Stack</span>
         </td>
         <td>
            <span data-path-to-node="26,0,2,0">Points</span>
         </td>
         <td>
            <span data-path-to-node="26,0,3,0">Team Member(s)</span>
         </td>
      </tr>
   </thead>
   <tbody>
      <tr>
         <td>
            <span data-path-to-node="26,1,0,0"><b data-path-to-node="26,1,0,0" data-index-in-node="0">Web</b></span>
         </td>
         <td>
            <span data-path-to-node="26,1,1,0">Use a framework to build the backend.</span>
         </td>
         <td>
            <span data-path-to-node="26,1,1,0">NodeJS + Fastify</span>
         </td>
         <td>
            <span data-path-to-node="26,1,2,0">10</span>
         </td>
         <td>
            <span data-path-to-node="26,1,3,0">ttaquet & (me)</span>
         </td>
      </tr>
      <tr>
         <td>
            <span data-path-to-node="26,2,0,0"><b data-path-to-node="26,2,0,0" data-index-in-node="0">Web</b></span>
         </td>
         <td>
            <span data-path-to-node="26,2,1,0">Use a framework or a toolkit to build the frontend.</span>
         </td>
         <td>
            <span data-path-to-node="26,1,1,0">TypeScript + React.js</span>
         </td>
         <td>
            <span data-path-to-node="26,2,2,0">10</span>
         </td>
         <td>
            <span data-path-to-node="26,2,3,0">(me)</span>
         </td>
      </tr>
      <tr>
         <td>
            <span data-path-to-node="26,3,0,0"><b data-path-to-node="26,3,0,0" data-index-in-node="0">Web</b></span>
         </td>
         <td>
            <span data-path-to-node="26,3,1,0">Use a database for the backend.</span>
         </td>
         <td>
            <span data-path-to-node="26,1,1,0">SQLite3</span>
         </td>
         <td>
            <span data-path-to-node="26,3,2,0">5</span>
         </td>
         <td>
            <span data-path-to-node="26,3,3,0">ttaquet</span>
         </td>
      </tr>
      <tr>
         <td>
            <span data-path-to-node="26,4,0,0"><b data-path-to-node="26,4,0,0" data-index-in-node="0">User Management</b></span>
         </td>
         <td>
            <span data-path-to-node="26,4,1,0">Std user management, authentication, users across tournaments.</span>
         </td>
         <td>
            <span data-path-to-node="26,1,1,0">TypeScript + React.js</span>
         </td>
         <td>
            <span data-path-to-node="26,4,2,0">10</span>
         </td>
         <td>
            <span data-path-to-node="26,4,3,0">(me)</span>
         </td>
      </tr>
      <tr>
         <td>
            <span data-path-to-node="26,4,0,0"><b data-path-to-node="26,4,0,0" data-index-in-node="0">User Management</b></span>
         </td>
         <td>
            <span data-path-to-node="26,4,1,0">Implementing a remote authentication.</span>
         </td>
         <td>
            <span data-path-to-node="26,1,1,0">TypeScript + React.js + Google Sign In (OAuth 2.0)</span>
         </td>
         <td>
            <span data-path-to-node="26,4,2,0">10</span>
         </td>
         <td>
            <span data-path-to-node="26,4,3,0">(me)</span>
         </td>
      </tr>
      <tr>
         <td>
            <span data-path-to-node="26,4,0,0"><b data-path-to-node="26,4,0,0" data-index-in-node="0">Gameplay & UX</b></span>
         </td>
         <td>
            <span data-path-to-node="26,4,1,0">Multiplayer (more than 2 players in the same game).</span>
         </td>
         <td>
            <span data-path-to-node="26,1,1,0">TypeScript + React.js + WebSocket API</span>
         </td>
         <td>
            <span data-path-to-node="26,4,2,0">10</span>
         </td>
         <td>
            <span data-path-to-node="26,4,3,0">ndavenne, (me)</span>
         </td>
      </tr>
      <tr>
         <td>
            <span data-path-to-node="26,4,0,0"><b data-path-to-node="26,4,0,0" data-index-in-node="0">Gameplay & UX</b></span>
         </td>
         <td>
            <span data-path-to-node="26,4,1,0">Add another game with user history and matchmaking.</span>
         </td>
         <td>
            <span data-path-to-node="26,1,1,0">Godot Engine</span>
         </td>
         <td>
            <span data-path-to-node="26,4,2,0">10</span>
         </td>
         <td>
            <span data-path-to-node="26,4,3,0">bchedru</span>
         </td>
      </tr>
      <tr>
         <td>
            <span data-path-to-node="26,4,0,0"><b data-path-to-node="26,4,0,0" data-index-in-node="0">AI-Algo</b></span>
         </td>
         <td>
            <span data-path-to-node="26,4,1,0">Introduce an AI opponent.</span>
         </td>
         <td>
            <span data-path-to-node="26,1,1,0">TypeScript</span>
         </td>
         <td>
            <span data-path-to-node="26,4,2,0">10</span>
         </td>
         <td>
            <span data-path-to-node="26,4,3,0">nvadenne</span>
         </td>
      </tr>
      <tr>
         <td>
            <span data-path-to-node="26,4,0,0"><b data-path-to-node="26,4,0,0" data-index-in-node="0">AI-Algo</b></span>
         </td>
         <td>
            <span data-path-to-node="26,4,1,0">User and game stats dashboards.</span>
         </td>
         <td>
            <span data-path-to-node="26,1,1,0">TypeScript + React.js</span>
         </td>
         <td>
            <span data-path-to-node="26,4,2,0">5</span>
         </td>
         <td>
            <span data-path-to-node="26,4,3,0">(me)</span>
         </td>
      </tr>
      <tr>
         <td>
            <span data-path-to-node="26,4,0,0"><b data-path-to-node="26,4,0,0" data-index-in-node="0">Cybersecurity</b></span>
         </td>
         <td>
            <span data-path-to-node="26,4,1,0">
               Implement WAF/ModSecurity with a hardened configuration and HashiCorp Vault for secrets management.
            </span>
         </td>
         <td>
            <span data-path-to-node="26,1,1,0">Vault + NodeJS + Fastify</span>
         </td>
         <td>
            <span data-path-to-node="26,4,2,0">10</span>
         </td>
         <td>
            <span data-path-to-node="26,4,3,0">ttaquet</span>
         </td>
      </tr>
      <tr>
         <td>
            <span data-path-to-node="26,4,0,0"><b data-path-to-node="26,4,0,0" data-index-in-node="0">Cybersecurity</b></span>
         </td>
         <td>
            <span data-path-to-node="26,4,1,0">GDPR compliance options with user anonymization, local
               data management, and Account Deletion.
            </span>
         </td>
         <td>
            <span data-path-to-node="26,1,1,0">NodeJS + Fastify + argon2</span>
         </td>
         <td>
            <span data-path-to-node="26,4,2,0">5</span>
         </td>
         <td>
            <span data-path-to-node="26,4,3,0">ttaquet</span>
         </td>
      </tr>
      <tr>
         <td>
            <span data-path-to-node="26,4,0,0"><b data-path-to-node="26,4,0,0" data-index-in-node="0">Cybersecurity</b></span>
         </td>
         <td>
            <span data-path-to-node="26,4,1,0">Implement Two-Factor Authentication (2FA) and JWT.</span>
         </td>
         <td>
            <span data-path-to-node="26,1,1,0">TypeScript + React.js + NodeJS + Fastify + otplib + qrcode</span>
         </td>
         <td>
            <span data-path-to-node="26,4,2,0">10</span>
         </td>
         <td>
            <span data-path-to-node="26,4,3,0">ttaquet & (me)</span>
         </td>
      </tr>
      <tr>
         <td>
            <span data-path-to-node="26,4,0,0"><b data-path-to-node="26,4,0,0" data-index-in-node="0">DevOps</b></span>
         </td>
         <td>
            <span data-path-to-node="26,4,1,0">Infrastructure setup for log management.</span>
         </td>
         <td>
            <span data-path-to-node="26,1,1,0">Docker</span>
         </td>
         <td>
            <span data-path-to-node="26,4,2,0">10</span>
         </td>
         <td>
            <span data-path-to-node="26,4,3,0">ttaquet</span>
         </td>
      </tr>
      <tr>
         <td>
            <span data-path-to-node="26,4,0,0"><b data-path-to-node="26,4,0,0" data-index-in-node="0">DevOps</b></span>
         </td>
         <td>
            <span data-path-to-node="26,4,1,0">Designing the backend as microservices.</span>
         </td>
         <td>
            <span data-path-to-node="26,1,1,0">Docker + NodeJS + Fastify</span>
         </td>
         <td>
            <span data-path-to-node="26,4,2,0">10</span>
         </td>
         <td>
            <span data-path-to-node="26,4,3,0">ttaquet</span>
         </td>
      </tr>
      <tr>
         <td>
            <span data-path-to-node="26,4,0,0"><b data-path-to-node="26,4,0,0" data-index-in-node="0">Graphics</b></span>
         </td>
         <td>
            <span data-path-to-node="26,4,1,0">Use advanced 3D techniques.</span>
         </td>
         <td>
            <span data-path-to-node="26,1,1,0">TypeScript + Babylon.js</span>
         </td>
         <td>
            <span data-path-to-node="26,4,2,0">10</span>
         </td>
         <td>
            <span data-path-to-node="26,4,3,0">agilles</span>
         </td>
      </tr>
      <tr>
         <td>
            <span data-path-to-node="26,4,0,0"><b data-path-to-node="26,4,0,0" data-index-in-node="0">Accessibility</b></span>
         </td>
         <td>
            <span data-path-to-node="26,4,1,0">Support on all devices.</span>
         </td>
         <td>
            <span data-path-to-node="26,1,1,0">TypeScript + React.js</span>
         </td>
         <td>
            <span data-path-to-node="26,4,2,0">5</span>
         </td>
         <td>
            <span data-path-to-node="26,4,3,0">(me)</span>
         </td>
      </tr>
      <tr>
         <td>
            <span data-path-to-node="26,4,0,0"><b data-path-to-node="26,4,0,0" data-index-in-node="0">Accessibility</b></span>
         </td>
         <td>
            <span data-path-to-node="26,4,1,0">Supports multiple languages.</span>
         </td>
         <td>
            <span data-path-to-node="26,1,1,0">TypeScript + React.js</span>
         </td>
         <td>
            <span data-path-to-node="26,4,2,0">5</span>
         </td>
         <td>
            <span data-path-to-node="26,4,3,0">(me)</span>
         </td>
      </tr>
      <tr>
         <td>
            <span data-path-to-node="26,4,0,0"><b data-path-to-node="26,4,0,0" data-index-in-node="0">Server-side Pong</b></span>
         </td>
         <td>
            <span data-path-to-node="26,4,1,0">
               Replace basic Pong with server-side Pong and implement an API.
            </span>
         </td>
         <td>
            <span data-path-to-node="26,1,1,0">TypeScript + React.js</span>
         </td>
         <td>
            <span data-path-to-node="26,4,2,0">5</span>
         </td>
         <td>
            <span data-path-to-node="26,4,3,0">ndavenne & (me)</span>
         </td>
      </tr>
   </tbody>
</table>

**Justification** : We chose this combination to maximize points while ensuring a high-security standard (Vault/WAF) and a visually impressive experience (Babylon.js).

## ✨ Features List

* **Live Pong & Billiards** : Real-time multiplayer gaming using WebSockets for low latency.
* **AI Training** : Play against an AI with a calculated 1-second delay to simulate human reaction time.
* **Google OAuth** : Login securely without creating a new password by using your Google Email.
* **Secure Secrets** : All environment variables and API keys are stored in HashiCorp Vault, never exposed in plain text.
* **Tournament Brackets** : Automatically generated matchups for up to 4 players in 1VS1.

## 📚 Resources & AI Use

### Main References

Those main resources are only my concern as a Frontend Developer for the project :

* [React Documentation & Profiler](https://react.dev/learn/adding-interactivity)

* [Requests HTTP Headers](https://developer.mozilla.org/en-US/docs/Web/HTTP/Reference/Headers)

* [WebSocket API on MDN](https://developer.mozilla.org/en-US/docs/Web/API/WebSockets_API)

* [OAuth 2.0 Explanation](https://developers.google.com/identity/protocols/oauth2)

Asking LLMs such as **Gemini 2.5** & **Claude Sonnet 4.2** about how core concepts works (OAuth, 2FA, AI opponent...)  help us too on this journey.

### Use of AI

As a tight deadline was set because of the blackhole absorptions of my mates, we only had 1 month to choose the topic and implement the entire webapp. In this context, AI was the best solution to learn faster and testing some extra code to better optimized and organized our time.

* **Code Optimization** : Used Gemini to generate a basic AI ball & pads directions code sample and to refactor Babylon.js particle shaders for better performance.

* **Boilerplate** : AI helped generate initial TypeScript interfaces for the database models.

* **Debugging** : Used AI to troubleshoot Nginx & Docker configuration conflicts between the WAF and WebSocket headers.

## 💡 Challenges & Solutions I've faced

* **Challenge**: Implementing Websockets logic accross client and server sides to fluidify the Pong game.

* **Solution**: To ensure a smooth and lag-free experience, we implemented a Server-Side model. Instead of letting the client calculate the game state (which leads to cheating and desync), the Node.js/Fastify backend runs a game loop at 60 FPS. It calculates the physics, ball collisions, and scores, then broadcasts a compressed JSON state to both players via WebSockets. On the client side, I used Linear Interpolation (Lerp) to smooth out the movement of the paddles and the ball, compensating for network latency (ping).
