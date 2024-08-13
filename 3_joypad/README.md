# Joypad

La gestion du joypad avec **GBDK** est relativement simple. La
fonction `joypad()` permet récupérer l'état des différents boutons
(constantes `J_A`, `J_B`, `J_UP` etc sont prédéfinies).

Un delai de 100 ms est ajouté entre chaque appel à `joypad()` ce qui
évite la réception de plusieurs input par *frame*.

<img src="https://github.com/nmeloni/gbdev/blob/main/img/joypad.gif" alt="Joypad" width="300" title="Joypad"/>
