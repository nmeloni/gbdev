# 📋 Avancement du projet – Shooter Game Boy

## 🟢 État du projet
Prototype jouable – Construction du premier niveau

---

## 🎮 Core gameplay

- [ ] Boucle de jeu stable (`vsync`, update, draw)
- [ ] Lecture des entrées joueur
- [ ] Déplacement du vaisseau joueur
- [ ] Boost (accélération / décélération)
- [ ] Tir joueur de base
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

- [ ] Sprites définitifs joueur
- [ ] Sprites ennemis cohérents
- [ ] Animations simples (2–3 frames)
- [ ] Effets visuels (explosions, flash)
- [ ] Lisibilité écran (contraste, tailles)

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

- [ ] Aucun calcul flottant
- [ ] Pas de 16 bits dans la boucle critique
- [ ] Tables pré-calculées (directions, patterns)
- [ ] Limites CPU testées (stress test bullets)
- [ ] Nettoyage du code mort
- [ ] Commentaires essentiels

---

## 📦 Finition

- [ ] README complet (description, contrôles)
- [ ] Screenshots
- [ ] Instructions de build (GBDK)
- [ ] ROM jouable
- [ ] Licence
