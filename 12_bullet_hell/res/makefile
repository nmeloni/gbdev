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

# Règle générique pour la plupart des sprites 8x16
%.c: $(PNG_DIR)/%.png
	@echo "Converting $< to $@"
	$(PNG2ASSET) $< -c $@ -sw 8 -sh 16 -spr8x16 -noflip -keep_palette_order -tiles_only

player_sprite.c: $(PNG_DIR)/player_sprite.png
	$(PNG2ASSET) $< -c $@ -sw 16 -sh 16 -spr8x16 -noflip -keep_palette_order

# regles spécifiques pour les tilesmap
space_bkg_tileset.c: $(PNG_DIR)/space_bkg_tileset.png
	$(PNG2ASSET) $< -c $@ -noflip -map -tiles_only

space_bkg_tilemap.c: $(PNG_DIR)/space_bkg_tilemap.png
	$(PNG2ASSET) $< -c $@ -noflip -map -maps_only -source_tileset $(PNG_DIR)/space_bkg_tileset.png


# Nettoyer les fichiers générés
clean:
	rm -f $(C_FILES) $(H_FILES)

# Forcer la régénération
rebuild: clean all

.PHONY: all clean rebuild
