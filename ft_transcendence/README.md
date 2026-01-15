# ft_transcendence - Final_Project

## 📝 Overview

**ft_transcendence** is the final project of the 42 common core. The goal is to build a high-end, single-page web application (SPA) that allows users to play Pong and Billiards games in real-time.

This project is a massive integration of diverse skills: **Full-stack development** with a microservices architecture, **Cybersecurity** (WAF, Vault, 2FA), **Game Development** (3D with Babylon.js, AI), and **DevOps** (Docker, Nginx). It provides a complete user experience with tournament system, AI opponent, and advanced statistics.

## 🛠 Technical Stack

* **Frontend** : Vite, HTML5, CSS3, TypeScript, React
* **Backend** : Node.js, Fastify (Microservices architecture)
* **Real-time** : WebSockets
* **3D Graphics** : Babylon.js (Particle rendering techniques)
* **Godot Engine** : Used for the second game (Billiards), exported to WebAssembly (WASM) and WebGL
* **Database** : SQLite3 (Chosen for portability and its "serverless" file-based nature, ideal for containerized microservices)
* **Security** : HashiCorp Vault (Secrets management), Nginx (Reverse Proxy), WAF/ModSecurity
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

<table data-path-to-node="16"><thead><tr><td><span data-path-to-node="16,0,0,0">Member</span></td><td><span data-path-to-node="16,0,1,0">Role</span></td><td><span data-path-to-node="16,0,2,0">Responsibilities</span></td></tr></thead><tbody><tr><td><span data-path-to-node="16,1,0,0"><b data-path-to-node="16,1,0,0" data-index-in-node="0">ttaquet</b></span></td><td><span data-path-to-node="16,1,1,0">Tech Lead / DevOps</span></td><td><span data-path-to-node="16,1,2,0">Microservices, Docker, Vault, WAF.</span></td></tr><tr><td><span data-path-to-node="16,2,0,0"><b data-path-to-node="16,2,0,0" data-index-in-node="0">(me)</b></span></td><td><span data-path-to-node="16,2,1,0">Lead Frontend</span></td><td><span data-path-to-node="16,2,2,0">React architecture, i18n, Accessibility.</span></td></tr><tr><td><span data-path-to-node="16,3,0,0"><b data-path-to-node="16,3,0,0" data-index-in-node="0">bchedru, agilles & nvadenne</b></span></td><td><span data-path-to-node="16,3,1,0">Games Developer</span></td><td><span data-path-to-node="16,3,2,0">Babylon.js, AI Opponent, Pong logic.</span></td></tr><tr><td><span data-path-to-node="16,4,0,0"><b data-path-to-node="16,4,0,0" data-index-in-node="0">[Member 4]</b></span></td><td><span data-path-to-node="16,4,1,0">ttaquet & (me)</span></td><td><span data-path-to-node="16,4,2,0">OAuth, 2FA, Tournament system, SQLite.</span></td></tr></tbody></table>

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

## 🧩 Modules Breakdown (7 Majors + 2 Minors)

The subject contains a MANDATORY part which brings 30 initial points, to pass the evaluation tests, we needed at least 100 points, we get 10 bonuses points which gives us an extra 110/100 points. Here is how modules where divided :

<table data-path-to-node="26">
   <thead>
      <tr>
         <td>
            <span data-path-to-node="26,0,0,0">Module Type</span>
         </td>
         <td>
            <span data-path-to-node="26,0,1,0">Feature Name</span>
         </td>
         <td>
            <span data-path-to-node="26,0,2,0">Points</span>
         </td>
         <td>
            <span data-path-to-node="26,0,3,0">Team Member</span>
         </td>
      </tr>
   </thead>
   <tbody>
      <tr>
         <td>
            <span data-path-to-node="26,1,0,0"><b data-path-to-node="26,1,0,0" data-index-in-node="0">Web</b></span>
         </td>
         <td>
            <span data-path-to-node="26,1,1,0">Major: Framework Frontend (React)</span>
         </td>
         <td>
            <span data-path-to-node="26,1,2,0">10</span>
         </td>
         <td>
            <span data-path-to-node="26,1,3,0">(me)</span>
         </td>
      </tr>
      <tr>
         <td>
            <span data-path-to-node="26,2,0,0"><b data-path-to-node="26,2,0,0" data-index-in-node="0">User Mgmt</b></span>
         </td>
         <td>
            <span data-path-to-node="26,2,1,0">Major: Remote Auth (OAuth 2.0) + 2FA</span>
         </td>
         <td>
            <span data-path-to-node="26,2,2,0">10</span>
         </td>
         <td>
            <span data-path-to-node="26,2,3,0">[Names]</span>
         </td>
      </tr>
      <tr>
         <td>
            <span data-path-to-node="26,3,0,0"><b data-path-to-node="26,3,0,0" data-index-in-node="0">User Mgmt</b></span>
         </td>
         <td>
            <span data-path-to-node="26,3,1,0">Minor: User Profiles &amp; Stats</span>
         </td>
         <td>
            <span data-path-to-node="26,3,2,0">1</span>
         </td>
         <td>
            <span data-path-to-node="26,3,3,0">[Names]</span>
         </td>
      </tr>
      <tr>
         <td>
            <span data-path-to-node="26,4,0,0"><b data-path-to-node="26,4,0,0" data-index-in-node="0">Graphics</b></span>
         </td>
         <td>
            <span data-path-to-node="26,4,1,0">Major: Babylon.js 3D Graphics</span>
         </td>
         <td>
            <span data-path-to-node="26,4,2,0">2</span>
         </td>
         <td>
            <span data-path-to-node="26,4,3,0">[Names]</span>
         </td>
      </tr>
      <tr>
         <td>
            <span data-path-to-node="26,5,0,0"><b data-path-to-node="26,5,0,0" data-index-in-node="0">Game</b></span>
         </td>
         <td>
            <span data-path-to-node="26,5,1,0">Major: Second Game (Billiards)</span>
         </td>
         <td>
            <span data-path-to-node="26,5,2,0">2</span>
         </td>
         <td>
            <span data-path-to-node="26,5,3,0">[Names]</span>
         </td>
      </tr>
      <tr>
         <td>
            <span data-path-to-node="26,6,0,0"><b data-path-to-node="26,6,0,0" data-index-in-node="0">Game</b></span>
         </td>
         <td>
            <span data-path-to-node="26,6,1,0">Minor: Tournament System</span>
         </td>
         <td>
            <span data-path-to-node="26,6,2,0">1</span>
         </td>
         <td>
            <span data-path-to-node="26,6,3,0">[Names]</span>
         </td>
      </tr>
      <tr>
         <td>
            <span data-path-to-node="26,7,0,0"><b data-path-to-node="26,7,0,0" data-index-in-node="0">AI</b></span>
         </td>
         <td>
            <span data-path-to-node="26,7,1,0">Major: AI Opponent</span>
         </td>
         <td>
            <span data-path-to-node="26,7,2,0">2</span>
         </td>
         <td>
            <span data-path-to-node="26,7,3,0">[Names]</span>
         </td>
      </tr>
      <tr>
         <td>
            <span data-path-to-node="26,8,0,0"><b data-path-to-node="26,8,0,0" data-index-in-node="0">Security</b></span>
         </td>
         <td>
            <span data-path-to-node="26,8,1,0">Major: WAF + HashiCorp Vault Secrets</span>
         </td>
         <td>
            <span data-path-to-node="26,8,2,0">2</span>
         </td>
         <td>
            <span data-path-to-node="26,8,3,0">[Names]</span>
         </td>
      </tr>
      <tr>
         <td>
            <span data-path-to-node="26,9,0,0"><b data-path-to-node="26,9,0,0" data-index-in-node="0">Accessibility</b></span>
         </td>
         <td>
            <span data-path-to-node="26,9,1,0">Minor: i18n (3 Languages)</span>
         </td>
         <td>
            <span data-path-to-node="26,9,2,0">1</span>
         </td>
         <td>
            <span data-path-to-node="26,9,3,0">[Names]</span>
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

* [React Documentation & Profiler](https://react.dev/learn/adding-interactivity)

* [WebSocket API on MDN](https://developer.mozilla.org/en-US/docs/Web/API/WebSockets_API)

* [OAuth 2.0 Simplified]()

Asking LLMs such as **Gemini 2.5** & **Claude Sonnet 4.2** about how core concepts works (OAuth, 2FA, AI opponent...)  help us too on this journey.

### Use of AI

As a tight deadline was set because of the blackhole absorptions of my mates (fired if we hadn't successfully validated the project), we only had 1 month to choose a topic and implement the whole app. In this context, AI was the easiest solution to learn faster and implement some extra code as tests to better optimized and organized our time.

* **Code Optimization** : Used Gemini to generate a basic AI ball & pads directions code sample and to refactor Babylon.js particle shaders for better performance.

* **Boilerplate** : AI helped generate initial TypeScript interfaces for the database models.

* **Debugging** : Used AI to troubleshoot Nginx & Docker configuration conflicts between the WAF and WebSocket headers.

## 💡 Challenges & Solutions I've faced

* **Challenge**: Implementing Websockets logic accross client and server sides to fluidify the Pong game.

* **Solution**: To ensure a smooth and lag-free experience, we implemented a Server-Authoritative model. Instead of letting the client calculate the game state (which leads to cheating and desync), the Node.js/Fastify backend runs a game loop at 60 FPS. It calculates the physics, ball collisions, and scores, then broadcasts a compressed JSON state to both players via WebSockets. On the client side, we used Client-Side Prediction and Linear Interpolation (Lerp) to smooth out the movement of the paddles and the ball, compensating for network latency (ping) and preventing "jittery" visuals. This ensures that even with a variable connection, the 3D Babylon.js rendering remains fluid for both users.
