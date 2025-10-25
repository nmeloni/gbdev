
PNG2ASSET = ${GBDKDIR}/bin/png2asset
# Répertoire des PNG sources
PNG_DIR = png

# Tous les fichiers PNG
PNG_FILES = $(wildcard $(PNG_DIR)/*.png)

# Fichiers C et H générés (dans le répertoire courant res/)
C_FILES = $(patsubst $(PNG_DIR)/%.png,%.c,$(PNG_FILES))
H_FILES = $(patsubst $(PNG_DIR)/%.png,%.h,$(PNG_FILES))

# Cible par défaut : générer tous les fichiers C
all: $(C_FILES)

# Règle générique pour la plupart des sprites 8x8
%.c: $(PNG_DIR)/%.png
	@echo "Converting $< to $@"
	$(PNG2ASSET) $< -c $@ -sw 8 -sh 8 -spr8x8 -noflip

# Règles spécifiques pour certains sprites si nécessaire
# (Décommentez et adaptez selon vos besoins)

# Métasprites 16x16
carti.c: $(PNG_DIR)/carti.png
	$(PNG2ASSET) $< -c $@ -sw 16 -sh 16 -spr8x16 -noflip

box.c: $(PNG_DIR)/box.png
	$(PNG2ASSET) $< -c $@ -sw 16 -sh 16 -spr8x16 -noflip

# Sprites animés (garde les tiles dupliquées pour l'animation)
animatedSpike.c: $(PNG_DIR)/animatedSpike.png
	$(PNG2ASSET) $< -c $@ -sw 8 -sh 8 -spr8x8 -noflip -keep_duplicate_tiles

animatedCD.c: $(PNG_DIR)/animatedCD.png
	$(PNG2ASSET) $< -c $@ -sw 8 -sh 8 -spr8x8 -noflip -keep_duplicate_tiles

# Nettoyer les fichiers générés
clean:
	rm -f $(C_FILES) $(H_FILES)

# Forcer la régénération
rebuild: clean all

# Liste les fichiers qui seront générés
list:
	@echo "PNG files found:"
	@echo $(PNG_FILES)
	@echo ""
	@echo "C files to generate:"
	@echo $(C_FILES)

.PHONY: all clean rebuild list
