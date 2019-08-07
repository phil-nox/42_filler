### EXAMPLE RUN
cd resources
./resources/filler_vm -p1 ./resources/players/carli.filler -p2 ./resources/players/abanlin.filler -f ./resources/maps/map00

### STEP 1
make -C./libft && gcc 1_read_map.c test_1_read_map.c -L./libft/build -lft -I./libft -o read.filler
touch test_out test_debug
./resources/filler_vm -p2 ./resources/players/carli.filler -p1 ./read.filler -f ./resources/maps/map00 -t 1

### STEP 2
### test is_place
./test_run.sh