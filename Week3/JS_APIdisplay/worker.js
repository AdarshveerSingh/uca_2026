const API_URL = "https://dummyapi.com/users";


async function fetchUsers(){

    try {

        const response = await fetch(API_URL);


        if(!response.ok){
            throw new Error("API request failed");
        }


        const users = await response.json();


        if(!users){
            self.postMessage({
                error: "No users found"
            });

            return;
        }


        self.postMessage(users);


    } catch(error){

        self.postMessage({
            error: error.message
        });

    }

}


fetchUsers();