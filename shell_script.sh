#/bin/sh
diff=`ls`

trap 'ls -a' 11


yolo=`./segfault_program`
normal='yolo'
if [ yolo -eq normal ]
then
    echo test
fi
#echo $yolo
read -p 'binary to test: ' binary
#echo $binary
#if [ -e malloc ]
#then
#    echo $diff
#fi