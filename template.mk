NAME := libft.a
HEADER_NAME := ft.h
OTHER_USEFUL_FILES := .editorconfig .gitignore

CFLAGS := -Wall -Wextra -Werror

default: all
.PHONY: default

.PHONY: all
all: all_done $(OTHER_USEFUL_FILES)

.PHONY: bonus
bonus: bonus_done $(OTHER_USEFUL_FILES)

.PHONY: clean
clean:
	$Qrm -rf *.o $(OTHER_USEFUL_FILES) $(HEADER_NAME) all_done bonus_done

.PHONY: fclean
fclean: clean
	$Qrm -f $(NAME)

.PHONY: re
re:
	$Q$(MAKE) fclean
	$Q$(MAKE) all

all_done: $(OBJS)
	$Qrm -f bonus_done
	$Q[ "$$(grep -c "^// \\[PREPROCESSOR\\] BONUS PART START\$$" libft.h)" = "1" ] && [ "$$(grep -c "^// \\[PREPROCESSOR\\] BONUS PART END\$$" libft.h)" = "1" ] && sed -e "1,12d;$$(grep -n "^// \\[PREPROCESSOR\\] BONUS PART START\$$" libft.h | cut -d : -f 1),$$(grep -n "^// \\[PREPROCESSOR\\] BONUS PART END\$$" libft.h | cut -d : -f 1)d" libft.h > $(HEADER_NAME) || (echo "FAILED TO PREPROCESS libft.h" && sed 1,12d libft.h > $(HEADER_NAME))
	$Q$(AR) $(ARFLAGS) $(NAME) $^
	$Qtouch $@
bonus_done: $(OBJS_BONUS)
	$Qrm -f all_done
	$Qsed 1,12d libft.h | grep -v "^// \\[PREPROCESSOR\\]" > $(HEADER_NAME)
	$Q$(AR) $(ARFLAGS) $(NAME) $^
	$Qtouch $@

.editorconfig:
	$Qprintf "root = true\n\n[*]\ncharset = utf-8\nend_of_line = lf\nindent_size = 4\nindent_style = tab\ninsert_final_newline = true\ntrim_trailing_whitespace = true\n" > .editorconfig
.gitignore:
	$Qprintf ".*\n*.o\n\nlibft.a\nft.h\n" > .gitignore
