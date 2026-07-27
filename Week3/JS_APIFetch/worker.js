fetch("https:/dummyapi.com/users")
    .then(response => {

        if (!response.ok) {
            throw new Error("Failed to fetch users");
        }

        return response.json();

    })
    .then(users => {

        if (!users || users.length === 0) {
            throw new Error("No users returned from the API");
        }

        postMessage(users);

    })
    .catch(error => {

        console.error(error.message);
        postMessage([]);

    });