function criticalCode() {
    throw "throwing an exception"
}

function logError(theException) {
    console.log(theException)
}

// throwing exceptions
throw 'myException';
throw true;

// try..catch
try {
    criticalCode();
} catch (ex) {
    console.log("Got an error");
    logError(ex);
}

// throw in try..catch
try {
    throw "An exception that is thrown every time";
} catch (ex) {
    console.log("Got an error");
    logError(ex);
}

// try..catch..finally
try {
    criticalCode()
} catch (ex) {
    console.log("Got an error");
    logError(ex);
} finally {
    console.log("Code that always will run");
}