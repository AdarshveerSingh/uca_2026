function* calc(initialValue) {
    let result = initialValue;
    let input = yield result;

    while (true) {
        while (
            !input ||
            !["add", "subtract", "multiply", "divide"].includes(input.operation) ||
            typeof input.value !== "number"
        ) {
            input = yield "Invalid input";
        }

        switch (input.operation) {
            case "add":
                result += input.value;
                break;

            case "subtract":
                result -= input.value;
                break;

            case "multiply":
                result *= input.value;
                break;

            case "divide":
                if (input.value === 0) {
                    input = yield "Cannot divide by zero";
                    continue;
                }
                result /= input.value;
                break;
        }

        input = yield result;
    }
}

const calculator = calc(50);

console.log(calculator.next().value);
console.log(calculator.next({operation: "add", value: 30}).value);
console.log(calculator.next({operation: "multiply", value: 2}).value);
console.log(calculator.next({operation: "add", value: "30"}).value);
console.log(calculator.next({operation: "multiply", value: 0}).value);