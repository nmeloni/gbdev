# 📋 Avancement du projet – Shooter Game Boy

## 🟢 État du projet
Prototype jouable – Construction du premier niveau

---

## 🎮 Core gameplay

- [x] Boucle de jeu stable (`vsync`, update, draw)
- [x] Lecture des entrées joueur
- [x] Déplacement du vaisseau joueur
- [x] Boost (accélération / décélération)
- [v] Tir joueur de base
- [ ] Pool statique de bullets
- [ ] Déplacement optimisé des bullets ennemies
- [ ] Hitbox précises (indépendantes des sprites)
- [ ] Invincibilité temporaire après hit
- [ ] Feedback visuel de dégâts (clignotement / flash)

---

## 👾 Ennemis

- [ ] Système d’ennemis générique
- [ ] 1 type d’ennemi fonctionnel
- [ ] 2–3 variations d’ennemis
- [ ] Patterns de déplacement
- [ ] Patterns de tirs
- [ ] Comportements combinés (move + shoot décalés)
- [ ] Mini-boss
- [ ] Boss de fin de niveau

---

## 💥 Collisions & règles

- [ ] Collision joueur ↔ ennemis
- [ ] Collision joueur ↔ bullets ennemies
- [ ] Collision bullets joueur ↔ ennemis
- [ ] Gestion des dégâts (PV ennemis)
- [ ] Destruction ennemis + explosion
- [ ] Gestion des vies joueur
- [ ] Gestion des powerup
- [ ] Game Over

---

## 🗺️ Niveau & progression

- [ ] Script de niveau (timeline frame-based)
- [ ] Vagues d’ennemis
- [ ] Temps morts / respirations
- [ ] Fin de niveau claire
- [ ] Transition vers écran de score

---

## 🎨 Graphismes

- [x] Sprites définitifs joueur
- [ ] Sprites ennemis cohérents
- [ ] Animations simples (2–3 frames)
- [ ] Effets visuels (explosions, flash)
- [ ] Lisibilité écran (contraste, tailles)
- [ ] Background défilant

---

## 🔊 Son & musique

- [ ] Tir joueur
- [ ] Tir ennemi
- [ ] Explosion
- [ ] Hit joueur
- [ ] Musique de niveau
- [ ] Musique de boss

---

## ⚙️ Technique & optimisation

- [x] Aucun calcul flottant
- [x] Pas de 16 bits dans la boucle critique
- [ ] Tables pré-calculées (directions, patterns)
- [x] Limites CPU testées (stress test bullets)
- [ ] Nettoyage du code mort
- [ ] Commentaires essentiels

---

## 📦 Finition

- [ ] Écran logo
- [ ] Écran titre
- [ ] README complet (description, contrôles)
- [ ] Screenshots
- [ ] Instructions de build (GBDK)
- [ ] ROM jouable
- [ ] Licence
