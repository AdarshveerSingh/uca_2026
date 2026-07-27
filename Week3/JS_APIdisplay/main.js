const usersDiv = document.getElementById("users");

const worker = new Worker("worker.js");


worker.onmessage = function(event) {

    const data = event.data;

    if (data.error) {
        usersDiv.innerHTML = data.error;
        return;
    }


    if (data.length === 0) {
        usersDiv.innerHTML = "No users found";
        return;
    }


    data.forEach(user => {

        const p = document.createElement("p");

        p.textContent = `${user.name} - ${
            user.active ? "Active" : "Inactive"
        }`;

        usersDiv.appendChild(p);

    });

};


worker.onerror = function(error) {

    usersDiv.innerHTML = "Something went wrong while fetching users";

};