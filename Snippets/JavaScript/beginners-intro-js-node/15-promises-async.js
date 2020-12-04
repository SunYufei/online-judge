function primiseTimeout(ms) {
    return new Promise((resolve, reject) => {
        setTimeout(resolve, ms);
    });
}

async function longRunningOperation() {
    // logic
    return 42;
}

async function run() {
    // logic
    console.log('Start!');
    await primiseTimeout(2000);

    const response = await longRunningOperation();
    console.log(response);

    console.log('Stop!');
}

run();

// start!
// wait(2000)
// 42
// stop!

// promise demo
function promiseTimeout(ms) {
    return new Promise((resolve, reject) => {
        setTimeout(resolve, ms);
    });
}

primiseTimeout(2000)
    .then(() => {
        console.log('Done!');
        return promiseTimeout(1000);
    }).then(() => {
        console.log('Also Done!');
        return Promise.resolve(42);
    }).then(result => {
        console.log(result);
    }).catch(() => {
        console.log('Error!');
    });

// wait(2000)
// Done!
// Also Done!
// 42