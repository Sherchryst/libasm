gcc -m64 test/test_ft_strcpy.c test/test_ft_strlen.c test/test_ft_strcmp.c test/test_ft_strdup.c test/test_ft_write.c test/test_ft_read.c test/test_ft_atoi_base.c test/ref_atoi_base.c test/test_ft_list_push_front.c test/helper_list.c test/ref_list_push_front.c test/test_ft_list_size.c test/ref_list_size.c test/main.c -L. -lasm -I ./include
./a.out
