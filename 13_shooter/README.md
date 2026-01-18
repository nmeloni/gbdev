# 📋 Avancement du projet – Shooter Game Boy

## 🟢 État du projet
Prototype jouable – Construction du premier niveau

---

## 🎮 Core gameplay

- [x] Boucle de jeu stable (`vsync`, update, draw)
- [x] Lecture des entrées joueur
- [x] Déplacement du vaisseau joueur
- [x] Boost (accélération / décélération)
- [x] Tir joueur de base
- [x] Pool statique de bullets
- [x] Déplacement optimisé des bullets ennemies
- [x] Hitbox précises (indépendantes des sprites)
- [x] Invincibilité temporaire après hit
- [x] Feedback visuel de dégâts (clignotement / flash)

---

## 👾 Ennemis

- [x] Système d’ennemis générique
- [x] 1 type d’ennemi fonctionnel
- [ ] 2–3 variations d’ennemis
- [ ] Patterns de déplacement
- [ ] Patterns de tirs
- [ ] Comportements combinés (move + shoot décalés)
- [ ] Mini-boss
- [ ] Boss de fin de niveau

---

## 💥 Collisions & règles

- [x] Collision joueur ↔ ennemis
- [x] Collision joueur ↔ bullets ennemies
- [x] Collision bullets joueur ↔ ennemis
- [x] Gestion des dégâts (PV ennemis)
- [ ] Destruction ennemis + explosion
- [x] Gestion des vies joueur
- [x] Gestion des powerup
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
- [x] Tables pré-calculées (directions, patterns)
- [x] Limites CPU testées (stress test bullets)
- [ ] Nettoyage du code mort
- [ ] Commentaires essentiels

---

## 📦 Finition

- [ ] README complet (description, contrôles)
- [ ] Screenshots
- [ ] Instructions de build (GBDK)
- [ ] ROM jouable
- [ ] Licence
