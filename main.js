const { exec } = require('child_process');

var nb_test = 1
var return_array = [nb_test];
var finished = 0;

var i = 0;

function yolo() {
    finished++;
    if (finished == nb_test)
    {
        console.log(return_array[0]);
    }
}

while (i < nb_test)
{
    var env = { "NB_MALLOC": i.toString()};
    console.log("coucou");
    console.log(i);
    exec("ls", { env }, function (error, stdout, stderr) {
        console.log(stdout);
        return_array[i] = { stdout, error, stderr };
        yolo();
    });
    i++;
}
