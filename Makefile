##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

OUT = my_rpg
SRCNAMES =	player_handling/init_player						\
			player_handling/player_health					\
			player_handling/player_movement					\
			player_handling/player_levels					\
			player_handling/create_sprite 					\
			player_handling/player_event					\
			player_handling/free_player						\
			player_handling/move_animation					\
			player_handling/idle_animation					\
			player_handling/player_mana						\
			player_handling/player_money					\
			player_handling/stat_increase					\
			player_handling/update_stats					\
			player_handling/death_animation					\
			entity/init_npc									\
			entity/init_shop								\
			entity/interact									\
			entity/decison_tree								\
			entity/create_sprite							\
			entity/npc_talk									\
			entity/recursion								\
			entity/enemy_attack								\
			entity/enemy_move								\
			entity/init_enemy								\
			entity/enemy_health								\
			entity/enemy_animation							\
			main_menu/main_menu								\
			main_menu/init_menu_struct						\
			main_menu/buttons								\
			main_menu/options/init_opt_menu_struct			\
			main_menu/options/options						\
			main_menu/options/fullscreen					\
			main_menu/options/music							\
			main_menu/options/keybinding/draw_key_select	\
			main_menu/options/keybinding/select_key			\
			main_menu/htp/htp								\
			main_menu/htp/init_htp_menu_struct				\
			pause_menu/pause_menu							\
			pause_menu/init_pause_menu_struct				\
			main_menu/music/music							\
			main_menu/music/set_volume						\
			map/generate_map								\
			map/cleanup_map									\
			map/init_tiles									\
			map/change_room									\
			map/free_map									\
			map/free_tiles									\
			map/create_special_room							\
			map/fill_room									\
			map/draw_tiles									\
			items/init_items								\
			items/get_item_text								\
			items/parse_item_file							\
			items/make_item_array							\
			items/equipment									\
			items/browse_inventory							\
			items/display_inventory							\
			items/display_equipment							\
			items/browse_shop								\
			items/buy_item									\
			items/display_player_stats						\
			items/item_handling								\
			items/level_items								\
			items/write_item_stats							\
			items/free_items								\
			spells/init_spells								\
			spells/make_spell_array							\
			spells/select_spell								\
			spells/player_use_spell							\
			spells/attack_spell								\
			spells/targeting								\
			spells/draw_target								\
			spells/display_spell_selection					\
			spells/spell_description						\
			combat/select_combat_option						\
			combat/display_overlay							\
			combat/combat									\
			combat/attack									\
			combat/end_of_combat							\
			status_condition/status_condition				\
			status_condition/apply_status_player			\
			status_condition/apply_more_status				\
			status_condition/apply_spell_effect				\
			status_condition/spell_effect					\
			status_condition/display_status					\
			draw											\
			time_manipulation								\
			error_handling									\
			m_rpg											\
			create_useful									\
			init_game										\
			count_file										\
			levels											\
			popup											\

TESTSNAMES = test_m_rpg

CSFML =		-l csfml-window -l csfml-graphics -l csfml-system -l csfml-audio
## DON'T TOUCH BELOW THIS LINE ##

SRCMAIN =	$(SRCNAMES)\
		main
TESTEDNAMES =	$(SRCNAMES)

CC = gcc
CPPFLAGS = -Iinclude/
DEBUG = -g3 -ggdb3
LDLIBS = -L lib/my -lmy

SRC = $(addsuffix .c, $(addprefix src/, $(SRCMAIN)))
OBJ = $(SRC:.c=.o)

TESTOUT = test_$(OUT)
TESTLIBS = -lcriterion

TESTS = $(addsuffix .c, $(addprefix tests/, $(TESTSNAMES)))
TESTED = $(addsuffix .c, $(addprefix src/, $(TESTEDNAMES)))

TESTFILES =     *.gcno\
	        *.gcda
TEMPFILES =     *~\
				*\#
VGFILES =       vgcore.*

.PHONY: all compile clean fclean re tests libcreate libclean libfclean

all:	libcreate compile

compile: $(OBJ)
	$(CC) $(CPPFLAGS) $(OBJ) -o $(OUT) $(LDLIBS) $(CSFML)

tests_run: clean libcreate
	$(CC) --coverage -o $(TESTOUT) $(TESTED) $(TESTS)\
	    $(TESTLIBS) $(LDLIBS) $(CPPFLAGS)
	./$(TESTOUT)
	gcovr --exclude tests/
	gcovr --exclude tests/ --branches

libcreate:
	make -C lib/my all

libclean:
	make -C ./lib/my clean

libfclean:
	make -C ./lib/my fclean

clean:	libclean
	$(RM) $(OBJ)
	$(RM) $(TESTFILES)
	$(RM) $(TEMPFILES) src/$(TEMPFILES) lib/my/$(TEMPFILES)
	$(RM) src/map/$(TEMPFILES) src/items/$(TEMPFILES)
	$(RM) src/player_handling/$(TEMPFILES) src/main_menu/$(TEMPFILES)
	$(RM) src/combat/$(TEMPFILES)
	$(RM) $(VGFILES) src/$(VGFILES) lib/my/$(VGFILES)
fclean: libfclean clean
	$(RM) $(OUT)
	$(RM) $(TESTOUT)

re: fclean all
