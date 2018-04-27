malioc{ exec } = require('child_process');
const fs = require('fs');

const name_file = 'test_file';

if (process.argv.length < 3)
{
    console.log("no input file");
    return;
}
async function get_file()
{
    console.log(process.argv[1]);
    var file =  fs.readFileSync(process.argv[2])
    console.log(file.indexOf('malloc\0'));
    var index = file.indexOf('malloc\0');
    file[index] = 't';
    // file[index + 4] = 'o';
    // file[index + 5 ] = 'i';

    fs.writeFile(name_file, file);
    // file = file.replace('malloc\0', 'malioc\0');
    console.log(file);
    exec(`chmod +x ${name_file}`, function (error, stdout, stderr)
    {
        console.log(error, stdout, stderr);
    })
}
get_file();
// var nb_test = 1
// var return_array = [nb_test];
// var finished = 0;

// var i = 0;

// function yolo() {
//     finished++;
//     if (finished == nb_test)
//     {
//         console.log(return_array[0]);
//     }
// }

// function

// while (i < nb_test)
// {
//     var env = { "NB_MALLOC": i.toString()};
//     console.log("coucou");
//     console.log(i);
//     exec("ls", { env }, function (error, stdout, stderr) {
//         console.log(stdout);
//         return_array[i] = { stdout, error, stderr };
//         yolo();
//     });
//     i++;
// }
