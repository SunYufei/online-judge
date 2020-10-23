// if else
const status = 400;

if (status === 200) {
    console.log('OK!');
} else if (status === 400) {
    console.log('Error!');
} else {
    console.log('Unknown status');
}

// if ternary
const status = 200;
// let message = '';

// if (status === 200) {
//     message = 'OK!'
// } else {
//     message = 'Error!';
// }
const message = (status === 200) ? 'OK!' : 'Error!';
console.log(message);

// or
const status = 500;

if (status === 200) {
    console.log('OK!');
} else if (status === 400 || status === 500) {
    console.log('Error!');
} else {
    console.log('Unknown status');
}

// case sensitive
const status = 'error';

if (status.toUpperCase() === 'ERROR') {
    console.log('Something went wrong!');
} else {
    console.log('Looks great!!');
}

// implicit false
const name = '';

if (name) {
    console.log('We have a name!');
} else {
    console.log('No name provided');
}

// switch
const status = 500;

switch (status) {
    case 200:
        console.log('OK!');
        break;
    case 400: // or
    case 500: // or
        console.log('Error!');
        break;
    default: // else
        console.log('Unknown status');
        break;
}