# WINDOWS

Une image Gameboy est constituée de trois plans: un pour les sprites,
un pour le background et enfin un pour la fenêtre. Cette dernière
fonctionne comme l'arrière plan mais se trouve toujours affiché devant
les deux autres plans. Il sert en général à afficher des informations
(points de vie, score etc).

L'image finale est constituée de trois types de sprites:
- les caractères (ici on charge une police minimale incluse dans **GBDK**)
- des tuiles pour la fenêtre
- des tuiles pour l'arrière-plan

Notons que lors du chargement des différentes tuiles il faut calculer
l'adresse de la première tuile en fonction du nombre de tuiles déjà
chargées.

<img src="https://github.com/nmeloni/gbdev/blob/main/img/windowtiles.png" alt="windowtiles" width="300" title="Window tiles in memory"/> <img src="https://github.com/nmeloni/gbdev/blob/main/img/windows.gif" alt="window" width="300" title="Window text animation"/>

On peut remarquer que l'affichage d'un texte de plus de 10 caractères
ne posent aucun problème puisqu'il ne s'agit pas de sprites *mobiles*
mais de tuiles limitées à une grille 8x8.
