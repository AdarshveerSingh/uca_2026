function NewPromise(executorFunction) {
    let state = "pending";
    let value;
    let handlers = [];

    function resolve(val) {
        if (state !== "pending") return;

        state = "fulfilled";
        value = val;

        handlers.forEach(handler => {
            if (handler.onFulfilled) {
                handler.resolve(handler.onFulfilled(value));
            }
        });
    }

    function reject(err) {
        if (state !== "pending") return;

        state = "rejected";
        value = err;

        handlers.forEach(handler => {
            if (handler.onRejected) {
                handler.resolve(handler.onRejected(value));
            } else {
                handler.reject(value);
            }
        });
    }

    this.then = function(onFulfilled) {
        return new NewPromise((resolve, reject) => {
            if (state === "fulfilled") {
                resolve(onFulfilled(value));
            } else if (state === "rejected") {
                reject(value);
            } else {
                handlers.push({
                    onFulfilled,
                    resolve,
                    reject
                });
            }
        });
    };

    this.catch = function(onRejected) {
        return new NewPromise((resolve, reject) => {
            if (state === "rejected") {
                resolve(onRejected(value));
            } else if (state === "fulfilled") {
                resolve(value);
            } else {
                handlers.push({
                    onRejected,
                    resolve,
                    reject
                });
            }
        });
    };

    executorFunction(resolve, reject);
}

new NewPromise(resolve => {
    resolve(5);
})
.then(value => value * 2)
.then(value => value * 5)
.then(value => console.log(value));