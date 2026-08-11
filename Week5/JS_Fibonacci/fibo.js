function* fibonacci() {
    let a = 0;
    let b = 1;

    while (true) {
        yield a;
        [a, b] = [b, a + b];
    }
}

const fibGen = fibonacci();

console.log(fibGen.next().value);
console.log(fibGen.next().value);
console.log(fibGen.next().value);
console.log(fibGen.next().value);
console.log(fibGen.next().value);
console.log(fibGen.next().value);