-WARNING: Un grand pouvoir implique de grandes responsabilitées

Mise en place:  <br />
1/ git submodule init <br />
2/ git submodule update <br />

-Test:<br />
sh detect_segfault.sh [binary] [arguments] [number of tests] <br />

If there is a segfault, you can check where it is with the second script:

sh valgrinder.sh [Directory of project] [argements] [Num of failed test] 
