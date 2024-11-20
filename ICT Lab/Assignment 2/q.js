const prompt = require('prompt-sync')(); //for user input

let tasks = []; //array to store tasks

//function to add task
function addTask(){
    const task = prompt("Enter the task description:");
    if(task.trim !== ""){
        tasks.push(task);
        console.log("Task added:" + task);
    }
    else{
        console.log("Task description cannot be empty.");
    }
}

//function to remove task
function removeTask(){
    displayTasks();
    const index = prompt("Enter the task to remove: ")-1;
    if(index < 0 || index >= tasks.length){
        console.log("Invalid task number!");
    } else {
        const removeTask = tasks.splice(index,1);
        console.log("Task removed: " + removeTask);
    }
}

//fuction to display all tasks
function displayTasks(){
    if(tasks.length === 0){
        console.log("No tasks in the list");
    } else {
        console.log("To-do List");
       for (var i=0; i<tasks.length; i++){
        console.log((i+1)+ ":" + tasks[i]);
       }
    }
}

//fuction to remove all tasks
function clearTasks(){
    tasks = [];
    console.log("All tasks have been cleared.");
}

//Main loop to interact with user
while (true){
    console.log("\nEnter a command: add, remove, view, clear, or exit");
    const command = prompt("Command: ").toLowerCase();

    switch(command){
        case "add":
            addTask();
            break;
        case "remove":
            removeTask();
            break;
        case "view":
            displayTasks();
            break;
        case "clear":
            clearTasks();
            break;
        case "exit":
            console.log("Exiting the program...");
            process.exit();
        default:
            console.log("Invalid command!"); 
    }
}